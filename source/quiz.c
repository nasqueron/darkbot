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

#ifdef ENABLE_QUIZ
struct chanserv_output *run_quiz_question (char *target)
{
	struct chanserv_output *result = NULL;
	FILE *fp;
	int i = 0;
	int j = 0;
	int k = 0;
	int size = 0;
	static int pos = 0;
	char b[STRING_LONG] = { 0 };
	char *ptr = NULL;

	if (quiz_timer > 0)
		return;					/* timer already running */

	if ((fp = fopen (QUIZ_FILE, "r")) == NULL)
		return;

	while (fgets (b, sizeof (b), fp))
	{
		i++;					/* count questions */
	}

	fseek (fp, 0L, SEEK_SET);
	j = get_random_integer(i);
	size = sizeof (recent_questions) / sizeof (recent_questions[0]);

	if (i < size)
		size = i / 2;

	while (k <= size)
	{
		if (j == recent_questions[k])
		{
			j = get_random_integer(i);
			k = 0;
			continue;
		}
		k++;
	}

	if (pos == size)
		pos = 0;

	recent_questions[pos] = j;
	quiz_line = j;
	pos++;
	i = 0;

	while (fgets (b, sizeof (b), fp))
	{
		if (i == quiz_line)
			break;
		i++;
	}

	if ((ptr = strtok (b, "@")) == NULL)
	{
		fclose (fp);
		return;
	}

	result = chanserv_asprintf(result, ptr);
	strncpy (quiz_target, target, sizeof (quiz_target));
	quiz_answer = 1;			/* switch on timer */

	fclose (fp);
}

void
run_quiz_answer (void)
{
	FILE *fp;
	int i = 0;
	char b[STRING_LONG] = { 0 };
	char *ptr = NULL;

	if ((fp = fopen (QUIZ_FILE, "r")) == NULL)
		return;

	while (fgets (b, sizeof (b), fp))
	{
		if (i == quiz_line)
			break;
		i++;
	}

	if ((ptr = strtok (b, "@")) == NULL)
	{
		fclose (fp);
		return;
	}
	if ((ptr = strtok (NULL, "")) == NULL)
	{
		fclose (fp);
		return;
	}

	S ("PRIVMSG %s :%s\n", quiz_target, ptr);

	fclose (fp);
	return result;
}
#endif
