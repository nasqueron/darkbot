/* Provide a version vfprintf in terms of _doprnt.
   By Kaveh Ghazi  (ghazi@caip.rutgers.edu)  3/29/98
   Copyright (C) 1998 Free Software Foundation, Inc.
 */

#include "ansidecl.h"
#include <stdarg.h>
#include <stdio.h>
#undef snprintf

int
rpl_snprintf (char *buff, size_t size, const char *fmt, ...)
{
	static char temp[BUFSIZ];	/* a temp (large buffer) */
	int result;
	va_list ap;
	va_start (ap, fmt);
	result = vsprintf (temp, fmt, ap);
	strncpy (buff, temp, size - 1);	/* copy at most n */
 	buff[size - 1] = '\0';		/* ensure \0 at end */
	va_end (ap);
	return result;
}
