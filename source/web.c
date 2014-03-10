#include "defines.h"
#include "tree.h"
#include "vars.h"
#include "prototypes.h"

#if defined ENABLE_WEBSEARCH || defined ENABLE_METAR || defined ENABLE_TAF || defined ENABLE_WEATHER

static void	init_sockaddr				(struct sockaddr_in *, char *, unsigned short int);
static int 	web_open_socket				(char *host, int port);
static int 	web_write_server 			(int filedes, char *format,...);
static struct chanserv_output *web_read_server		(char *source, char *uh, char *target, int filedes, char *host, struct chanserv_output *output);
static struct chanserv_output *websearch_parse_query	(char *source, char *uh, char *target, char *data, struct chanserv_output *output);
static int 	_websearch_parse			(const void *data, Tree *tree, int element, int level);
static struct chanserv_output *weather_parse_query	(char *source, char *uh, char *target, char *data, struct chanserv_output *output);
static struct chanserv_output *metar_parse_query	(char *source, char *uh, char *target, char *data, struct chanserv_output *output);
static int 	_metar_parse				(const void *data, Tree *tree, int element, int level);
static struct chanserv_output *taf_parse_query		(char *source, char *uh, char *target, char *data, struct chanserv_output *output);

struct chanserv_output *web_post_query(char *trigger, char *source, char *uh, char *target, char *query, int size)
{
    struct chanserv_output *result = NULL;
    char *ptr = NULL;
    char *mem = NULL;
    struct webinfo *wi = NULL;
    
    if(strcasecmp (trigger, WEBSEARCH_webinfo.trigger) == 0)
    {
	wi = (struct webinfo *) &WEBSEARCH_webinfo;
    }
    else if(strcasecmp (trigger, METAR_webinfo.trigger) == 0)
    { 
	wi = (struct webinfo *) &METAR_webinfo;
    }
    else if(strcasecmp (trigger, TAF_webinfo.trigger) == 0)
    { 
	wi = (struct webinfo *) &TAF_webinfo;
    }
    else if(strcasecmp (trigger, WEATHER_webinfo.trigger) == 0)
    {
        wi = (struct webinfo *) &WEATHER_webinfo;
    }
    else
    {
	return result;
    }
    
    size++; // for null

    if((ptr = calloc(size, sizeof(char))) == NULL)
    {
        return chanserv_asprintf(result, "ERR_CANT_MALLOC");
    }
    mem = ptr;

    if(web_open_socket(wi->host, wi->port) != SUCCESS)
    {
	free (mem);
        return chanserv_asprintf(result, "ERR_OPEN_SOCKET");
    }
    snprintf(ptr, size + 1, "%s", query);

    while(*ptr != '\0')
    {
        if(*ptr == ' ')
        {
            *ptr = '+';
        }
        ptr++;
    }

    // TODO - we really should URL encode mem.
    if(web_write_server(wsock, "GET %s%s HTTP/1.0\r\nHost: %s:%d\r\nUser-Agent: Darkbot\r\nAccept: text/plain\r\n\r\n", wi->url, mem, wi->host, wi->port) != SUCCESS)
    {
	free (mem);
        return chanserv_asprintf(result, "ERR_WRITE_SOCKET");
    }

    /* i'm passing the trigger instead of the host to web_read_server 
       because the hostnames could be equal (see METAR & TAF) */
    result = web_read_server(source, uh, target, wsock, wi->trigger, result);

    close(wsock);
    free (mem);

    return result;
}

static void
init_sockaddr (struct sockaddr_in *name, char *host, unsigned short int port)
{
    struct hostent *hostinfo;

    name->sin_family = AF_INET;
    name->sin_port = htons (port);
    hostinfo = gethostbyname (host);

    if (!hostinfo)
    {
	return;
    }
    name->sin_addr = *(struct in_addr *) hostinfo->h_addr;
}

