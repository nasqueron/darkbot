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

#if HAVE_DIRENT_H
# include <dirent.h>
# define NAMLEN(dirent) strlen((dirent)->d_name)
#else
# define dirent direct
# define NAMLEN(dirent) (dirent)->d_namlen
# if HAVE_SYS_NDIR_H
#  include <sys/ndir.h>
# endif
# if HAVE_SYS_DIR_H
#  include <sys/dir.h>
# endif
# if HAVE_NDIR_H
#  include <ndir.h>
# endif
#endif

#if !HAVE_NANOSLEEP
# include "timespec.h"
#endif

/**
 * Removed trailing newline and carriage returns.
 * 6/22/00 Dan
 * Rewrote to be more efficient, reduced from O(2n) to O(n)
 */
void
stripline (char *ptr)
{
	for (; ptr && *ptr; ++ptr)
	{
		if ('\r' == *ptr || '\n' == *ptr)
		{
			*ptr = 0;
			return;
		}
	}
}

void
db_log (const char *filename, const char *format,...)
{
	va_list arglist;
	FILE *fp;

	fp = fopen (filename, "a");
	if (NULL == fp)
	{
		/* I guess there's no sense in trying to log the error :) */
		return;
	}

	va_start (arglist, format);
	vfprintf (fp, format, arglist);
	va_end (arglist);
	fclose (fp);
}

/**
 * Convert a character array to all lowercase.
 * 6/23/00 Dan:
 * - Rewrote to be more compact and a bit more efficient
 */
char *
strlwr (char *buf)
{
	char *ptr = buf;

	for (; ptr && *ptr; ++ptr)
	{
		*ptr = tolower (*ptr);
	}
	return buf;
}

/**
 * Convert a character array to all uppercase.
 * 6/23/00 Dan:
 * - Rewrote to be more compact and a bit more efficient
 */
char *
strupr (char *buf)
{
	char *ptr = buf;

	for (; ptr && *ptr; ++ptr)
	{
		*ptr = toupper (*ptr);
	}
	return buf;
}

/* 
 * Added cast to str[i -1] to prevent warnings on Solaris.
 * -ron
 */

void
trailing_blanks (char *str)
{
	int i = 0;

	if (str == NULL)
		return;
	for (i = strlen (str); i > 0; i--)
	{
		if (isspace ( (int) str[i - 1]))
			str[i - 1] = '\0';
		else
			return;
	}
}


void
save_changes (void)
{
	long i = 0;
	struct helperlist *c;
#ifdef	ENABLE_STATS
	struct statslist *d;

	d = statshead;
#endif
	c = helperhead;
	remove (TMP_FILE);
	while (c != NULL)
	{
		i++;
		db_log (TMP_FILE, "%s %s %d %d %s %s\n",
			 c->chan, c->uh, (int) c->level, (int) c->num_join, c->pass, c->greetz);
		c = c->next;
	}
	rename (TMP_FILE, HELPER_LIST);

#ifdef	ENABLE_STATS
	while (d != NULL)
	{
		i++;
		db_log (TMP_FILE, "%s %s %ld %ld %ld\n",
			 d->nick, d->uh, d->total, d->added_time, d->last_time);
		d = d->next;
	}
	rename (TMP_FILE, STATS_FILE);
#endif
}

char *
date (void)
{
	time_t timer;

	time (&timer);
	strncpy (strbuff, ctime (&timer), sizeof (strbuff));
	stripline (strbuff);
	return strbuff;
}


int
match_wild (const char *pattern, const char *str)
{
	char c = 0;
	const char *s = NULL;

	for (;;)
	{
		switch (c = *pattern++)
		{
			case 0:
				if (!*str)
					return 1;
				return 0;
			case '?':
				++str;
				break;
			case '*':
				if (!*pattern)
					return 1;
				s = str;
				while (*s)
				{
					if (*s == *pattern && match_wild (pattern, s))
						return 1;
					++s;
				}
				break;
			default:
				if (*str++ != c)
					return 0;
				break;
		}						/* switch */
	}
}

char **
tokenize (char *theString, size_t * numTokens)
{
	static char *tokens[STRING_SHORT] = { 0 };

	assert (numTokens != NULL && theString != NULL);
	memset (tokens, 0, STRING_SHORT * sizeof (char *));

	tokens[(*numTokens = 0)] = strtok (theString, " ");
	if (NULL == tokens[0])
	{
		/* 0 tokens */
		return tokens;
	}

	while ((tokens[++(*numTokens)] = strtok (NULL, " ")) != NULL)
	{
		/* NO-OP */ ;
	}
	tokens[*numTokens] = 0;

	return tokens;
}

