#include "defines.h"
#include "vars.h"
#include "prototypes.h"

void
count_seen (char *source, char *target)
{
	FILE	*fp = 0;
	char	temp		[STRING_LONG] = { 0 };
	size_t	nCount = 0;

	// Complain if we can't open the file.
	if ((fp = fopen (SEEN_FILE, "r")) == NULL)
	{
		L003 (source, SEEN_FILE);
		return;
	}

	while (fgets (temp, STRING_LONG, fp))
	{
		++nCount;
	}

	fclose (fp);
	L004 (target, source, nCount);
}

struct chanserv_output *show_seen (char *nick, char *source, char *target)
{
	struct chanserv_output *result = NULL;
	FILE	*fp = 0;
	char	temp[STRING_LONG] = { 0 }, *intime = NULL, *r_nick = NULL, *uh =
			NULL, *chan = NULL, *ptr = NULL;
	time_t	unixtime = 0;

	if ((nick == NULL) || (strlen(nick) > MAX_NICK_LENGTH))
		return result;

	// Looking for yourself, eh?
	if (strcasecmp (nick, source) == 0)
	{
		L005 (target, source);
		return result;
	}

	if ((ptr = strchr (nick, '?')) != NULL)
		memmove (ptr, ptr + 1, strlen (ptr + 1) + 1);

	if ((fp = fopen (SEEN_FILE, "r")) == NULL)
	{
		L003 (source, SEEN_FILE);
		return result;
	}

	while (fgets (temp, STRING_LONG, fp))
	{
		stripline (temp);
		r_nick = strtok (temp, " ");
		if (strcasecmp (nick, r_nick) == 0)
		{
			uh = strtok (NULL, " ");
			chan = strtok (NULL, " ");

			if ((uh == NULL) || (chan == NULL))
				continue;

			intime = strtok (NULL, " ");

			if (intime == NULL)
				continue;

			unixtime = time (NULL) - atoi (intime);

			if (unixtime > 86400)
				result = chanserv_asprintf(result, "%s, I last saw %s (%s) %d day%s, %02d:%02d ago in %s",
				   source, r_nick, uh, unixtime / 86400, (unixtime / 86400 == 1) ? "" : "s",
				   (unixtime / 3600) % 24, (unixtime / 60) % 60, chan);
			else if (unixtime > 3600)
				result = chanserv_asprintf(result, "%s, I last saw %s (%s) %d hour%s, %d min%s ago in %s",
				   source, r_nick, uh, unixtime / 3600, unixtime / 3600 == 1 ? "" : "s",
				   (unixtime / 60) % 60, (unixtime / 60) % 60 == 1 ? "" : "s", chan);
			else
				result = chanserv_asprintf(result, "PRIVMSG %s :%s, I last saw %s (%s) %d minute%s, %d sec%s ago in %s",
				   source, r_nick, uh, unixtime / 60, unixtime / 60 == 1 ? "" : "s", unixtime % 60,
				   unixtime % 60 == 1 ? "" : "s", chan);
			fclose (fp);
			return result;
		}
	}
	fclose (fp);
	L006 (target, source, nick, SEEN_REPLY);
	return result;
}

long
save_seen (char *nick, char *uh, char *chan)
{
	FILE	*fp = 0; 
	char	temp[STRING_LONG] = { 0 }, *r_nick = NULL, *r_chan = NULL, *r_uh = NULL, *r_time = NULL;
	long	toggle = 0;
	time_t	unixtime = 0;

	printf ("\n*** Writing seen file: %s (%s) [%s]\n", CHAN, SEEN_FILE, date ());

	unlink (TMP_FILE);

	if ((fp = fopen (SEEN_FILE, "r")) == NULL)
	{
		db_log (SEEN_FILE, "%s %s %s %d\n", nick, uh, chan, (time_t) time (NULL));
		return (-1);
	}

	while (fgets (temp, STRING_LONG, fp))
	{
		stripline (temp);
		r_nick = strtok (temp, " ");
		if (strcasecmp (nick, r_nick) == 0)
		{
			toggle = 1;
			db_log (TMP_FILE, "%s %s %s %d\n", nick, uh, chan, (time_t) time (NULL));
		}
		else
		{
			r_uh = strtok (NULL, " ");
			r_chan = strtok (NULL, " ");
			r_time = strtok (NULL, " ");

			if (r_uh == NULL || r_chan == NULL || r_time == NULL)
				continue;

			unixtime = (time_t) time (NULL) - (time_t) atoi (r_time);

			if (unixtime < MAX_LASTSEEN)
				db_log (TMP_FILE, "%s %s %s %s\n", r_nick, r_uh, r_chan, r_time);
		}
	}
	fclose (fp);
	if (toggle == 0)
	{
		db_log (TMP_FILE, "%s %s %s %d\n", nick, uh, chan, (time_t) time (NULL));
	}

	rename (TMP_FILE, SEEN_FILE);

	return toggle;
}