static int
web_open_socket(char *host, int port)
{
    extern void init_sockaddr (struct sockaddr_in *name, char *host, unsigned short int port);
	
    struct sockaddr_in name;
    struct timeval timeout;
    int result = 0;
    int esc = 0;
    fd_set set;

    if((wsock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
	return ERR_CANT_CONNECT;
    }

    if((result = fcntl(wsock, F_SETFL, O_NONBLOCK)) < 0)
    {
        return ERR_CANT_CONNECT;
    }

    init_sockaddr (&name, host, port);
	
    if(connect(wsock, (struct sockaddr *) & name, sizeof(name)) != -1)
    {
        return ERR_CANT_CONNECT;
    }

    if(errno != EINPROGRESS)
    {
        return ERR_CANT_CONNECT;
    }

    while(!esc)
    {
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;

	FD_ZERO(&set);
	FD_SET(wsock, &set);

	switch(select(FD_SETSIZE, (fd_set *) NULL, &set, (fd_set *) NULL, &timeout))
        {
	    case 0:
		return ERR_TIMED_OUT;

	    case -1:
		break;

	    default:
		esc++;

		switch(getsockopt(wsock, SOL_SOCKET, SO_ERROR, &sockerr, &optlen)) 
		{
		    case -1:
			break;

		    case 0:
			switch(sockerr) 
			{
			    case ECONNREFUSED:
				break;
							
			    case EADDRNOTAVAIL:
				break;

			    case ENETUNREACH:
				break;

			    case SUCCESS: 
				if((result = fcntl(wsock, F_SETFL, 0)) < 0)
                                {
                                    return ERR_CANT_CONNECT;
   				}
				return SUCCESS;
			}
		}
	}
    }
    return SUCCESS;
}

static int
web_write_server (int filedes, char *format,...)
{
    int	nbytes = 0;
    va_list arglist;
    char message[STRING_LONG] = {0};
    struct timeval timeout;
    fd_set set;

    va_start(arglist, format);
    vsprintf(message, format, arglist);
    va_end(arglist);

    while(1)
    {
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;
	FD_ZERO(&set);
	FD_SET(filedes, &set);

	switch (select(FD_SETSIZE, (fd_set *) NULL, &set, (fd_set *) NULL, &timeout))
        {
	    case 0:
		close(filedes);
		return ERR_SERVER_BUSY;

	    case -1:
		if (!alarmed)
                {
		    db_sleep(RECHECK);
		}
                else
                {
		    alarmed = 0;
                }
		break;
			
	    default: 
		if((nbytes = write(filedes, message, strlen(message) + 1)) < 0)
                {
		    return ERR_SERVER_BUSY;
                }
		else
                {
		    return SUCCESS;
                }
	}
    }
}

static struct chanserv_output *web_read_server(char *source, char *uh, char *target, int filedes, char *host, struct chanserv_output *output)
{
    int nbytes = 0;
    int esc = 0;
    char packet[STRING_LONG] = { 0 };
    char *mem = NULL;
    char *ptr = NULL;
    struct timeval timeout;
    fd_set set;

    if((mem = calloc(sizeof(packet) + 1, sizeof(char))) == NULL)
        return chanserv_asprintf(output, "ERR_READ_SOCKET");
    alarm(0);

    while(!esc)
    {
	timeout.tv_sec = 10;
	timeout.tv_usec = 0;
	FD_ZERO(&set);
	FD_SET(filedes, &set);

	switch(select(FD_SETSIZE, &set, (fd_set *) NULL, (fd_set *) NULL, &timeout))
        {
	    case 0:
		close(filedes);
		alarm(AIL);
                free (mem);
		return chanserv_asprintf(output, "ERR_SERVER_BUSY");

	    case -1:
		break;
			
	    default:
		alarm(AIL);
		esc = 1;
		break;
	}
    }

    while((nbytes = recv(filedes, packet, sizeof(packet), 0)) > 0)
    {
        strncat(mem, packet, sizeof(packet));

	if((ptr = realloc(mem, strlen(mem) + sizeof(packet) + 1)) == NULL)
        {
            free ( mem );
            return chanserv_asprintf(output, "ERR_CANT_MALLOC");
	}
        else
	    mem = ptr;
	memset(packet, 0, sizeof(packet));
    }

    if(nbytes < 0)
    {
	free ( mem );
        return chanserv_asprintf(output, "ERR_SERVER_BUSY");
    }
    close(filedes);

    if(strcasecmp (host, WEBSEARCH_webinfo.trigger) == 0)
	output = websearch_parse_query(source, uh, target, mem, output);
    else if(strcasecmp (host, METAR_webinfo.trigger) == 0)
	output = metar_parse_query(source, uh, target, mem, output);
    else if(strcasecmp (host, TAF_webinfo.trigger) == 0)
	output = taf_parse_query(source, uh, target, mem, output);
    else if (strcasecmp (host, WEATHER_webinfo.trigger) == 0)
        output = weather_parse_query (source, uh, target, mem, output);

    free(mem);
    
    return output;
}

static struct chanserv_output *weather_parse_query (char *source, char *uh, char *target, char *data, struct chanserv_output *output)
{
	char	*s1 = NULL, *s2 = NULL;
	char	*tmp = NULL, *temp = NULL, *city = NULL;
	char 	*humid = NULL, *dew = NULL;
	char 	*wind = NULL, *pres = NULL, *cond = NULL;
	char	*vis = NULL, *cloud = NULL, *wind2 = NULL;
	char	*sunr = NULL, *suns = NULL;

	char	sub1[] = "<b>";
	char	sub2[] = "<span class=\"nowrap\"><b>";

	
	if ((s1 = strstr (data, "Observed at")) != NULL)
	{
		s2 += 8;
		if ((s2 = strstr (s1, sub1)) != NULL)
		{
			city = strtok (s2, "</b>");
			data = strtok (NULL, "");
		}
	}

	if ((s1 = strstr (data, "Temperature")) != NULL)
	{
		if ((s2 = strstr(s1, sub1)) != NULL)
		{
			s2 += strlen (sub1);

			temp = strtok (s2, "</b>");
			data = strtok (NULL, "");
		}
	}

	if ((s1 = strstr (data, "Humidity")) != NULL)
	{	
		if ((s2 = strstr(s1, sub1)) != NULL)
		{
			s2 += strlen (sub1);
			
			humid = strtok (s2, "</b>");
			data = strtok (NULL, "");
		}		
	}	
 
        if ((s1 = strstr (data, "Dew Point")) != NULL)
 	{
        	 if ((s2 = strstr(s1, sub1)) != NULL)
        	 {
                	s2 += strlen (sub1);

                 	dew = strtok (s2, "</b>");
                 	data = strtok (NULL, "");
		} 
        }

        if ((s1 = strstr (data, "Wind")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        wind = strtok (s2, "</b>");
			data = strtok (NULL, "");
			
			if ((tmp = strstr (data, sub2)) != NULL)
			{
			 	tmp += strlen (sub2);
				wind2 = strtok (tmp, "</b>");
				data = strtok (NULL, "");
			}
		
                }
        }
        
	if ((s1 = strstr (data, "Pressure")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        pres = strtok (s2, "</b>");
           	
			data = strtok (NULL, "");			
                }
        }

        if ((s1 = strstr (data, "Conditions")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        cond = strtok (s2, "</b>");
                        data = strtok (NULL, "");
                }
        }

        if ((s1 = strstr (data, "Visibility")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        vis = strtok (s2, "</b>");
                        data = strtok (NULL, "");
                 }
        }
        
	if ((s1 = strstr (data, "Clouds")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        cloud = strtok (s2, "</b>");
                        data = strtok (NULL, "");
                }
        }
        
	if ((s1 = strstr (data, "Sunrise")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        sunr = strtok (s2, "</b>");
                        data = strtok (NULL, "");
                }
        }
        
	if ((s1 = strstr (data, "Sunset")) != NULL)
        {
                 if ((s2 = strstr(s1, sub1)) != NULL)
                 {
                        s2 += strlen (sub1);

                        suns = strtok (s2, "</b>");
                        data = strtok (NULL, "");
                }
        }

	/* Display stuff to target. */
	output = chanserv_asprintf(output, "%s: Temperature (%s%cF) Humidity (%s) DewPoint (%s%cF) Wind (%s at %smph) Pressure (%s in) Conditions (%s) Visibility (%s miles) Clouds (%sft) Sunrise (%s) Sunset (%s)", 
			city, temp, 176, humid, dew, 176, wind, wind2, pres, cond, vis, cloud, sunr, suns);

	return output;
}

static struct chanserv_output * websearch_parse_query(char *source, char *uh, char *target, char *data, struct chanserv_output *output)
{
  char url[STRING_LONG] = { 0 };
  Tree *result_xml = xmlame_from_string(data);

  if (result_xml)
  {
    tree_foreach(result_xml, 0, _websearch_parse, &url);
    output = chanserv_asprintf(output, "%s%s", rand_reply(source), url);
#ifdef	ENABLE_STATS
    add_stats (source, uh, 1, time (NULL), time (NULL));
#endif
  }
  else
    output = chanserv_asprintf(output, "Sorry, your search did not match any documents.");
  return output;
}

static int _websearch_parse(const void *data, Tree *tree, int element, int level)
{
  char  *url = (char *)data;
  int    result = 0;

  if (tree->elements[element].type == TREE_ELEMENT_TYPE_STRING)
  {
    char *string;

    string = (char *)tree->elements[element].element;
    if ((strlen(url) + strlen(string) + 3) < STRING_LONG)
    {
      if (strncmp(string, "http://", 7) == 0)
      {
        strcat(url, string);
        strcat(url, " ");
        result = 1;
      }
      else if (strncmp(string, "https://", 8) == 0)
      {
        strcat(url, string);
        strcat(url, " ");
        result = 1;
      }
    }
  }
  return result;
}

struct _metar_data
{
  char *temp, *city, *time, *humid, *dew, *wind, *pres, *cond, *vis, *cloud, *wind2, *sunr, *suns;
};

static struct chanserv_output *metar_parse_query(char *source, char *uh, char *target, char *data, struct chanserv_output *output)
{
  struct _metar_data _data;
  Tree *result_xml = xmlame_from_string(data);

  if (result_xml)
  {
    memset(&_data, 0, sizeof(struct _metar_data));
    tree_foreach(result_xml, 0, _metar_parse, &_data);
    output = chanserv_asprintf(output, "%s: Observation time (%s) Temperature (%s%cC) DewPoint (%s%cC) Wind (%s%c at %sknots) Visibility (%s statute miles)", 
	_data.city, _data.time, _data.temp, 176, _data.dew, 176, _data.wind, 176, _data.wind2, _data.vis);
#ifdef	ENABLE_STATS
    add_stats (source, uh, 1, time (NULL), time (NULL));
#endif
    E_FN_DEL(tree_del, (result_xml));
  }
  else
    output = chanserv_asprintf(output, "Sorry, no METAR data available.");
  return output;
}

// TODO - There's more that can be decoded, see -
// http://www.aviationweather.gov/adds/dataserver/metars/MetarFieldDescription.php
// http://www.aviationweather.gov/adds/dataserver/tafs/TafsFieldDescription.php

static int _metar_parse(const void *data, Tree *tree, int element, int level)
{
  struct _metar_data *_data = (struct _metar_data *)data;
  char   temp[PATH_MAX];
  int    result = 0;

  if (tree->elements[element].type == TREE_ELEMENT_TYPE_STRING)
  {
    char *string;

    string = (char *)tree->elements[element].element;
    if (strcmp(string, "<station_id") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->city = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<observation_time") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->time = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<issue_time") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->time = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<temp_c") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->temp = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<dewpoint_c") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->dew = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<wind_dir_degrees") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->wind = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<wind_speed_kt") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->wind2 = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
    else if (strcmp(string, "<visibility_statute_mi") == 0)
    {
      sprintf(temp, "%s", (char *)tree->elements[element + 1].element);
      tree_extend(tree, temp);
      _data->vis = tree->buffers[tree->buffers_size - 1];
      result = 1;
    }
  }

  return result;
}

static struct chanserv_output *taf_parse_query(char *source, char *uh, char *target, char *data, struct chanserv_output *output)
{
  struct _metar_data _data;
  Tree *result_xml = xmlame_from_string(data);

  if (result_xml)
  {
    memset(&_data, 0, sizeof(struct _metar_data));
    tree_foreach(result_xml, 0, _metar_parse, &_data);
    output = chanserv_asprintf(output, "%s: Issue time (%s) Wind (%s%c at %sknots) Visibility (%s statute miles)", 
	_data.city, _data.time, _data.wind, 176, _data.wind2, _data.vis);
#ifdef	ENABLE_STATS
    add_stats (source, uh, 1, time (NULL), time (NULL));
#endif
    E_FN_DEL(tree_del, (result_xml));
  }
  else
    output = chanserv_asprintf(output, "Sorry, no TAF data available.");
  return output;
}

#endif
