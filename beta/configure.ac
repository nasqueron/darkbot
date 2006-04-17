dnl ---------------------------------
dnl configure.ac file for Darkbot.
dnl Written by ron <ron@darkbot.org>
dnl ---------------------------------

dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Darkbot],[8rc2],[ron@darkbot.org])
AC_COPYRIGHT([Copyright (C) 2004 Darkbot Development Team])
AC_REVISION($Revision$)
AC_CONFIG_SRCDIR([source])
AC_CONFIG_HEADER([source/config.h])
AC_PREFIX_DEFAULT([\${HOME}/darkbot])

AM_INIT_AUTOMAKE([darkbot], [8rc2])
AM_MAINTAINER_MODE

dnl config.h stuff
AH_TOP([#ifndef _DARKBOT_CONFIG_H
#define _DARKBOT_CONFIG_H])
AH_BOTTOM([#endif /* !_DARKBOT_CONFIG_H */])

dnl Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PATH_PROG(RM,rm)
AC_PATH_PROG(CP,cp)


AC_CHECK_TYPE(size_t)
AC_CHECK_TYPE(clock_t)

dnl Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_TIME

AC_CHECK_HEADERS(fcntl.h sys/time.h unistd.h)
AC_CHECK_HEADER([windows.h],AC_DEFINE([WIN32],,[windows.h]))

dnl Checks for libraries.
AC_CHECK_LIB(crypt, main)
AC_CHECK_LIB(user32, main)

AC_CHECK_FUNCS(select socket strspn strstr strtol snprintf)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST

dnl Checks for library functions.
AC_TYPE_SIGNAL
AC_FUNC_VPRINTF

AC_SUBST(CFLAGS)
AC_SUBST(PACKAGE)
AC_SUBST(VERSION)

AC_ARG_ENABLE(math-stuff, 
[  --enable-math-stuff              enable math stuff code], [
  if [ test "$enableval" = "yes" ]; then  
  AC_MSG_RESULT(Enabled math stuff code)
    want_math_stuff="yes"
  else
	AC_MSG_RESULT(Disabled math stuff code)
    want_math_stuff="no"
  fi
], [
  AC_MSG_RESULT(Disabled math stuff code)
  want_math_stuff="no"
]
)

if test "x$want_math_stuff" = "xyes"; then
	AC_DEFINE(DO_MATH_STUFF, 1, [Define to 1 to enable math stuff code])
   AM_CONDITIONAL(DO_MATH_STUFF, true)
else
    AM_CONDITIONAL(DO_MATH_STUFF, false)
fi


AC_CONFIG_FILES([source/Makefile Makefile])
AC_OUTPUT

AC_OUTPUT([
dat/servers.ini
dat/setup.ini
dat/userlist.db
source/defines.h
],[
])


dnl Tell the user to run the Setup utility

echo
echo "You may now run ./Setup for configuration."

