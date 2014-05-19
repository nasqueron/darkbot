#include "defines.h"
#include "vars.h"
#include "prototypes.h"

/**
 * TODO: No function should ever be this long...move to the Command Pattern
 */
void
parse (char *line)
{
	char *s = NULL, *s1 = NULL, *s2 = NULL, *s3 = NULL, *s4 = NULL, *cmd = NULL, *ptr = NULL;
	long TOG = 0, seen_value = 0;

	LastInput = 0;
	if (DebuG == 1)
		printf ("IN: %s", line);
#ifdef	DEBUG2
	db_log ("darkbot_debug.log", "IN: %s", line);
#endif
	stripline (line);
	s = strtok (line, " ");
	if (strcasecmp (s, "PING") == 0)
	{
		s1 = strtok (NULL, " ");
		Snow ("PONG %s\n", s1);
	}
	else if (strcasecmp (s, "ERROR") == 0)
	{
		s1 = strtok (NULL, "");
		if (s1 != NULL)
		{
			if (strstr (s1, "Excess Flood") != NULL)
			{
				prepare_bot ();
				register_bot ();
			}
			else if (strstr (s1, "throttled") != NULL)
			{
				prepare_bot ();
				register_bot ();
			}
			else if (strstr (s1, "oo many c") != NULL)
			{
				prepare_bot ();
				register_bot ();
			}
			else if (strstr (s1, "o more c") != NULL)
			{
				prepare_bot ();
				register_bot ();
			}
			else
			{
				S ("QUIT :Caught ERROR from %s :(\n", BS);
				db_sleep (5);
				prepare_bot ();
				register_bot ();
			}
		}
	}
	else if (strstr (s, "!") == NULL)
	{							/* From Server */
		cmd = strtok (NULL, " ");
		if (strcasecmp (cmd, "004") == 0)
		{						/* Connected! */
			save_changes ();
			s2 = strtok (NULL, " ");	/* Copy the current nick */
			strncpy (Mynick, s2, sizeof (Mynick));
			snprintf (NICK_COMMA, sizeof (NICK_COMMA), "%s,", Mynick);
			snprintf (COLON_NICK, sizeof (COLON_NICK), "%s:", Mynick);
			snprintf (BCOLON_NICK, sizeof (BCOLON_NICK), "%s\2:\2", Mynick);
			s2 = strtok (NULL, " ");	/* Got server name */
		}
		else if (strcasecmp (cmd, "315") == 0)
		{
			if (DISPLAY_SYNC)
			{
			    s2 = strtok (NULL, " ");	/*mynick */
			    strncpy (Mynick, s2, sizeof (Mynick));
			    s2 = strtok (NULL, " ");	/* chan */
			    S ("PRIVMSG %s :Sync with %s completed.\n", s2, s2);
			}
		}
		else if (strcasecmp (cmd, "311") == 0)
		{
			s1 = strtok (NULL, " ");
			s1 = strtok (NULL, " ");
			s1 = strtok (NULL, " ");
			s1 = strtok (NULL, " ");
			strncpy (g_host, s1, sizeof (g_host));
		}
		else if (strcasecmp (cmd, "319") == 0)
		{
			s1 = strtok (NULL, " ");
			s1 = strtok (NULL, " ");
			s2 = strtok (NULL, "");
			if (*s2 == ':')
				s2++;
			strlwr (s2);
			if (strstr (s2, "arez") != NULL)
				TOG = 1;
			if (strstr (s2, "kidd") != NULL)
				TOG = 1;
			if (strstr (s2, "hack") != NULL)
				TOG = 1;
			if (strstr (s2, "sex") != NULL)
				TOG = 1;
			if (strstr (s2, "fuck") != NULL)
				TOG = 1;
			if (strstr (s2, "porn") != NULL)
				TOG = 1;
			if (strstr (s2, "pic") != NULL)
				TOG = 1;
			if (TOG == 1)
			{
				S ("NOTICE @%s :%s is on \2%s\2\n", g_chan, s1, s2);
				return;
			}
		}
		else if (strcasecmp (cmd, "432") == 0 || strcasecmp (cmd, "468") == 0)
		{						/* Invalid nick/user */
			// TODO - Should send this to the user requesting the nick change.
			s2 = strtok (NULL, "");
			printf ("Server reported error %s\n", s2);
		}
		else if ((strcasecmp (cmd, "376") == 0) || (strcasecmp(cmd, "422") == 0))
		{
			/* Set default umodes */
			S ("MODE %s %s\n", Mynick, DEFAULT_UMODE);
			run_perform (); /* Run performs */
			S ("JOIN %s\n", CHAN);
		}
		else if (strcasecmp (cmd, "482") == 0)
		{
#ifdef ENABLE_CHANNEL
			if (BITCH_ABOUT_DEOP)
			{
			    s2 = strtok (NULL, " ");	/* mynick */
			    strncpy (Mynick, s2, sizeof (Mynick));
			    s2 = strtok (NULL, " ");	/* chan */
			    /* We used to run the DEOP.INI here */
			}
#endif
		}
		else if (strcasecmp (cmd, "352") == 0)
		{
			s2 = strtok (NULL, "");
			parse_who (s2);
#ifdef ENABLE_STATUS
		}
		else if (strcasecmp (cmd, "252") == 0)
		{
			s2 = strtok (NULL, "");
			parse_252 (s2);
		}
		else if (strcasecmp (cmd, "404") == 0
				 || strcasecmp (cmd, "475") == 0
				 || strcasecmp (cmd, "474") == 0 || strcasecmp (cmd, "473") == 0)
		{						/* Can't join? */
			s2 = strtok (NULL, " ");
			s2 = strtok (NULL, " ");
			db_sleep (5);
			S ("JOIN %s\n", s2);
		}
		else if (strcasecmp (cmd, "251") == 0)
		{
			s2 = strtok (NULL, "");
			parse_251 (s2);
		}
		else if (strcasecmp (cmd, "255") == 0)
		{
			s2 = strtok (NULL, "");
			parse_255 (s2);
#endif
		}
		else if (strcasecmp (cmd, "433") == 0)
		{
			s2 = strtok (NULL, " ");
			if (*s2 != '*')
			{
// TODO - I dunno about these ones, so log them for now.  Probably should go through process_nick().
#ifdef	DEBUG2
db_log ("darkbot_debug.log", " 433 *: %s -> %s\n", Mynick, s2);
#endif
				strncpy (Mynick, s2, sizeof (Mynick));
				snprintf (NICK_COMMA, sizeof (NICK_COMMA), "%s,", Mynick);
				snprintf (COLON_NICK, sizeof (COLON_NICK), "%s:", Mynick);
				snprintf (BCOLON_NICK, sizeof (BCOLON_NICK), "%s\2:\2", Mynick);
				s3 = strtok (NULL, " ");
			}
			else
			{
#ifdef	DEBUG2
db_log ("darkbot_debug.log", " 433: %s\n", Mynick);
#endif
				Snow ("NICK %s%d\n", Mynick, xtried);
				xtried++;
				if (xtried > 15)
					Snow ("NICK _`^%s%d\n", Mynick, xtried);
				if (xtried > 5)
					Snow ("NICK _%s%d\n", Mynick, xtried);
			}
		}
	}
	else
	{							/* Info from user */
		if (*s == ':')			/* Remove the colon prefix */
			s++;
		cmd = strtok (NULL, " ");	/* Read in command  */
		if (strcasecmp (cmd, "NOTICE") == 0)
		{
#ifdef ENABLE_CHANNEL
			s2 = strtok (NULL, " ");	/* target */
			if ((KICK_ON_CHANNEL_NOTICE) && (*s2 == '#'))
			{
				s3 = strtok (s, "!");
				if (BAN_ON_CHANNEL_NOTICE)
				{
				    if (BAN_BY_HOST)
				    {
					s4 = strtok (NULL, "@");
					s4 = strtok (NULL, "");
					S ("MODE %s +b *!*@%s\n", s2, s4);
				    }
				    else /* ban just by u@h */
					S ("MODE %s +b *%s\n", s2, strtok (NULL, ""));
				}
				S ("KICK %s %s :Punt\n", s2, s3);
			}
#endif
		}
		else if (strcasecmp (cmd, "PRIVMSG") == 0)
		{						/* PRIVMSG  */
			s1 = strtok (NULL, " ");	/* Target */
			s2 = strtok (NULL, "");	/* Rest  */
			if ((LOG_PRIVMSG) && (*s1 != '#') && (*s1 != '&'))
			{
				db_log (privmsg_log, "[%s] %s %s %s\n", date (), s, s1, s2);
			}
			if (*s1 == '#' || *s1 == '&' || *s1 == '+')
				if (do_lastcomm (s, s1, s2) == 1)
					return;
			chanserv (s, s1, s2);	/* Process PRIVMSG commands */
		}
		else if (strcasecmp (cmd, "KILL") == 0)
		{
			s1 = strtok (NULL, " ");	/* Kill nick */
			if (strcasecmp (s1, Mynick) == 0)
			{
				do_quit (s1, 3);	/* delete all users from ram since I'm gone */

				prepare_bot ();
				register_bot ();
			}
		}
		else if (strcasecmp (cmd, "KICK") == 0)
		{
			s1 = strtok (NULL, " ");	/* #chan */
			s2 = strtok (NULL, " ");	/* Who got kicked? */
			if (strcasecmp (s2, Mynick) == 0)
			{					/* Rejoin if I was
								   * kicked */
				do_quit (s1, 2);
				db_sleep (5);
				S ("JOIN %s\n", s1);
				S ("PRIVMSG %s :%s\n", s1, COMPLAIN_REASON);
			}
			else
				delete_user (s2, s1);
		}
		else if (strcasecmp (cmd, "INVITE") == 0)
		{
			s1 = strtok (NULL, " ");	/* Mynick */
			s2 = strtok (NULL, " ");	/* Target */
			if (*s2 == ':')
				s2++;
			if (strcasecmp (s2, CHAN) == 0)
				S ("JOIN %s\n", s2);
		}
		else if (strcasecmp (cmd, "PART") == 0)
		{

                        if ((ptr = strchr (s, '!')) != NULL)
    	                       *ptr++ = '\0';			
			
			// Channel
			s1 = strtok (NULL, " ");
			
			// Make sure the first character in the target operative is not a :.
			
			if (*s1 == ':')
				s1++;

			/*
			 * If we are parting the channel, remove all users in that channel from 
			 * memory. If someone else is parting, only remove them from memory.
			 */
			
			if (strcasecmp (s, Mynick) != 0)
				delete_user (s, s1);
			else			
				do_quit (s1, 2);
	
		}
		else if (strcasecmp (cmd, "QUIT") == 0)
		{
			if ((ptr = strchr (s, '!')) != NULL)
				*ptr++ = '\0';
			do_quit (s, 1);
		}
		else if (strcasecmp (cmd, "MODE") == 0)
		{
			do_modes (s, strtok (NULL, ""));
		}
		else if (strcasecmp (cmd, "NICK") == 0)
		{
			if ((ptr = strchr (s, '!')) != NULL)
				*ptr++ = '\0';
			s1 = strtok (NULL, " ");
			process_nick (s, s1);
		}
		else if (strcasecmp (cmd, "JOIN") == 0)
		{
			JOINs++;
			s1 = strtok (NULL, " ");	/* TARGET */
			if (*s1 == ':')
				s1++;
			if ((ptr = strchr (s, '!')) != NULL)
				*ptr++ = '\0';
			strlwr (ptr);
			if ((SeeN) && (*s1 == '#'))
				seen_value = save_seen (s, ptr, s1);
			if (strcasecmp (s, Mynick) != 0)
			{
				if (check_permban (ptr, s1, s) == 1)
					return;
				add_user (s1, s, ptr, 1);
				
				if ((AUTOHELP_GUESTS) && (strstr(s, "Guest") != NULL))
					S ("PRIVMSG %s :hello %s. need any help?\n", s);

				if (DO_WHOIS)
				{
				    strncpy (g_chan, s1, sizeof (g_chan));
				    S ("WHOIS %s\n", s);
				}

				if (check_access (ptr, s1, 0, s) >= 4)
				{
					S ("MODE %s +o %s\n", s1, s);
				}
				else if (check_access (ptr, s1, 1, s) >= 1)
				{
#ifdef ENABLE_CHANNEL
					if (VOICE_USERS_ON_JOIN)
					    S ("MODE %s +v %s\n", s1, s);
#endif
				}
				else if ((HELP_GREET) && (check_access(ptr, s1, 0, s) >= 1))
				{
					return;		/* don't greet if the guy has
								   * access (and no setinfo) */
				}
				else if ((HELP_GREET) && (strcasecmp(s1, CHAN) == 0))
				{
					if (SeeN)
					{
						if (seen_value == 0)	/* don't show people the
												   * notice every join */
							if (setinfo_lastcomm (s1) == 0)	/* don't do it if you just did it! */
								L102 (s, s1, s, *CMDCHAR);
					}
					else
					{
						if (setinfo_lastcomm (s1) == 0)
							L102 (s, s1, s, *CMDCHAR);
					}
				}
			}
			else
				S ("WHO %s\n", s1);	/* Check who is in the
									   * chan */
		}						/* JOIN */
	}
}

