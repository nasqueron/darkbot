/*
 * Copyright (C) 1996 Darkbot Project.

 * This program is free software, you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2.  This
 * program is distributed in the hope that it will be useful, but without
 * any warranty, without even the implied warranty of merchantability or
 * fitness for a particular purpose.  See the COPYING file for details.
 */


#define STRING_SHORT    512
#define STRING_LONG     2048

#define FLAG_CHANOP	0x0001
#define FLAG_CHANVOICE	0x0002

extern int wsock;
extern int sockerr;
extern int optlen;
extern size_t nRandStuffs;
extern long QUESTIONS;
extern long ADDITIONS;
extern long DELETIONS;
extern long uptime;
extern long NO_FLOOD;
extern long NUM_SERV;
extern long L_CLIENTS;
extern long IRCOPS;
extern long xtried;
extern long G_USERS;
extern long rt;
extern long fc;
extern long spr;
extern long snr;
extern long BP;
extern long CHECKED;
extern long SEND_DELAY;
extern long send_tog;
extern long NUM_HELPER;
extern long NUM_USER;
extern long NUMLINESSEEN;
extern long Rand_Stuff;
extern long Rand_Idle;
extern long AIL4;
extern long Sleep_Toggle;
extern long Sleep_Time;
extern long AIL3;
extern long AIL2;
extern long AIL5;
extern long JOINs;
extern long PERMBAN_counter;
extern long	RAND_CHANS;
extern long ram_load_time;
extern long AIL9;
extern long AIL666;
extern long AIL8;
#ifdef ENABLE_QUIZ
extern long AIL13;
#endif
extern long LastInput;
extern long AIL10;
extern long MARK_CHANGE;
extern long html_counter;
extern long lcn1;
extern long lcn2;
extern long lcn4;
extern long lcn3;
extern bool SeeN;
extern long DebuG;
#ifdef ENABLE_QUIZ
extern long quiz_timer;
extern long quiz_line;
extern bool quiz_answer;
extern bool quiz_halt;
extern long recent_questions[10];
#endif
extern char NICK_COMMA[32];
extern char COLON_NICK[33];
extern char BPASS[STRING_SHORT];
extern char pass_data[512];
extern char pass_pass[STRING_SHORT];
extern char rword[STRING_SHORT];
extern char lc1[STRING_SHORT];
extern char lc2[STRING_SHORT];
extern char lc4[STRING_SHORT];
extern char lc3[STRING_SHORT];
extern char slc1[STRING_SHORT];
extern char slc2[STRING_SHORT];
extern char slc4[STRING_SHORT];
extern char slc3[STRING_SHORT];
extern char	mask_tmp[STRING_LONG];
extern char quiz_target[STRING_SHORT];
extern long slcn1;
extern long slcn2;
extern long slcn4;
extern long slcn3;
extern char *rp391;
extern char BCOLON_NICK[STRING_SHORT];
extern char DARKBOT_BIN[STRING_SHORT];
extern char URL2[STRING_SHORT];
extern char DBTIMERS_PATH[STRING_SHORT];
extern char LOG_DIR[STRING_SHORT];
extern char RDB_DIR[STRING_SHORT];
#ifdef ENABLE_STATS
extern char STATS_FILE[STRING_SHORT];
#endif
extern char SEEN_FILE[STRING_SHORT];
extern char BACKUP_DUP[STRING_SHORT];
extern char ADD_DELETES[STRING_SHORT];
extern char AUTOTOPIC_F[STRING_SHORT];
extern char HELPER_LIST[STRING_SHORT];
extern char QUIZ_FILE[STRING_SHORT];
extern char PERFORM[STRING_SHORT];
extern char DEOP[STRING_SHORT];
extern char RAND_SAY[STRING_SHORT];
extern char RAND_FILE[STRING_SHORT];
extern char RANDQ_TEMPFILE[STRING_SHORT];
extern char RAND_BACKUP_FILE[STRING_SHORT];
extern char SERVERS[STRING_SHORT];
extern char PERMBAN[STRING_SHORT];
extern char SETUP[STRING_SHORT];
extern char DAT_DIR[STRING_SHORT];
extern char r_reply[STRING_SHORT];
extern char data[STRING_SHORT];
extern char g_chan[STRING_SHORT];
extern char dbVersion[STRING_SHORT];
extern char strbuff[STRING_SHORT];
extern char f_tmp[STRING_LONG];
extern char UID[STRING_SHORT];
extern char BS[STRING_SHORT];
extern char CMDCHAR[2];
extern char CHAN[STRING_SHORT];
extern char s_Mynick[STRING_SHORT];
extern char g_host[STRING_SHORT];
extern char Mynick[STRING_SHORT];
extern char sleep_chan[STRING_SHORT];
extern char VHOST[STRING_SHORT];
extern char REALNAME[STRING_SHORT];
extern char privmsg_log[STRING_SHORT];

extern long CONNECT_WAIT_TIMEOUT;
extern bool PERFORM_TIMER;
extern char DEFAULT_UMODE[STRING_SHORT];
extern bool ANTI_IDLE;
extern bool DISPLAY_SYNC;

extern bool SORT;
extern bool FIND_DUPS;
extern bool SAVE_DUPS;
extern bool GENERAL_QUESTIONS;
extern bool ALLOW_ADD_IN_MSG;
extern bool ALLOW_DEL_IN_MSG;
extern bool MSG_RESPONSES;

extern bool LOG_ADD_DELETES;
extern bool LOG_PRIVMSG;

extern long SLEEP_TIME;
extern char GOSLEEP_ACTION[STRING_SHORT];
extern char WAKEUP_ACTION[STRING_SHORT];