void
get_s (void)
{
	char temp[50] = { 0 };
	long i = 0;

	i = strlen (rp391);
	while (i > 0)
	{
		i--;
		snprintf (temp, sizeof (temp), "%s%c", dbVersion, rp391[i]);
		strncpy (dbVersion, temp, sizeof (dbVersion));
	}
}

const char *
run_program (const char *input)
{
	FILE *read_fp;

	read_fp = popen (input, "r");
	if (read_fp != NULL)
	{
		int length = 0;

		while ( fgets(f_tmp + length, sizeof(f_tmp - length), read_fp) )
		{
			length = strlen(f_tmp);
			while ((f_tmp[length - 1] == '\n') || (f_tmp[length - 1] == '\r'))
			{
				f_tmp[length - 1] = '\0';
				length--;
			}
		}

		pclose (read_fp);
		if (f_tmp)
		{
			return f_tmp;
		}
		return "No match";
	}
	return NULL;
}

/**
 * 6/22/00 Dan
 * - Removed srand(), should only be done once, in main()
 * - Changed while to for loop
 */
char *
get_rand_nick (const char *chan)
{
	size_t x = 0;
	size_t i = 0;
	const struct userlist *c = userhead;

	/* Iterate through the userlist */
	for (; c != NULL; c = c->next)
	{
		/* Check if this user is on the channel */
		if (strcasecmp (chan, c->chan) == 0)
		{
			if (strcasecmp (Mynick, c->nick) != 0)
			{
				strncpy (f_tmp, c->nick, sizeof (f_tmp));
				i++;
			}
		}
	}

	x = 2 + get_random_integer(i);
	i = 0;						/* reinit! */

	for (c = userhead; c != NULL; c = c->next)
	{
		if (strcasecmp (chan, c->chan) == 0)
		{
			i++;
			if (i == x)
			{
				if (*c->nick == '0')
				{
					return f_tmp;
				}
				if (strcasecmp (Mynick, c->nick) != 0)
				{
					strncpy (f_tmp, c->nick, sizeof (f_tmp));
					return f_tmp;
				}
			}
		}
	}
	return f_tmp;
}

void
check_dbtimers (void)
{
	DIR *dp;
	long i = 0;
	char filename[STRING_SHORT] = { 0 };
	struct dirent *entry;
	struct stat statbuf;
	FILE *fp;
	char b[STRING_LONG] = { 0 }, output[STRING_LONG] =
	{
	0};

	if ((dp = opendir (DBTIMERS_PATH)) == NULL)
	{
		return;
	}
	while ((entry = readdir (dp)) != NULL)
	{
		stat (entry->d_name, &statbuf);
		if (S_ISDIR (statbuf.st_mode) && *entry->d_name == '.')
		{
			continue;			/* it's a dir, ignore it */
		}
		if (S_ISDIR (statbuf.st_mode) && strcasecmp(entry->d_name, "CVS") == 0)
		{
			/* Ignore the CVS directory */
			continue;
		}
		i = time (NULL);
		if (i >= atoi (entry->d_name))
		{
			snprintf (filename, sizeof (filename), "%s/%s", DBTIMERS_PATH, entry->d_name);
			if ((fp = fopen (filename, "r")) == NULL)
			{
				return;
			}
			while (fgets (b, STRING_LONG, fp))
			{
				stripline (b);
				snprintf (output, sizeof (output), "%s\n", b);
				S (output);
			}
			fclose (fp);
			remove (filename);
		}
	}
        // FIXME: if CLOSEDIR_VOID is not defined, check the return value.
	closedir (dp);
}

int
add_ignore_user_ram (char *nick)
{
	struct ignorelist *n, *c;

	c = ignorehead;

    while (c)
	{
		if (strcasecmp (c->nick, nick) == 0)
		{
			return 1;
		}
		c = c->next;
	}
	
    if ( ( n = malloc (sizeof (struct ignorelist))) == NULL )
	{
		db_log ("error.log", "AHHH! No ram left! in add_ignore_user!\n");
		return 0;
	}
	
    memset (n, 0, sizeof (struct ignorelist));

    if (n != NULL)
	{
		strncpy (n->nick, nick, sizeof (n->nick));

		n->next = ignorehead;
		ignorehead = n;
	}
    return 1;
}

