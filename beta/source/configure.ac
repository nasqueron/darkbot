# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Darkbot],[8rc2],[ron@darkbot.org])
AC_COPYRIGHT([Copyright 2003 Darkbot Development Team])
AC_REVISION($Revision$)
AC_CONFIG_AUX_DIR([auxdir])
AC_CONFIG_LIBOBJ_DIR([../source/compat])
AC_CONFIG_MACRO_DIR([../m4])
AC_CONFIG_SRCDIR([../source/parse.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign 1.9 -Wall -Werror])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Checks for libraries.
AC_CHECK_LIB(crypt, crypt)
LIB_SOCKET_NSL

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_STAT
AC_CHECK_HEADERS([arpa/inet.h errno.h fcntl.h limits.h netdb.h netinet/in.h stddef.h stdlib.h string.h sys/param.h sys/socket.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
# FIXME: change all select()'s to cater to the detected results of this -
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_LSTAT
AC_FUNC_STAT
AC_FUNC_VPRINTF
# FIXME: No idea at the moment what to do about select, socket, and strspn.
AC_CHECK_FUNCS([alarm gethostbyname memmove select socket strchr strrchr strspn])
AC_REPLACE_FUNCS([memset snprintf strcasecmp strstr])

# User enabled stuff.
DB_ENABLE_COMMAND([math],[yes],[DO_MATH_STUFF])

# Create output files.
AC_CONFIG_FILES([Makefile defines.h:../source/defines.h.in])
AC_OUTPUT