extern long LASTCOMM_TIME;
extern long OUTPUT1_COUNT;
extern long OUTPUT1_DELAY;
extern long OUTPUT2_COUNT;
extern long OUTPUT2_DELAY;
extern long OUTPUT3_DELAY;
extern long OUTPUT_PURGE_COUNT;

extern char EXISTING_ENTRY[STRING_SHORT];
extern char NO_ENTRY[STRING_SHORT];
//extern char CANT_FIND[STRING_SHORT];	/* ... */
extern char NO_TOPIC[STRING_SHORT];	/* ... */
extern char TRY_FIND[STRING_SHORT];
extern char WHUT[STRING_SHORT];
extern bool RANDOM_WHUT;
extern char DUNNO_Q[STRING_SHORT];
extern bool RANDOM_DUNNO;

#ifdef ENABLE_RANDOM
//extern bool RANDOM_STUFF;
extern long RAND_STUFF_TIME;
extern long RAND_IDLE;
//extern long RAND_LEVEL;
//extern bool RANDQ;
extern bool BACKUP_RANDOMSTUFF;
#endif

extern bool JOIN_GREET;
extern long SLASTCOMM_TIME;
#ifdef ENABLE_CHANNEL
extern bool VOICE_USERS_ON_JOIN;
extern bool OP_USERS_ON_LOGIN;
#endif

extern bool DO_WHOIS;
extern long MAX_LASTSEEN;
extern char SEEN_REPLY[STRING_SHORT];

extern char COMPLAIN_REASON[STRING_SHORT];
#ifdef ENABLE_CHANNEL
extern bool BITCH_ABOUT_DEOP;
extern char BITCH_DEOP_REASON[STRING_SHORT];

extern long AUTOTOPIC_TIME;
extern char DEFAULT_KICK[STRING_SHORT];
extern bool KICK_ON_BAN;

extern bool KICK_ON_CHANNEL_NOTICE;
extern bool BAN_ON_CHANNEL_NOTICE;
extern bool BAN_BY_HOST;

extern bool FLOOD_KICK;
extern char FLOOD_REASON[STRING_SHORT];
#endif

#ifdef ENABLE_QUIZ
extern long QUIZ_TIMER;
extern long QUIZ_REPEAT_TIMER;
#endif

extern bool HELP_GREET;
extern bool AUTOHELP_GUESTS;

extern char mySetinfo[STRING_SHORT];
extern char myVariables[STRING_SHORT];

extern struct rusage r_usage;

extern struct ignorelist
{
    char nick[STRING_SHORT];
    struct ignorelist *next;
}
 *ignorehead;

extern struct sendq
{
	char data[STRING_SHORT];
	struct sendq *next;
}
 *sendqhead, *sendqtail;

extern struct userlist
{					/* internal userlist */
	char chan[STRING_SHORT];
	char nick[STRING_SHORT];
	char uh[STRING_SHORT];
	long flags;			/* op/voice/etc */
	long level;			/* auth */
	short global;			/* Global user? */
	long idle;
	struct userlist *next;
}
 *userhead;

extern struct helperlist
{
	char chan[STRING_SHORT];
	char uh[STRING_SHORT];
	char nick[STRING_SHORT];
	long level;
	size_t num_join;
	char greetz[STRING_SHORT];
	char pass[STRING_SHORT];
	struct helperlist *next;
}
 *helperhead;

/**
 * 6/23/00 Dan
 * - Changed permbanlist to have dynamically allocated
 *   userhost and reason fields.
 * - Changed type of counter to size_t, this should be an
 *   unsigned type.
 */
extern struct permbanlist
{
	char *uh;
	char *reason;
	size_t counter;

	struct permbanlist *next;
}
 *permbanhead;

extern struct old
{
	char host[200];
	long time;
	int count;
	int value;
	int kick;
}
 ood[STRING_SHORT];

extern struct sl124
{
	char name[STRING_SHORT];
	long port;
	char pass[STRING_SHORT];
	struct sl124 *next;
}
 *sh124;

#ifdef ENABLE_STATS
extern struct statslist
{
	char nick[STRING_SHORT];
	char uh[STRING_SHORT];
	long total;
	long added_time;
	long last_time;

	struct statslist *next;
}
 *statshead;
#endif

extern struct	randstats
{
	char	chan	[STRING_SHORT];
	size_t	Rand_Stuff;
	size_t	Rand_Idle;
	size_t	refnum;
	size_t	nCount;		/* Number of times we outputted to this channel. */
	struct	randstats	*next;
/*	struct	randstats	*prev; */
}	
 *randstatshead;

struct chanserv_output
{
    char                         *output;
    struct chanserv_output       *next;
};

extern struct webinfo
{
	char trigger[STRING_SHORT];
	char host[STRING_SHORT];
	int port;
	char url[STRING_SHORT];
}
 WEBSEARCH_webinfo, METAR_webinfo, TAF_webinfo, WEATHER_webinfo;


enum setup_type
{
   ST_BOOLEAN = 0,
   ST_INTEGER = 1,
   ST_STRING = 2
};

enum chanserv_invoke_type
{
   DIRECT_INVOKE = 0,   // command
   ADDRESS_INVOKE = 1,  // bot: command
   MSG_INVOKE = 2,      // /msg bot command
   CHAR_INVOKE = 3      // !command
};

extern struct setup_parameter
{
    enum setup_type	type;
    int			access;         /* Access level required to change the value. */
    size_t		max_size;
    char		*parameter[5];
    char		*summary;
    void		*value;         /* Where the value is stored. */
    void 		*(*func) (struct setup_parameter *parameter, char *ptr);  /* Optional function that can do other things with the value, and veto the change by returning NULL. */
}
parameters[];