int
check_ignore_user_ram (char *nick)
{
	struct ignorelist *c;

	c = ignorehead;

    while (c)
	{
        if (strcasecmp (c->nick, nick) == 0)
		{
			return 1;
		}
		c = c->next;
	}
    return 0;
}

int
delete_ignore_user_ram (char *nick)
{
	struct ignorelist *pNode, *pPrev;

	pNode = ignorehead;
	pPrev = NULL;

	while (pNode)
	{
		if (strcasecmp (pNode->nick, nick) == 0)
		{
			if (pPrev != NULL)
			{
				pPrev->next = pNode->next;
			}
			else
				ignorehead = pNode->next;
			free (pNode);
			pNode = NULL;
			return 1;
		}
		pPrev = pNode;
		pNode = pNode->next;
	}
    return 0;
}

/* Count lines in a given filename. */
size_t			count_lines	(char *filename)
{
	FILE	*fp = NULL;
	
	size_t		lines = 0;
	char	b	[STRING_LONG] = {0};
	
	if((fp = fopen(filename, "r")) == NULL)
	{
		db_log("error.log", "Failed to open %s in count_lines()", 
			filename);
		return (-1);
	}

	while(fgets(b, STRING_LONG, fp))
	{
			/* Ignore comments! */
			if((*b != '/') && (*b != '\n'))
				lines++;
			
			if(*b == '\n')
				continue;
	}

	/* Close the file. */
	fclose(fp);

	return(lines);
}

/* Self explanatory. */
void    reverse  (char   *pString)
{
        size_t  nLength = strlen(pString);
        char    *endptr = pString + nLength - 1;

        for(;pString < endptr; ++pString, --endptr)
        {
                 char c = *pString;
                 *pString = *endptr;
                 *endptr = c;
        }
}
	

/* Count how many times the character nChar exists in szStuff
 * return that number. 
 */

size_t		count_char		(const char *pStuff, const char nChar)
{
	char	szStuff [STRING_LONG] = {0};
	int		nIndex = 0;
	int		nCount = 0;
	
	strcpy(szStuff, pStuff);

	for(nIndex = 0; nIndex <= (size_t) strlen(szStuff); nIndex++)
	{
		if(szStuff[nIndex] == nChar)
			nCount++;
	}

	return(nCount);
}

/* I wrote this for my matrix-RAD.net project, this is translated from the Java.
 *
 * Try to turn all sorts of string things into a boolean.  Only the first character is considered.
 */

// true   1 yes ack  ok   one  positive absolutely affirmative  'ah ha' 'shit yeah' 'why not'
static const char *IS_TRUE =  "t1aopswy";
// false  0 no  nack nope zero negative nah 'no way' 'get real' 'uh uh' 'fuck off' 'bugger off'
static const char *IS_FALSE = "f0bgnuz";
bool isBoolean(char *aBoolean)
{
    bool result = false;

    if ((aBoolean != NULL) && (aBoolean[0] != '\0'))
    {
	char test = aBoolean[0];

	result = (strchr(IS_TRUE, tolower(test)) != NULL);
    }

    return result;
}

void db_sleep(unsigned long seconds)
{
    struct timespec req, rem;

    memset(&req, 0, sizeof(struct timespec));
    req.tv_sec = seconds;
    nanosleep(&req, &rem);
}

/* plural(): This function returns "s", or "" (empty string),
 * depending on the plurality of the number specified by 'i'. 
 * Used for beautification purposes in output that involves 
 * showing a numeric count of objects.
 */

char	*plural 	(size_t i)
{
	/* We only need to return "" if 'i' is equal to 1 or -1. */
	if (i == 1 || i == -1)
		return ("");

	/* Everything else is considered plural. */
	return ("s");
}

/* db_argstostr(): This function takes char **args and fills the buffer
 * pointed to by 'str' with a 'delim' delimited string of each element 
 * in the argument buffer. A pointer to 'str' is returned for value 
 * checking. 
 */

int	db_argstostr(char *str, char **args, size_t startarg, char delim)
{
	int i = 0, j = 0, tc = 0;

	/* Bail out if no args. */
	if ((NULL == args) || (NULL == args[0]))
		return (0);
	
	/* Iterate words. */
	for (i = startarg; args[i]; i++)
	{
		/* Go through the letters and fill str buffer. */
		for (j = 0; args[i][j]; j++)
		{
			str[tc++] = args[i][j];

			if (args[i+1] && !(args[i][j+1]))
				str[tc++] = delim;
		}
	}

	str[tc] = '\0';
	
	return (tc);
}
