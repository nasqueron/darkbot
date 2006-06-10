# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT([Darkbot],[8rc2],[ron@darkbot.org])
AC_COPYRIGHT([Copyright 1996 Darkbot Development Team])
AC_REVISION($Revision$)
AC_CONFIG_AUX_DIR([auxdir])
AC_CONFIG_LIBOBJ_DIR([../source/compat])
AC_CONFIG_MACRO_DIR([../m4])
AC_CONFIG_SRCDIR([../source/parse.c])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign 1.9 -Wall -Werror])

# Checks for programs.
AC_GNU_SOURCE
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_MAKE_SET
AC_PROG_RANLIB

gl_USE_SYSTEM_EXTENSIONS

# Checks for libraries.
AC_CHECK_LIB(crypt, crypt)
LIB_SOCKET_NSL

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_HEADER_STAT
AC_CHECK_HEADERS([arpa/inet.h errno.h fcntl.h limits.h netdb.h netinet/in.h stddef.h stdlib.h string.h sys/param.h sys/socket.h sys/time.h unistd.h])
gl_MINMAX

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME
AC_C_VOLATILE
gl_TIMESPEC

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_FORK
AC_FUNC_MALLOC
AC_FUNC_REALLOC
# FIXME: change all select()'s to cater to the detected results of AC_FUNC_SELECT_ARGTYPES.
# Probably not a lot can be done with the results actually.
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_LSTAT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_STAT
AC_FUNC_VPRINTF
AC_CHECK_FUNCS([alarm gethostbyname memmove select socket strchr strrchr])
AC_REPLACE_FUNCS([crypt memset nanosleep snprintf strcasecmp strcasestr strndup strspn strstr vfprintf vsprintf])

# User enabled stuff.
# testing mode must be done first.
DB_ENABLE_GENERIC([testing],[no],[TESTING],[testing mode - for developers only])

DB_ENABLE_COMMAND([math],[yes],[MATH])
DB_ENABLE_COMMANDS([CTCP],[yes],[CTCP])
DB_ENABLE_COMMANDS([channel],[yes],[CHANNEL])
DB_ENABLE_COMMAND([google],[yes],[GOOGLE])
DB_ENABLE_COMMAND([weather],[yes],[WEATHER])
DB_ENABLE_COMMAND([METAR],[yes],[METAR])
DB_ENABLE_COMMAND([TAF],[yes],[TAF])
DB_ENABLE_COMMAND([quiz],[no],[QUIZ])
DB_ENABLE_COMMAND([randq],[yes],[RANDQ])
DB_ENABLE_GENERIC([status],[no],[STATUS],[display of network status])
DB_ENABLE_GENERIC([stoned],[yes],[STONED_CHECK],[server stoned check])
DB_ENABLE_GENERIC([version],[no],[VERSION_CHECK],[new darkbot version check])
DB_ENABLE_GENERIC([verbose],[yes],[VERBOSE],[verbose startup])
DB_ENABLE_GENERIC([encrypt],[no],[ENCRYPT],[encryption of passwords])
DB_ENABLE_GENERIC([random],[yes],[RANDOM],[random utterences])
DB_ENABLE_VALUE([lang],[1],[LANG],[language])
DB_ENABLE_VALUE([sleep],[3],[SLEEP_LEVEL],[sleep command access level])
DB_ENABLE_VALUE([add],[1],[ADD_LEVEL],[topic adding access level])
DB_ENABLE_VALUE([del],[1],[DEL_LEVEL],[topic deleting access level])
DB_ENABLE_VALUE([random],[2],[RAND_LEVEL],[randomstuff command access level])
DB_ENABLE_VALUE([data],[400],[MAX_DATA_SIZE],[maximum data size])
DB_ENABLE_VALUE([topic],[50],[MAX_TOPIC_SIZE],[maximum topic size])

# If in testing mode, then make sure everything gets compiled.
if test "[${db_cv_enable_testing}]" = yes; then
  AC_LIBOBJ([crypt])
   AC_LIBOBJ([lstat])
   AC_LIBOBJ([malloc])
  AC_LIBOBJ([memset])
  AC_LIBOBJ([nanosleep])
   AC_LIBOBJ([realloc])
  AC_LIBOBJ([snprintf])
   AC_LIBOBJ([stat])
  AC_LIBOBJ([strcasecmp])
  AC_LIBOBJ([strcasestr])
  AC_LIBOBJ([strndup])
  AC_LIBOBJ([strspn])
  AC_LIBOBJ([strstr])
  AC_LIBOBJ([vfprintf])
  AC_LIBOBJ([vsprintf])
fi

# Create output files.
AC_CONFIG_FILES([Makefile defines.h:../source/defines.h.in])
AC_OUTPUT