void
parse_who (char *data)
{
	char *chan = NULL, *nick = NULL, *ptr = NULL, *flags = NULL, b[STRING_SHORT] = { 0 };

	nick = strtok (data, " ");	/* botnick */
	strncpy (Mynick, nick, sizeof (Mynick));
	chan = strtok (NULL, " ");
	ptr = strtok (NULL, " ");
	snprintf (b, sizeof (b), "%s@%s", ptr, strtok (NULL, " "));
	nick = strtok (NULL, " ");	/* server */
	nick = strtok (NULL, " ");
	flags = strtok (NULL, " ");
	add_user (chan, nick, b, 1);

	if (strstr (flags, "@") != NULL)
		do_op(nick, chan, 1);
}

#ifdef ENABLE_STATUS
void
parse_252 (char *s)
{
	char *tmp = NULL;
	int numb = 0;

	tmp = strtok (s, " ");
	tmp = strtok (NULL, " ");
	sscanf (tmp, "%d", &numb);
	IRCOPS = numb;
}

void
parse_251 (char *s)
{
	char *tmp = NULL;
	int numb = 0, r = 0, i = 0;

  /*- Read and chuck useless data from line 'b' -*/
	tmp = strtok (s, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	sscanf (tmp, "%d", &r);
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	sscanf (tmp, "%d", &i);
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	sscanf (tmp, "%d", &numb);
	NUM_SERV = numb;
	G_USERS = r + i;
}

void
parse_255 (char *s)
{
	char *tmp = NULL, Stat[1] = { 0 };
	int numb = 0, pre_CLIENTS = 0;

	/* test321 :I have 1313 clients and 1 servers */
	strlwr (s);
	tmp = strtok (s, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	tmp = strtok (NULL, " ");
	numb = atoi (tmp);
	pre_CLIENTS = L_CLIENTS;
	L_CLIENTS = numb;
	if (L_CLIENTS < pre_CLIENTS)
	{
		strncpy (Stat, "-", sizeof (Stat));
		pre_CLIENTS = pre_CLIENTS - L_CLIENTS;
	}
	else
	{
		strncpy (Stat, "+", sizeof (Stat));
		pre_CLIENTS = L_CLIENTS - pre_CLIENTS;
	}
	snprintf (tmp, sizeof (tmp), "%3.2f", (float) (((float) L_CLIENTS / (float) G_USERS) * 100));
/* FIXME: I don't see PLAY defined anywhere, is it left over from something else? */
#if PLAY == 1
#define PBOT "ArchFiend"
	if (pre_CLIENTS == 0 || pre_CLIENTS == L_CLIENTS)
	{
		S ("PRIVMSG %s :!SENDQ %d srvs, %d ops, %d users (%s%% of %d, %ld avg)\n", PBOT, NUM_SERV,
		   IRCOPS, L_CLIENTS, tmp, G_USERS, G_USERS / NUM_SERV);
	}
	else
		S ("PRIVMSG %s :!SENDQ %d srvs, %d ops, %d users [%c%2d] (%s%% of %d, %ld avg)\37\n", PBOT,
		   NUM_SERV, IRCOPS, L_CLIENTS, Stat[0], pre_CLIENTS, tmp, G_USERS, G_USERS / NUM_SERV);
	db_log (".ubcount", "%d\n%d\n0\n0\n", L_CLIENTS, L_CLIENTS);
	rename (".ubcount", "/usr/local/apache/htdocs/usage/userbase/userbase.dat");
	db_log (".glcount", "%d\n%d\n0\n0\n", G_USERS, G_USERS);
	rename (".glcount", "/usr/local/apache/htdocs/usage/global/global.dat");
#else
	if (pre_CLIENTS == 0 || pre_CLIENTS == L_CLIENTS)
	{
		S ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users \37(\37%s%% %5d global \2!\2 %3ld avg\37)\37\1\n", CHAN, NUM_SERV, IRCOPS, L_CLIENTS, tmp, G_USERS, NUM_SERV ? (G_USERS / NUM_SERV) : 0);
	}
	else
		S ("PRIVMSG %s :\1ACTION \37(\37%2d servers\37)\37: %2d opers + \2%4d\2 users [\37%c%2d\37] \37(\37%s%% %5d global \2!\2 %3ld avg\37)\37\1\n", CHAN, NUM_SERV, IRCOPS, L_CLIENTS, Stat[0], pre_CLIENTS, tmp, G_USERS, NUM_SERV ? (G_USERS / NUM_SERV) : 0);
#endif
}
#endif

void
parse_server_msg (fd_set * read_fds)
{
	if (FD_ISSET (socketfd, read_fds))
	{
		if (readln () > 0)
		{
			NUMLINESSEEN++;
			parse (L);
		}
		else
		{
			close (socketfd);
		}
	}
}
