/* Provide a version vfprintf in terms of _doprnt.
   By Kaveh Ghazi  (ghazi@caip.rutgers.edu)  3/29/98
   Copyright (C) 1998 Free Software Foundation, Inc.
 */

#include "defines.h"

int
rpl_vfprintf (FILE *stream, const char *format, va_list ap)
{
  return _doprnt (format, ap, stream);
}
