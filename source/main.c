#include "defines.h"
#include "vars.h"
#include "prototypes.h"

/**
 * 6/23/00 Dan:
 * - Moved declaration of newact into #ifdef
 */
int
main (int argc, char **argv)
{
	char temp[STRING_SHORT] = { 0 };
	struct timeval timeout;
	int		i = 0;
	fd_set fdvar;

#if (SGI == 1) || (NEED_LIBC5 == 1)
	struct sigaction newact;
#endif
#ifdef	DEBUG
	DebuG = 1;
#endif

	temp[0] = temp[0];			/* hide warning for WIN32 compile */

	get_s ();
	srand (time (0));
	uptime = time (NULL);

	/* Parse the command line arguements, if there are any. */
	if (argv[1] != NULL)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				if (argv[i][1] == 'S')
				{
					SeeN = 1;
				}
				else if (argv[i][1] == 'D')
				{
					DebuG = 1;
				}
				else if (argv[i][1] == 'I')
				{
					strcpy (URL2, argv[++i]);
					printf ("URL2: Using %s.\n", URL2);
				}
				else 
				{
					printf ("\n\n%s HELP:\n\n", dbVersion);
					printf ("%s          (Launches Darkbot to IRC)\n", argv[0]);
					printf ("%s -SEEN    (Enables SEEN [Even if SEEN is undefined])\n", argv[0]);
					printf ("%s -DEBUG   (Launch in debug mode)\n", argv[0]);
					exit (0);
				}
			}
		}
	}
	
	if (SeeN == 1)
	{
		printf ("\nSEEN ENABLED.\n");
	}
	if (DebuG == 1)
	{
		printf ("\nDEBUG ENABLED.\n");
	}


	strncpy (DARKBOT_BIN, argv[0], sizeof (DARKBOT_BIN));
#if (SGI == 1) || (NEED_LIBC5 == 1)
	newact.sa_handler = sig_alrm;
	sigemptyset (&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction (SIGALRM, &newact, NULL);
	newact.sa_handler = sig_segv;
	sigemptyset (&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction (SIGSEGV, &newact, NULL);
	newact.sa_handler = sig_hup;
	sigemptyset (&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction (SIGHUP, &newact, NULL);
#else /* ----------------------- */
	signal (SIGALRM, sig_alrm);
	signal (SIGSEGV, sig_segv);
	signal (SIGHUP, sig_hup);
#endif
#ifndef	WIN32
#ifdef	FORK
	if (fork ())
		exit (0);
#endif
#endif
#ifdef	RANDOM_STUFF
	get_rand_stuff_time ();
#endif

	printf ("\n\n\n");
	printf ("  * * * * * * Darkbot, (c) 2002  ver. 7.0 Release Candidate - 4 * * * * * *  \n");
	printf ("  *                         The IRC Talking Robot                         *  \n");
	printf ("  *                                                                       *  \n"); 
	printf ("  *           Creator/Author:  Hamilton, Jason @ superlink.net            *  \n");
	printf ("  *             Project Administrator: LuizCB @ darkbot.info              *  \n");
	printf ("  *             Last major code changes:  Ron @ darkbot.info              *  \n");
	printf ("  *      Please check docs/contributors for a list of  colaborators       *  \n");
	printf ("  *                                                                       *  \n");
	printf ("  *        Eventual malfunction,  suggestions or patches use only         *  \n");
	printf ("  *              Support Forum @  http://forum.darkbot.info               *  \n");
	printf ("  *                                                                       *  \n");
	printf ("  * By running this installation  you agree that this program is provided *  \n");
	printf ("  * free for non-commercial use only;  -  Distribution of modified source *  \n");
	printf ("  * code or binaries compiled from modified source code for any  platform *  \n");
	printf ("  * or OS  is expressly forbidden.  -   This program is only available at *  \n");
	printf ("  *              http://darkbot.net   http://darkbot.info                 *  \n");
        printf ("  *                        develop@darkbot.info                           *  \n");
	printf ("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");

#ifndef	WIN32
#ifndef DISALLOW_COUNT
	snprintf (temp, sizeof (temp), "lynx -source http://darkbot.net/cgi/laun.cgi?%s &", dbVersion);
	system (temp);
#endif
	sprintf (temp, "echo \"%d\" > %s.pid", getpid (), DARKBOT_BIN);
	system (temp);
#endif
#ifndef	WIN32
	db_sleep (2);
#endif
#ifndef	WIN32
#ifdef	SORT
	printf ("Sorting database...\n");
	snprintf (temp, sizeof (temp), "sort %s -o %s\n", URL2, URL2);
	system (temp);
#endif
#endif
	load_helpers ();
	load_stats ();
	check_files ();
	raw_now ("SERVERS");
	raw_now ("SETUP");
	raw_now ("PERMBAN");
	gs26 ();
#ifndef	WIN32
#endif
	alarm (AIL);
	prepare_bot ();
	register_bot ();

	while (1)
	{
		timeout.tv_sec = WSEC;
		timeout.tv_usec = USEC;
		FD_ZERO (&fdvar);
		FD_SET (socketfd, &fdvar);
		switch (select (NFDBITS, &fdvar, (fd_set *) 0, (fd_set *) 0, &timeout))
		{
			case 0:
				break;
			case -1:
				if (!alarmed)
				{
					db_sleep (RECHECK);
				}
				else
					alarmed = 0;
				break;
			default:
				parse_server_msg (&fdvar);
				break;
		}
	}
} 

