/*
 * Copyright (C) 2002 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


/* @configure_input@ */

#ifdef 	HAVE_CONFIG_H
#include <config.h>
#endif


/* defines.h
 *	The Internet Relay Chat Talking Robot
 * 
 ***	Darkbot Creator       : Jason Hamilton (play) Jason@superlink.net
 *	Project Administrator : LuizCB (lcb) LuizCB@dusers.sourceforge.net
 *      Lead Developer        : David Seikel (onefang) onefang@users.sourceforge.net
 *
 *	Official Site: http://darkbot.sourceforge.net 
 *	 		http://darkbot.sourceforge.net
 * 
 ***	For any questions, suggestions, malfunctions, etc
 *	Use our support area at http://darkbot.sourceforge.net
 *
 * 	*******************************---******************************* */
/*
 ***	NOTES - READ before you start:
 *** 	Lines beginning by # (hash) are peprocessor directives, they are not
 * 	comments. You should NOT remove them.
 *** 	#defines should only be changed to ON, OFF, #define, #undef
 * 	or it's value defined on the very right end.
 *** 	Areas between " " are messages Darkbot will send. Do not remove " ".
 *** 	Double slash characters on de beginning of a line or slaches followed
 *	or preceded by * on the beginning and end of lines envolving some
 *	portion of text are comment characters combinations with help
 *	information for the delelopers or users. They do not have any effect
 *	in the behavior of the program.
 *
 	,-----------------------------------------------------------------,
	|   Note that the defines bellow are the RECOMMENDED settings!    |
	| Modify it by changing it's values of the data. This file will   |
	| instruct the compiler to build the executable file. If you're   |
	|  not sure of what to do, leave the default settings alone :)    |
	`-----------------------------------------------------------------' */

#define ON			1
#define OFF			0


/* ================ SYSTEM REQUIREMENTS ================ */

/* 
 * Change the Ansi C signal handling below if it's not in the standard place,
 * usually on include/. Leave it as is if you don't know what that is. Type 
 * 'man signal' on your unix box for more info.
 * (default = <signal.h>)
 */
//#include <signal.h>

/*
 * Most BSD systems will not need this. If your bot will
 * connect but don't react at all try turning this ON.
 * (default = OFF)
 */

//#define NEED_LIBC5 OFF

/*
 * SGI boxes (ie; IRIX system) need this
 * define to run. (default = OFF)
 */
//#define	SGI OFF


/*
 * If you change anything on the next 5 directives be careful not to
 * remove or change the position of '%s' nor anything outside quotes.
 */
#define	L100(s,a,b,c,d,e,f) S("NOTICE %s :I can be triggered by various \
forms of speech, all which must be addressed to me, in one of the \
following formats:  %s %s %s or even %s .... In my database, you can \
find a topic by saying my nick, <topic> .  eg; \37%s nuke\37  ..... \
to do a search on a word, or partial text, just type:  <mynick>, search \
<text>   ... eg; \37%s search nuke\37\n",s,a,b,c,d,e,f)

#define	L101(a,b,c,d) S("NOTICE %s :I can also be triggered with even more \
human formats: \37%s who is bill gates?\37  .. You can also phrase it \
in a question: \37%s where is msie?\37 ...For more info \
about me, visit http://darkbot.sourceforge.net\n",a,b,c,d)

#define	L102(a,b,c,d) S("NOTICE %s :Welcome to %s, %s. Before \
asking your question, type %cHELP for a list of help topics.\n", a,b,c,d)

/* *******************************---******************************* */
/* --------------- Don't change anything else below! --------------- */
/* ***************************************************************** */


//#include <sys/cdefs.h>
//#include <sys/param.h>
//#include <pwd.h>


/* Here we sort out what to do based on some autoconf detected things. */
#if defined _WIN32 || defined __CYGWIN__ || defined __CYGWIN32__ || defined __MINGW32__
# ifndef WIN32
#  define WIN32
# endif
#endif

#define _GNU_SOURCE 1

#if HAVE_ANSIDECL_H
#include <ansidecl.h>
#endif
#include <ctype.h>
#include <limits.h>
#include <stddef.h>

#if HAVE_ERRNO_H
# include <errno.h>
#endif
#ifndef errno
extern int errno;
#endif

#if HAVE_NETDB_H
# include <netdb.h>
#endif
#if HAVE_NETINET_IN_H
# include <netinet/in.h>
#endif
#if HAVE_ARPA_INET_H
# include <arpa/inet.h>
#endif
#include <assert.h>
#if HAVE_FCNTL_H
# include <fcntl.h>
#endif
#ifdef WIN32
# include <windows.h>
#endif

#include <signal.h>
#include <sys/stat.h>

#include <stdio.h>  /* The only one we can guarantee. */

#if HAVE_STDBOOL_H
# include <stdbool.h>
#else
# if ! HAVE__BOOL
#  ifdef __cplusplus
typedef bool _Bool;
#  else
typedef unsigned char _Bool;
#  endif
# endif
# define bool _Bool
# define false 0
# define true 1
# define __bool_true_false_are_defined 1
#endif

#if STDC_HEADERS
# include <string.h>
# include <stdarg.h>
# include <stdlib.h>
#else
# if !HAVE_STRCHR
#  define strchr index
#  define strrchr rindex
# endif
char *strchr (), *strrchr ();
# if !HAVE_MEMMOVE
#  define memcpy(d, s, n) bcopy ((s), (d), (n))
#  define memmove(d, s, n) bcopy ((s), (d), (n))
# endif
#endif

