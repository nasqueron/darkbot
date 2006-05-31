#include "defines.h"
#include "vars.h"
#include "prototypes.h"

void
check_files (void)
{
	FILE *fp;
	
	if ((fp = fopen (PERFORM, "r")) == NULL)
	{
		if ((fp = fopen (PERFORM, "w")) == NULL)
		{
			printf ("Can't read/write %s! Exiting ...\n", PERFORM);
			exit (EXIT_FAILURE);
		}
		else
			fclose (fp);
	}
	
	if ((fp = fopen (URL2, "r")) == NULL)
	{ 
		if ((fp = fopen (URL2, "w")) == NULL)
		{
			printf ("Can't read/write %s! Exiting ...\n", URL2);
			exit (EXIT_FAILURE);
		}
		else
			fclose (fp);
	}
	
	fclose(fp);

}


void *check_nick_parameter(struct setup_parameter *parameter, char *ptr)
{
    if (strspn (ptr, LEGAL_NICK_TEXT) != strlen (ptr))
    {
	printf("The nickname %s contains illegal characters.", ptr);
	return NULL;
    }

    strncpy (s_Mynick, ptr, sizeof (s_Mynick));
    snprintf(NICK_COMMA, sizeof (NICK_COMMA), "%s,", s_Mynick);
    snprintf(COLON_NICK, sizeof (COLON_NICK), "%s:", s_Mynick);
    snprintf(BCOLON_NICK, sizeof (BCOLON_NICK), "%s\2:\2", s_Mynick);
    S("NICK %s\n", s_Mynick);

    if(LOG_PRIVMSG)
	snprintf (privmsg_log, sizeof (privmsg_log), "%s%s-privmsg.log", LOG_DIR, s_Mynick);

    return ptr;
}

/**
 * 6/23/00 Dan:
 * - Initialized all variables
 */
void
raw_now (char *type)
{
	FILE *fp = NULL;
	long i = 0, counter = 0;
	char str[STRING_LONG] = { 0 }, *dat = NULL, *ptr = NULL, *tmp1 =
		NULL, *tmp2 = NULL, *tmp3 = NULL;

	if (strcasecmp (type, "PERMBAN") == 0)
		if ((fp = fopen (PERMBAN, "r")) == NULL)
			return;
	if (strcasecmp (type, "DEOP") == 0)
		if ((fp = fopen (DEOP, "r")) == NULL)
			return;
	if (strcasecmp (type, "SERVERS") == 0)
		if ((fp = fopen (SERVERS, "r")) == NULL)
		{
			printf ("%s not found. You must create the file with format:\n", SERVERS);
			printf ("server port ...this list can be as long as you want.\n");
			exit (0);
		}
	if (strcasecmp (type, "SETUP") == 0)
		if ((fp = fopen (SETUP, "r")) == NULL)
		{
			printf ("Unable to locate %s! You must run configure!.\n", SETUP);
			exit (0);
		}
	while (!feof (fp))
	{
		if (strcasecmp (type, "SETUP") == 0)
		{
			SeeN = true;
			while (fgets (str, STRING_LONG, fp))
			{
				stripline (str);
				set_parameter(str);
			}
		}
		else if (strcasecmp (type, "PERMBAN") == 0)
		{
			while (fgets (str, STRING_LONG, fp))
			{
				stripline (str);

				/* Allow comments */

				if (*str == '#')
			        	continue;

				tmp1 = strtok (str, " ");
				if (tmp1 == NULL)
					continue;
				tmp2 = strtok (NULL, " ");
				if (tmp2 == NULL)
					tmp2 = "0";
				tmp3 = strtok (NULL, "");
				if (tmp3 == NULL)
					tmp3 = "Permbanned!";
				strlwr (tmp1);
				counter = atoi (tmp2);
				add_permban (tmp1, counter, tmp3);
			}
		}
		else if (strcasecmp (type, "SERVERS") == 0)
		{
			printf ("Loading %s file ", SERVERS);
			while (fgets (str, STRING_LONG, fp))
			{
				/* Allow comments */

				if (*str == '#')
					continue;

				i++;
				printf (".");
				fflush (stdout);
				stripline (str);
				tmp1 = strtok (str, " ");
				if (tmp1 == NULL)
				{
					printf ("Found error in %s! Aboring! please re-run configure!\n", SERVERS);
					exit (0);
				}
				else
					tmp2 = strtok (NULL, " ");
				if (tmp2 == NULL)
				{
					printf ("%s has no matching port in %s!\n", tmp1, SERVERS);
					exit (0);
				}
				
				tmp3 = strtok (NULL, "");
				add_s25 (tmp1, atoi (tmp2), tmp3);
			}
			printf ("done(%d).\n", (int) i);
		}
		else if (fgets (str, STRING_LONG, fp))
			S ("%s\n", str);
	}
	fclose (fp);
}

void
run_perform (void)
{
	FILE *fp;
	char str	[STRING_LONG] = {0},
	     temp	[STRING_LONG] = {0};
	size_t	len = 0;

	if ((fp = fopen (PERFORM, "r")) == NULL)
		return;

	while (fgets (str, sizeof (str), fp))
	{
		/* Allow comments */

		if (*str == '#') 
			continue;
		
		len = strlen (str);
		memset (data, 0, sizeof (data));

		while (len > 0)
		{
			len--;
			if ((str[len] == '~') && (str[len-1] == 'B'))
			{
				len--;
				snprintf (temp, sizeof (temp), "%s%s", Mynick, data);
			}
			else
			{
				snprintf (temp, sizeof (temp), "%c%s", str[len], data);
			}

			strncpy (data, temp, sizeof (data));
		}

		if (data != NULL)
		{
			S ("%s\n", data);
		}
	}
	fclose (fp);
}
