/* timespec -- System time interface

   Copyright (C) 2000, 2002, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#if ! defined TIMESPEC_H
# define TIMESPEC_H


// # if ! HAVE_STRUCT_TIMESPEC  // This is what it should be, but old cygwin versions seem to break this check.
# if defined _STRUCT_TIMESPEC || defined __timespec_defined
#else
/* Some systems don't define this struct, e.g., AIX 4.1, Ultrix 4.3, early cygwin versions.  */
# define _STRUCT_TIMESPEC
# define __timespec_defined	1
#  if !HAVE_STRUCT_TIMESPEC
struct timespec
{
  time_t tv_sec;
  long tv_nsec;
};
#  endif
# endif


# if !HAVE_DECL_NANOSLEEP
/* Don't specify a prototype here.  Some systems (e.g., OSF) declare
   nanosleep with a conflicting one (const-less first parameter).  */
int nanosleep ();
# endif

#endif