#if HAVE_SYS_SOCKET_H
# include <sys/socket.h>
#endif

#if HAVE_UNISTD_H
#include <sys/types.h>
#include <unistd.h>
#endif

#if TIME_WITH_SYS_TIME
# include <sys/time.h>
# include <time.h>
#else
# if HAVE_SYS_TIME_H
#  include <sys/time.h>
# else
#  include <time.h>
# endif
#endif

/* MacOS X is happier with this one AFTER timeval is declared. */
#include <sys/resource.h>

#include "stat-macros.h"
#include "minmax.h"

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1
#endif

#if !LSTAT_FOLLOWS_SLASHED_SYMLINK
extern int rpl_lstat (const char *name, struct stat *buf);
# undef lstat
# define lstat rpl_lstat
#endif

#if !HAVE_MEMSET
# define memset rpl_memset
#endif

#if !HAVE_NANOSLEEP
# define nanosleep rpl_nanosleep
#endif

#if !HAVE_SNPRINTF
# define snprintf rpl_snprintf
#endif

#if !HAVE_STRCASECMP
# define strcasecmp rpl_strcasecmp
#endif

#if !HAVE_STRCASESTR
# define strcasestr rpl_strcasestr
#endif

#if !HAVE_STRNDUP
extern char *rpl_strndup (const char *dupMe, size_t maxBytes);
# undef strndup
# define strndup rpl_strndup
#endif

#if !HAVE_STRSPN
# define strspn rpl_strspn
#endif

#if !HAVE_STRSTR
# define strstr rpl_strstr
#endif

#if !HAVE_VPRINTF
# define vsprintf rpl_vsprintf
# define vfprintf rpl_vfprintf
#endif

#if !HAVE_LIBCRYPT
# if !HAVE_CRYPT
#  define crypt rpl_crypt
# endif
#endif


/* -------------------------------------------------- */


#define	FR			3	/* these two are the # of lines per secs */
#define	FT			3
#define	AIL			1
#define	WSEC 			10
#define	USEC 			0
#define	RECHECK 		45
#define DEFAULT_DBTIMERS_PATH	"timers"
#define	DEFAULT_LOG_DIR		"logs/"
#define	DEFAULT_RDB_DIR		"rdb"
#ifdef	ENABLE_STATS
#define DEFAULT_STATS_FILE	"stats.db"
#endif
#define	DEFAULT_SEEN_FILE	"seen.db"
#define	DEFAULT_URL2		"info2.db"
#define DUNNO_FILE		"dunno"
#define WHUT_FILE		"whut"
#define	DEFAULT_BACKUP_DUP	"backup_dups.db"
#define	DEFAULT_ADD_DELETES	"logs/add_delete.log"
#define	TMP_URL			".info.tmp"
#define	TMP_FILE		".file.tmp"
#define	DEFAULT_AUTOTOPIC_F	"autotopic.ini"
#define	DEFAULT_HELPER_LIST	"userlist.db"
#define	DEFAULT_QUIZ_FILE	"quiz.db"
#define	DEFAULT_PERFORM		"perform.ini"
#define	DEFAULT_DEOP		"deop.ini"
#define	DEFAULT_RAND_SAY	"random.ini"
#define	DEFAULT_RAND_FILE	"randomstuff.ini"
#define DEFAULT_RANDQ_TEMPFILE  "randq.tmp"
#define DEFAULT_RAND_BACKUP_FILE "randomstuff.bak"
#define	DEFAULT_SERVERS		"servers.ini"
#define	DEFAULT_PERMBAN		"permbans.db"
#define	DEFAULT_SETUP		"setup.ini"
#define	MAX_SEARCH_LENGTH	350
#define ERR_SOCK_OPT		-1
#define ERR_TIMED_OUT		-1
#define ERR_CANT_MALLOC		-1
#define ERR_OPEN_SOCKET		-2
#define ERR_CONN_REFUSED	-2
#define ERR_NOT_ADDR		-3
#define ERR_WRITE_SOCKET	-3
#define ERR_NO_REACH		-4
#define ERR_CANT_CONNECT	-5
#define ERR_READ_SOCKET		-5
#define ERR_SERVER_BUSY		-6
#define ERR_NO_DOCUMENTS	-6
#define ERR_NO_DATA		-7
#define SUCCESS			0

#define LEGAL_TEXT		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-"
#define SAFE_LIST		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"
#define LEGAL_NICK_TEXT		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_-\\|[]{}`"

#define NUMBER_LIST		"1234567890"
#define	MAX_NICK_LENGTH		35

#ifndef	LANG	/* If not defined, default to english */
#define	LANG 			1
#endif

#define	NORMALR			0
#define WHUTR			1
#define DUNNOR			2

#define	RAND_NORMAL		0
#define	RAND_ACTION		1
#define	RAND_RAW		2

#define RANDQ_NORMAL            0
#define RANDQ_CASE              1
#define	RANDQ_RAND		2

#define	RDB_NORMAL		0
#define	RDB_ACTION		1
#define	RDB_RAW			2

/* ////////////////////////////////////////////////////////////////////// */

#define RESERVED1		"EXPLAIN"
#define RESERVED2		"DECLARE"

#include "langs/lang.h"
