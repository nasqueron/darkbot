/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#include "defines.h"
#include "vars.h"
#include "prototypes.h"

#ifdef ENABLE_STATS
struct chanserv_output *get_stats (char *target, char *user)
{
	struct chanserv_output *result = NULL;
	struct statslist *c;
	char temp[50] = { 0 };
	char *ptr = NULL;
	long total = 0;
	time_t oldtime = 0;
	time_t added_time = 0;
	time_t last_time = 0;

	c = statshead;

	if (c)
		oldtime = c->added_time;

	while (c)
	{
		if (user == NULL)
		{
			total += c->total;
			if (c->added_time < oldtime)
				oldtime = c->added_time;
		}
		else
		{
			if (strcasecmp (c->nick, user) == 0)
			{
				added_time = c->added_time;
				last_time = c->last_time;
				strncpy (temp, ctime (&added_time), sizeof (temp));
				if ((ptr = strchr (temp, '\n')) != NULL)
					*ptr = '\0';
				result = chanserv_asprintf(result, "%s has asked %ld questions since %s, %s's last question was asked on %s", user, c->total, temp, user, ctime (&last_time));
				return NULL;
			}
		}
		c = c->next;
	}
	if (user)
	{
		result = chanserv_asprintf(result, "I have no data on %s\n", user);
	}
	else
	{
		result = chanserv_asprintf(result, "There have been %ld questions asked by %ld people, since I began recording on %s", total, NUM_USER, ctime (&oldtime));
	}
	return result;
}

void
add_stats (char *nick, char *uh, long total, long added_time, long last_time)
{
	struct statslist *n, *c;

	c = statshead;
	if (strlen (uh) > 399)
		uh[399] = '\0';

	while (c)
	{
		if (strcasecmp (c->nick, nick) == 0)
		{
			strncpy (c->uh, uh, sizeof (c->uh));
			c->total++;
			c->last_time = last_time;
			save_changes ();
			return;
		}
		c = c->next;
	}

	n = malloc (sizeof (struct statslist));
	if (n == NULL)
	{
		db_log ("error.log", "AHHH! No ram left! in add_stats!\n");
		return;
	}
	NUM_USER++;
	memset (n, 0, sizeof (struct statslist));
	if (n != NULL)
	{
		strncpy (n->nick, nick, sizeof (n->nick));
		strncpy (n->uh, uh, sizeof (n->uh));
		strlwr (n->uh);
		n->total = total;
		n->added_time = added_time;
		n->last_time = last_time;
		n->next = statshead;
		statshead = n;
	}
	save_changes ();
}

void
load_stats (void)
{
	FILE *fp;
	char b[STRING_LONG] = { 0 }, *user_host = NULL;
	char *nick = NULL, *w_total = NULL, *w_added_time = NULL, *w_last_time = NULL;
	long last_time = 0, added_time = 0, i = 0, total = 0;

	if ((fp = fopen (STATS_FILE, "r")) == NULL)
	{
		if ((fp = fopen (STATS_FILE, "w")) == NULL)
		{
			printf ("Unable to create %s!\n", STATS_FILE);
			exit (0);
		}
		fclose (fp);
		return;
	}
	while (fgets (b, STRING_LONG, fp))
	{
		if (b == NULL)
			continue;
		stripline (b);
		if (*b == '/')
			continue;
		i++;
		printf (".");
		fflush (stdout);
		nick = strtok (b, " ");
		if (nick == NULL)
			continue;
		user_host = strtok (NULL, " ");
		if (user_host == NULL)
			continue;
		w_total = strtok (NULL, " ");
		if (w_total == NULL)
			continue;
		w_added_time = strtok (NULL, " ");
		if (w_added_time == NULL)
			continue;
		w_last_time = strtok (NULL, "");
		if (w_last_time == NULL)
			continue;
		if (w_total != NULL)
			total = atoi (w_total);
		else
			total = 0;
		if (w_added_time != NULL)
			added_time = atoi (w_added_time);
		else
			added_time = 0;
		if (w_added_time != NULL)
			last_time = atoi (w_last_time);
		else
			last_time = 0;
		if (DebuG == 1)
			printf
				("loading statslist: %s %s total:%ld add:%ld last:%ld\n",
				 nick, user_host, total, added_time, last_time);
		add_stats (nick, user_host, total, added_time, last_time);
	}
	printf ("done(%d), ", (int) i);
	fclose (fp);
	if (DebuG == 1)
		db_sleep (2);
}
#endif
