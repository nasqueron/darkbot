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
	char exe[STRING_SHORT] = { 0 };
	struct timeval timeout;
	int		i = 0;
	fd_set fdvar;
	struct stat st;
#ifdef SA_NOCLDSTOP
	struct sigaction newact;
#endif

#ifdef	DEBUG
	DebuG = 1;
#endif

	get_s ();
	srand (time (0));
	uptime = time (NULL);

	strncpy (DARKBOT_BIN, argv[0], sizeof (DARKBOT_BIN));
	strncpy (exe, argv[0], sizeof (exe));  /* Coz basename() may modify it's argument. */

#ifdef DATABASEDIR
	strncpy (DAT_DIR, DATABASEDIR, sizeof (DAT_DIR));
#else
	strncpy (DAT_DIR, "dat", sizeof (DAT_DIR));
#endif
#ifdef SOURCEDIR
	/* Check if this is being run from the build directory before being installed. */
	snprintf(temp, sizeof(temp), "%s/dat/setup.ini", SOURCEDIR);
	if (stat(temp, &st) >= 0)
	{
	    snprintf(temp, sizeof(temp), "%s/dat", SOURCEDIR);
	    strncpy(DAT_DIR, temp, sizeof (DAT_DIR));
	}
#endif

	/* Parse the command line arguements, if there are any. */
	if (argv[1] != NULL)
	{
		for (i = 1; i < argc; i++)
		{
			if (argv[i][0] == '-')
			{
				if (argv[i][1] == 'S')
				{
					SeeN = true;
				}
				else if (argv[i][1] == 'D')
				{
					DebuG = 1;
				}
				else if (argv[i][1] == 'I')
				{
					strcpy (DAT_DIR, argv[++i]);
					printf ("DAT_DIR: Using %s.\n", DAT_DIR);
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
	
	if (SeeN)
	{
		printf ("\nSEEN ENABLED.\n");
	}
	if (DebuG == 1)
	{
		printf ("\nDEBUG ENABLED.\n");
	}

	set_paths ();

/* This is the best way to deternmine if sigaction() can be used.  
 * sigaction() is more portable than signal(), so use it if we can. */
#ifdef SA_NOCLDSTOP
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
#else
	signal (SIGALRM, sig_alrm);
	signal (SIGSEGV, sig_segv);
	signal (SIGHUP, sig_hup);
#endif

#ifdef ENABLE_RANDOM
	get_rand_stuff_time ();
#endif

	printf ("\n\n\n");
	printf ("  * * * * * * * * Darkbot (c) 1996 v8 Release Candidate 4 * * * * * * * * *  \n");
	printf ("  *                         The IRC Talking Robot                         *  \n");
	printf ("  *                                                                       *  \n"); 
	printf ("  *           Creator/Author: Jason <jason@superlink.net>                 *  \n");
	printf ("  *             Project Administrator: juice <juice@freezedown.org>          *  \n");
	printf ("  *             Last major code changes: ron <ron@freezedown.org>            *  \n");
	printf ("  *             Last major code changes: onefang <onefang@gmail.com>      *  \n");
	printf ("  *      Please check docs/contributors for a list of collaborators       *  \n");
	printf ("  *                                                                       *  \n");
	printf ("  *        Eventual malfunction,  suggestions or patches use only         *  \n");
	printf ("  *              Support Forum @  http://forum.freezedown.org                *  \n");
	printf ("  *                                                                       *  \n");
	printf ("  * By running this installation  you agree that this program is provided *  \n");
	printf ("  * free for non-commercial use only;  -  Distribution of modified source *  \n");
	printf ("  * code or binaries compiled from modified source code for any  platform *  \n");
	printf ("  * or OS  is expressly forbidden.  -   This program is only available at *  \n");
	printf ("  *                       http://www.freezedown.org                          *  \n");
	printf ("  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  \n");

#ifndef	WIN32
# ifdef ENABLE_VERSION_CHECK
	snprintf (temp, sizeof (temp), "lynx -source http://www.freezedown.org/cgi/laun.cgi?%s &", dbVersion);
	system (temp);
# endif
	db_sleep (2);
	if (SORT)
	{
	    printf ("Sorting database...\n");
	    snprintf (temp, sizeof (temp), "sort %s -o %s\n", URL2, URL2);
	    system (temp);
	}
#endif
	load_helpers ();
#ifdef	ENABLE_STATS
	load_stats ();
#endif
	check_files ();
	raw_now ("SERVERS");
	raw_now ("SETUP");
	raw_now ("PERMBAN");
	alarm (AIL);
	prepare_bot ();
	register_bot ();

	while (1)
	{
		timeout.tv_sec = WSEC;
		timeout.tv_usec = USEC;
		FD_ZERO (&fdvar);
		FD_SET (socketfd, &fdvar);
		switch (select (NFDBITS, &fdvar, (fd_set *) NULL, (fd_set *) NULL, &timeout))
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

void	set_paths	(void)
{
	snprintf (DBTIMERS_PATH, sizeof (DBTIMERS_PATH), "%s/%s", DAT_DIR, DEFAULT_DBTIMERS_PATH);
	snprintf (LOG_DIR, sizeof (LOG_DIR), "%s/%s", DAT_DIR, DEFAULT_LOG_DIR);
	snprintf (RDB_DIR, sizeof (RDB_DIR), "%s/%s", DAT_DIR, DEFAULT_RDB_DIR);
#ifdef	ENABLE_STATS
	snprintf (STATS_FILE, sizeof (STATS_FILE), "%s/%s", DAT_DIR, DEFAULT_STATS_FILE);
#endif
	snprintf (SEEN_FILE, sizeof (SEEN_FILE), "%s/%s", DAT_DIR, DEFAULT_SEEN_FILE);
	snprintf (URL2, sizeof (URL2), "%s/%s", DAT_DIR, DEFAULT_URL2);
	snprintf (BACKUP_DUP, sizeof (BACKUP_DUP), "%s/%s", DAT_DIR, DEFAULT_BACKUP_DUP);
	snprintf (AUTOTOPIC_F, sizeof (AUTOTOPIC_F), "%s/%s", DAT_DIR, DEFAULT_AUTOTOPIC_F);
	snprintf (HELPER_LIST, sizeof (HELPER_LIST), "%s/%s", DAT_DIR, DEFAULT_HELPER_LIST);
	snprintf (QUIZ_FILE, sizeof (QUIZ_FILE), "%s/%s", DAT_DIR, DEFAULT_QUIZ_FILE);
	snprintf (PERFORM, sizeof (PERFORM), "%s/%s", DAT_DIR, DEFAULT_PERFORM);
	snprintf (DEOP, sizeof (DEOP), "%s/%s", DAT_DIR, DEFAULT_DEOP);
	snprintf (RAND_SAY, sizeof (RAND_SAY), "%s/%s", DAT_DIR, DEFAULT_RAND_SAY);
	snprintf (RAND_FILE, sizeof (RAND_FILE), "%s/%s", DAT_DIR, DEFAULT_RAND_FILE);
	snprintf (RANDQ_TEMPFILE, sizeof (RANDQ_TEMPFILE), "%s/%s", DAT_DIR, DEFAULT_RANDQ_TEMPFILE);
	snprintf (RAND_BACKUP_FILE, sizeof (RAND_BACKUP_FILE), "%s/%s", DAT_DIR, DEFAULT_RAND_BACKUP_FILE);
	snprintf (SERVERS, sizeof (SERVERS), "%s/%s", DAT_DIR, DEFAULT_SERVERS);
	snprintf (PERMBAN, sizeof (PERMBAN), "%s/%s", DAT_DIR, DEFAULT_PERMBAN);
	snprintf (SETUP, sizeof (SETUP), "%s/%s", DAT_DIR, DEFAULT_SETUP);
}

