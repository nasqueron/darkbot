#include "defines.h"
#include "vars.h"
#include "prototypes.h"

int wsock = 0;
int sockerr = 0;
int optlen = sizeof(sockerr);
size_t nRandStuffs = 0;
long QUESTIONS = 0;
long ADDITIONS = 0;
long DELETIONS = 0;
long uptime = 0;
long NO_FLOOD = 0;
long NUM_SERV = 0;
long L_CLIENTS = 0;
long IRCOPS = 0;
long xtried = 0;
long G_USERS = 0;
long rt = 120;
long fc = 0;
long spr = 0;
long snr = 0;
long BP = 6667;
long CHECKED = 1;
long SEND_DELAY = 1;
long send_tog = 0;
long NUM_HELPER = 0;
long NUMLINESSEEN = 0;
long NUM_USER = 0;
#ifdef ENABLE_QUIZ
long quiz_timer = 0;
long quiz_line = 0;
bool quiz_answer = 0;
bool quiz_halt = 0;
char quiz_target[STRING_SHORT] = { 0 };
long recent_questions[10] = { 0 };
#endif

#ifdef ENABLE_RANDOM
long Rand_Stuff = 0;
long Rand_Idle = 0;
#endif
long AIL4 = 0;
long Sleep_Toggle = 0;
long Sleep_Time = 0;
long AIL3 = 0;
long AIL2 = 0;
long AIL5 = 0;
long JOINs = 0;
long PERMBAN_counter = 0;
long ram_load_time = 0;
long AIL9 = 0;
long AIL666 = 0;
long AIL8 = 0;
#ifdef ENABLE_QUIZ
long AIL13 = 0;
#endif
long LastInput = 0;
long AIL10 = 0;
long MARK_CHANGE = 0;
long html_counter = 0;
char NICK_COMMA[32] = { 0 };
char COLON_NICK[33] = { 0 };
char pass_data[512] = { 0 };
char pass_pass[STRING_SHORT] = { 0 };
char rword[STRING_SHORT] = { 0 };
char lc1[STRING_SHORT] = "0";
char lc2[STRING_SHORT] = "0";
char lc4[STRING_SHORT] = "0";
char lc3[STRING_SHORT] = "0";
char BPASS[STRING_SHORT] = "0";
char mask_tmp[STRING_LONG] = "0";
long lcn1 = 0;
long lcn2 = 0;
long lcn4 = 0;
long lcn3 = 0;
bool SeeN = false;
long DebuG = 0;
char slc1[STRING_SHORT] = "0";
char slc2[STRING_SHORT] = "0";
char slc4[STRING_SHORT] = "0";
char slc3[STRING_SHORT] = "0";
long slcn1 = 0;
long slcn2 = 0;
long slcn4 = 0;
long slcn3 = 0;

#ifdef	WIN32
char *rp391 = "niW-4cr8 tobkraD";
#else
char *rp391 = "4cr8 tobkraD";
#endif
char BCOLON_NICK[STRING_SHORT] = { 0 };
char DARKBOT_BIN[STRING_SHORT] = { 0 };
char URL2[STRING_SHORT] = { 0 };
char DBTIMERS_PATH[STRING_SHORT] = { 0 };
char LOG_DIR[STRING_SHORT] = { 0 };
char RDB_DIR[STRING_SHORT] = { 0 };
#ifdef	ENABLE_STATS
char STATS_FILE[STRING_SHORT] = { 0 };
#endif
char SEEN_FILE[STRING_SHORT] = { 0 };
char BACKUP_DUP[STRING_SHORT] = { 0 };
char ADD_DELETES[STRING_SHORT] = { 0 };
char AUTOTOPIC_F[STRING_SHORT] = { 0 };
char HELPER_LIST[STRING_SHORT] = { 0 };
char QUIZ_FILE[STRING_SHORT] = { 0 };
char PERFORM[STRING_SHORT] = { 0 };
char DEOP[STRING_SHORT] = { 0 };
char RAND_SAY[STRING_SHORT] = { 0 };
char RAND_FILE[STRING_SHORT] = { 0 };
char RANDQ_TEMPFILE[STRING_SHORT] = { 0 };
char RAND_BACKUP_FILE[STRING_SHORT] = { 0 };
char SERVERS[STRING_SHORT] = { 0 };
char PERMBAN[STRING_SHORT] = { 0 };
char SETUP[STRING_SHORT] = { 0 };
char DAT_DIR[STRING_SHORT] = { 0 };
char r_reply[STRING_SHORT] = { 0 };
char data[STRING_SHORT] = { 0 };
char g_chan[STRING_SHORT] = { 0 };
char dbVersion[STRING_SHORT] = { 0 };
char strbuff[STRING_SHORT] = { 0 };
char f_tmp[STRING_LONG] = { 0 };
char UID[STRING_SHORT] = "database";
char BS[STRING_SHORT] = "irc.undernet.org";
char CMDCHAR[2] = "!";
char CHAN[STRING_SHORT] = "#darkbot";
char s_Mynick[STRING_SHORT] = "darkbot";
char g_host[STRING_SHORT] = { 0 };
char Mynick[STRING_SHORT] = "darkbot";
char sleep_chan[STRING_SHORT] = { 0 };
char VHOST[STRING_SHORT] = "0";
char REALNAME[STRING_SHORT] = "http://www.freezedown.org";
char privmsg_log[STRING_SHORT] = { 0 };

long CONNECT_WAIT_TIMEOUT = 10;
bool PERFORM_TIMER = true;
char DEFAULT_UMODE[STRING_SHORT] = "+i-ds";
bool ANTI_IDLE = false;
bool DISPLAY_SYNC = false;

bool SORT = false;
bool FIND_DUPS = false;
bool SAVE_DUPS = true;
bool GENERAL_QUESTIONS = true;
//bool ALLOW_ADD_IN_MSG = false;
//bool ALLOW_DEL_IN_MSG = false;
bool MSG_RESPONSES = false;

bool LOG_ADD_DELETES = true;
bool LOG_PRIVMSG = true;

long SLEEP_TIME = 300;
char GOSLEEP_ACTION[STRING_SHORT] = "\1ACTION falls asleep... ZzzZZzzZZzz\1";
char WAKEUP_ACTION[STRING_SHORT] = "\1ACTION wakes up from a snooze..\1";

long LASTCOMM_TIME = 5;
long OUTPUT1_COUNT = 4;
long OUTPUT1_DELAY = 1;
long OUTPUT2_COUNT = 6;
long OUTPUT2_DELAY = 2;
long OUTPUT3_DELAY = 3;
long OUTPUT_PURGE_COUNT = 7;

char EXISTING_ENTRY[STRING_SHORT] = "Sorry, there is an existing entry under keyword";
char NO_ENTRY[STRING_SHORT] = "I was unable to find entry:";
//char CANT_FIND[STRING_SHORT] = "Was unable to find";	/* ... */
char NO_TOPIC[STRING_SHORT] = "Sorry, I don't have any entry for";	/* ... */
char TRY_FIND[STRING_SHORT] = "What am I trying to find";
char WHUT[STRING_SHORT] = "hmmm?";
char DUNNO_Q[STRING_SHORT] = "*shrug*";
bool RANDOM_DUNNO = true;
bool RANDOM_WHUT = true;

#ifdef ENABLE_RANDOM
//bool RANDOM_STUFF = true;
long RAND_STUFF_TIME = 3600;
long RAND_IDLE = 1800;
//long RAND_LEVEL = 2;
//bool RANDQ = true;
bool BACKUP_RANDOMSTUFF = false;
#endif

bool JOIN_GREET = true;
long SLASTCOMM_TIME = 60;
bool VOICE_USERS_ON_JOIN = false;
bool OP_USERS_ON_LOGIN = false;

bool DO_WHOIS = false;
long MAX_LASTSEEN = 604800;
char SEEN_REPLY[STRING_SHORT] = "in the last 7 days.";

char COMPLAIN_REASON[STRING_SHORT] = "grrr, kick me again and I'm going to...";
bool BITCH_ABOUT_DEOP = false;
char BITCH_DEOP_REASON[STRING_SHORT] = "grr, someone op me!";

long AUTOTOPIC_TIME = 1800;
char DEFAULT_KICK[STRING_SHORT] = "Requested!";
bool KICK_ON_BAN = false;

bool KICK_ON_CHANNEL_NOTICE = true;
bool BAN_ON_CHANNEL_NOTICE = false;
bool BAN_BY_HOST = false;

bool FLOOD_KICK = true;
char FLOOD_REASON[STRING_SHORT] = "Don't flood!";

#ifdef ENABLE_QUIZ
long QUIZ_TIMER = 25;
long QUIZ_REPEAT_TIMER = 20;
#endif

bool HELP_GREET = false;
bool AUTOHELP_GUESTS = false;

char mySetinfo[STRING_SHORT] = "My !setinfo variables are: ^ nick, % Number of joins, & \
Channel, $ user@host. Example: !setinfo ^ has joined & % times!!  (also, if \
you make the first char of your SETINFO a \"+\" the setinfo will be shown \
as an ACTION)";

char myVariables[STRING_SHORT] = "Data variables are: N~ (Nick), C~ (Chan), T~ \
(Time/date) B~ (Botnick), Q~ (Question asked), R~ (random nick), !~ \
(command char), S~ (current Server), P~ (current port) V~ (botVer), W~ \
(db WWW site), H~ (u@h), t~ (unixtime), BAN (sets a ban), TEMPBAN (bans \
for 60 sec)";


struct rusage r_usage;

struct ignorelist *ignorehead = NULL;

struct sendq *sendqhead = NULL, *sendqtail = NULL;

struct userlist *userhead = NULL;

struct helperlist *helperhead = NULL;

struct permbanlist *permbanhead = NULL;

struct old ood[STRING_SHORT];

struct sl124 *sh124 = NULL;

#ifdef	ENABLE_STATS
struct statslist *statshead = NULL;
#endif

struct webinfo
 GOOGLE_webinfo = { "GOOGLE", "www.google.com", 80, "/search?q=" } ,
 METAR_webinfo = { "METAR", "weather.noaa.gov", 80, "/cgi-bin/mgetmetar.pl?cccc=" } ,
 TAF_webinfo = { "TAF", "weather.noaa.gov", 80, "/cgi-bin/mgettaf.pl?cccc=" } ,
 WEATHER_webinfo = { "WEATHER", "mobile.wunderground.com", 80, "/cgi-bin/findweather/getForecast?brand=mobile&query=" };


struct setup_parameter parameters[] =
{
// I managed to eliminate these options when I rewrote chansrv.c.
//    {ST_BOOLEAN, 3, sizeof(ALLOW_ADD_IN_MSG),       {"ALLOW_ADD_IN_MSG",       NULL, NULL, NULL, NULL}, "allowing ADD command in private",         &ALLOW_ADD_IN_MSG,     NULL},
//    {ST_BOOLEAN, 3, sizeof(ALLOW_DEL_IN_MSG),       {"ALLOW_DEL_IN_MSG",       NULL, NULL, NULL, NULL}, "allowing DEL command in private",         &ALLOW_DEL_IN_MSG,     NULL},
    {ST_BOOLEAN, 3, sizeof(ANTI_IDLE),              {"ANTI_IDLE",              NULL, NULL, NULL, NULL}, "idling for less than ten minutes",        &ANTI_IDLE,            NULL},
#ifdef ENABLE_CHANNEL
    {ST_BOOLEAN, 3, sizeof(BITCH_ABOUT_DEOP),       {"BITCH_DEOP",             NULL, NULL, NULL, NULL}, "bitch about deop",                        &BITCH_ABOUT_DEOP,     NULL},
    {ST_STRING,  3, sizeof(BITCH_DEOP_REASON),      {"BITCH_DEOP_TEXT",        NULL, NULL, NULL, NULL}, "deop complaint",                          BITCH_DEOP_REASON,     NULL},
#endif
    {ST_STRING,  3, sizeof(COMPLAIN_REASON),        {"BITCH_KICK_TEXT",        NULL, NULL, NULL, NULL}, "bot kicked message",                      COMPLAIN_REASON,       NULL},
    {ST_STRING,  3, sizeof(CMDCHAR),                {"BOT_CMD_CHAR",           NULL, NULL, NULL, NULL}, "bot's command char",                      CMDCHAR,               NULL},
    {ST_STRING,  3, sizeof(Mynick),                 {"BOT_NICK",               NULL, NULL, NULL, NULL}, "bot's nickname",                          Mynick,                check_nick_parameter},
    {ST_STRING,  3, sizeof(REALNAME),               {"BOT_NAME",               NULL, NULL, NULL, NULL}, "bot's real name",                         REALNAME,              NULL},
    {ST_STRING,  3, sizeof(UID),                    {"BOT_USER_ID",            NULL, NULL, NULL, NULL}, "bot's user ID",                           UID,                   NULL},
    {ST_STRING,  3, sizeof(DEFAULT_UMODE),          {"BOT_USER_MODE",          NULL, NULL, NULL, NULL}, "bot's user modes",                        DEFAULT_UMODE,         NULL},
    {ST_STRING,  3, sizeof(VHOST),                  {"BOT_VHOST",              NULL, NULL, NULL, NULL}, "bot's virtual host",                      VHOST,                 NULL},
    {ST_INTEGER, 3, sizeof(CONNECT_WAIT_TIMEOUT),   {"CONNECT_TIME",           NULL, NULL, NULL, NULL}, "server connection timeout",               &CONNECT_WAIT_TIMEOUT, NULL},
    {ST_STRING,  3, sizeof(CHAN),                   {"DEFAULT_CHANNEL",        NULL, NULL, NULL, NULL}, "channel",                                 CHAN,                  NULL},
    {ST_BOOLEAN, 3, sizeof(DISPLAY_SYNC),           {"DISPLAY_SYNC",           NULL, NULL, NULL, NULL}, "tell channel bot has finished syncing",   &DISPLAY_SYNC,         NULL},
    {ST_BOOLEAN, 3, sizeof(DO_WHOIS),               {"DO_WHOIS",               NULL, NULL, NULL, NULL}, "questionable channel alert",              &DO_WHOIS,             NULL},
    {ST_STRING,  3, sizeof(DUNNO_Q),                {"DUNNO_TEXT",             NULL, NULL, NULL, NULL}, "no answer complaint",                     DUNNO_Q,               NULL},
    {ST_BOOLEAN, 3, sizeof(RANDOM_DUNNO),           {"DUNNO_RANDOM_TEXT",      NULL, NULL, NULL, NULL}, "random no answer complaint",              &RANDOM_DUNNO,         NULL},
    {ST_BOOLEAN, 3, sizeof(FIND_DUPS),              {"DUPS_REMOVE",            NULL, NULL, NULL, NULL}, "remove duplicates in hatabase",           &FIND_DUPS,            NULL},
    {ST_BOOLEAN, 3, sizeof(SAVE_DUPS),              {"DUPS_SAVE",              NULL, NULL, NULL, NULL}, "save duplicates in database",             &SAVE_DUPS,            NULL},
    {ST_STRING,  3, sizeof(EXISTING_ENTRY),         {"ENTRY_EXISTS_TEXT",      NULL, NULL, NULL, NULL}, "replacing existing complaint",            EXISTING_ENTRY,        NULL},
    {ST_STRING,  3, sizeof(NO_ENTRY),               {"ENTRY_NOT_EXIST_TEXT",   NULL, NULL, NULL, NULL}, "non-existing topic complaint",            NO_ENTRY,              NULL},
    {ST_STRING,  3, sizeof(NO_TOPIC),               {"FIND_NO_TEXT",           NULL, NULL, NULL, NULL}, "no topic search complaint",               NO_TOPIC,              NULL},
    {ST_STRING,  3, sizeof(TRY_FIND),               {"FIND_WHAT_TEXT",         NULL, NULL, NULL, NULL}, "try find search complaint",               TRY_FIND,              NULL},
#ifdef ENABLE_CHANNEL
    {ST_BOOLEAN, 3, sizeof(KICK_ON_CHANNEL_NOTICE), {"FLOOD_NOTICE_KICK",      NULL, NULL, NULL, NULL}, "kick on channel notice flood",          &KICK_ON_CHANNEL_NOTICE, NULL},
    {ST_BOOLEAN, 3, sizeof(BAN_ON_CHANNEL_NOTICE),  {"FLOOD_NOTICE_BAN",       NULL, NULL, NULL, NULL}, "ban on channel notice flood",           &BAN_ON_CHANNEL_NOTICE,  NULL},
    {ST_BOOLEAN, 3, sizeof(BAN_BY_HOST),            {"FLOOD_NOTICE_BAN_HOST",  NULL, NULL, NULL, NULL}, "ban by host on channel notice flood",     &BAN_BY_HOST,          NULL},
    {ST_BOOLEAN, 3, sizeof(FLOOD_KICK),             {"FLOOD_KICK",             NULL, NULL, NULL, NULL}, "kick if bot is flooded",                  &FLOOD_KICK,           NULL},
    {ST_STRING,  3, sizeof(FLOOD_REASON),           {"FLOOD_TEXT",             NULL, NULL, NULL, NULL}, "flooded bot complaint",                   FLOOD_REASON,          NULL},
#endif
    {ST_BOOLEAN, 3, sizeof(AUTOHELP_GUESTS),        {"GREET_GUESTS_TEXT",      NULL, NULL, NULL, NULL}, "give guests help",                        &AUTOHELP_GUESTS,      NULL},
    {ST_BOOLEAN, 3, sizeof(HELP_GREET),             {"GREET_NEW_TEXT",         NULL, NULL, NULL, NULL}, "give new users help",                     &HELP_GREET,           NULL},
    {ST_BOOLEAN, 3, sizeof(JOIN_GREET),             {"GREET_USER_TEXT",        NULL, NULL, NULL, NULL}, "registered user greeting",                &JOIN_GREET,           NULL},
    {ST_INTEGER, 3, sizeof(LASTCOMM_TIME),          {"IGNORE_TIME",            NULL, NULL, NULL, NULL}, "seconds to ignore repeated topics",       &LASTCOMM_TIME,        NULL},
    {ST_INTEGER, 3, sizeof(SLASTCOMM_TIME),         {"IGNORE_USER_TIME",       NULL, NULL, NULL, NULL}, "registered user delay seconds",           &SLASTCOMM_TIME,       NULL},
#ifdef ENABLE_CHANNEL
    {ST_STRING,  3, sizeof(DEFAULT_KICK),           {"KICK_TEXT",              NULL, NULL, NULL, NULL}, "kick message",                            DEFAULT_KICK,          NULL},
    {ST_BOOLEAN, 3, sizeof(KICK_ON_BAN),            {"KICK_ON_BAN",            NULL, NULL, NULL, NULL}, "kick when banned",                        &KICK_ON_BAN,          NULL},
#endif
    {ST_BOOLEAN, 3, sizeof(LOG_ADD_DELETES),        {"LOG_CHANGES",            NULL, NULL, NULL, NULL}, "logging of database changes",             &LOG_ADD_DELETES,      NULL},
    {ST_BOOLEAN, 3, sizeof(LOG_PRIVMSG),            {"LOG_PRIVATE",            NULL, NULL, NULL, NULL}, "logging of private messages",             &LOG_PRIVMSG,          NULL},
#ifdef ENABLE_CHANNEL
    {ST_BOOLEAN, 3, sizeof(OP_USERS_ON_LOGIN),      {"OP_ON_LOGIN",            NULL, NULL, NULL, NULL}, "op users on login",                       &OP_USERS_ON_LOGIN,    NULL},
#endif
    {ST_INTEGER, 3, sizeof(OUTPUT1_COUNT),          {"OUTPUT1_COUNT",          NULL, NULL, NULL, NULL}, "output delay threshold",                  &OUTPUT1_COUNT,        NULL},
    {ST_INTEGER, 3, sizeof(OUTPUT1_DELAY),          {"OUTPUT1_TIME",           NULL, NULL, NULL, NULL}, "output delay seconds",                    &OUTPUT1_DELAY,        NULL},
    {ST_INTEGER, 3, sizeof(OUTPUT2_COUNT),          {"OUTPUT2_COUNT",          NULL, NULL, NULL, NULL}, "long output delay threshold",             &OUTPUT2_COUNT,        NULL},
    {ST_INTEGER, 3, sizeof(OUTPUT2_DELAY),          {"OUTPUT2_TIME",           NULL, NULL, NULL, NULL}, "long output delay seconds",               &OUTPUT2_DELAY,        NULL},
    {ST_INTEGER, 3, sizeof(OUTPUT_PURGE_COUNT),     {"OUTPUT_PURGE_COUNT",     NULL, NULL, NULL, NULL}, "purge output delay threshold",            &OUTPUT_PURGE_COUNT,   NULL},
    {ST_INTEGER, 3, sizeof(OUTPUT3_DELAY),          {"OUTPUT3_TIME",           NULL, NULL, NULL, NULL}, "purge output delay seconds",              &OUTPUT3_DELAY,        NULL},
    {ST_BOOLEAN, 3, sizeof(PERFORM_TIMER),          {"PERFORM_TIME",           NULL, NULL, NULL, NULL}, "sending perform.ini to server reqularly", &PERFORM_TIMER,        NULL},
    {ST_BOOLEAN, 3, sizeof(GENERAL_QUESTIONS),      {"QUESTIONS_GENERAL",      NULL, NULL, NULL, NULL}, "bot responds without being asked",        &GENERAL_QUESTIONS,    NULL},
    {ST_BOOLEAN, 3, sizeof(MSG_RESPONSES),          {"QUESTIONS_PRIVATE",      NULL, NULL, NULL, NULL}, "bot responds to private questions",       &MSG_RESPONSES,        NULL},
#ifdef ENABLE_QUIZ
    {ST_INTEGER, 3, sizeof(QUIZ_TIMER),             {"QUIZ_TIME",              NULL, NULL, NULL, NULL}, "quiz answer seconds",                     &QUIZ_TIMER,           NULL},
    {ST_INTEGER, 3, sizeof(QUIZ_REPEAT_TIMER),      {"QUIZ_REPEAT_TIME",       NULL, NULL, NULL, NULL}, "next quiz delay seconds",                 &QUIZ_REPEAT_TIMER,    NULL},
#endif
#ifdef ENABLE_RANDOM
// This one is currently ./configure --enable-random
//    {ST_BOOLEAN, 3, sizeof(RANDOM_STUFF),           {"RANDOM_STUFF",           NULL, NULL, NULL, NULL}, "random utterences",                       &RANDOM_STUFF,         NULL},
    {ST_BOOLEAN, 3, sizeof(BACKUP_RANDOMSTUFF),     {"RANDOM_BACKUP",          NULL, NULL, NULL, NULL}, "enable random stuff auto backups",        &BACKUP_RANDOMSTUFF,   NULL},
    {ST_INTEGER, 3, sizeof(RAND_IDLE),              {"RANDOM_IDLE_TIME",       NULL, NULL, NULL, NULL}, "seconds idle before random utterences",   &RAND_IDLE,            NULL},
// This one is currently ./configure --with-random=level
//    {ST_INTEGER, 3, sizeof(RAND_LEVEL),             {"RANDOM_LEVEL",           NULL, NULL, NULL, NULL}, "level for adding random things",          &RAND_LEVEL,           NULL},
// This one is currently ./configure --enable-randq
//    {ST_BOOLEAN, 3, sizeof(RANDQ),                  {"RANDOM_Q",               NULL, NULL, NULL, NULL}, "enable RANDQ command",                    &RANDQ,                NULL},
    {ST_INTEGER, 3, sizeof(RAND_STUFF_TIME),        {"RANDOM_TIME",            NULL, NULL, NULL, NULL}, "seconds between random utterences",       &RAND_STUFF_TIME,      NULL},
#endif
    {ST_BOOLEAN, 3, sizeof(SeeN),                   {"SEEN_MODE",              NULL, NULL, NULL, NULL}, "seen mode",                               &SeeN,                 NULL},
    {ST_INTEGER, 3, sizeof(MAX_LASTSEEN),           {"SEEN_TIME",              NULL, NULL, NULL, NULL}, "maximum last seen seconds",               &MAX_LASTSEEN,         NULL},
    {ST_STRING,  3, sizeof(SEEN_REPLY),             {"SEEN_TEXT",              NULL, NULL, NULL, NULL}, "maximum last seen reply",                 SEEN_REPLY,            NULL},
    {ST_STRING,  3, sizeof(mySetinfo),              {"SETINFO_TEXT",           NULL, NULL, NULL, NULL}, "setinfo variables help text",             mySetinfo,             NULL},
    {ST_INTEGER, 3, sizeof(SLEEP_TIME),             {"SLEEP_TIME",             NULL, NULL, NULL, NULL}, "seconds to sleep for",                    &SLEEP_TIME,           NULL},
    {ST_STRING,  3, sizeof(GOSLEEP_ACTION),         {"SLEEP_TEXT",             NULL, NULL, NULL, NULL}, "sleep action",                            GOSLEEP_ACTION,        NULL},
    {ST_STRING,  3, sizeof(WAKEUP_ACTION),          {"SLEEP_WAKE_TEXT",        NULL, NULL, NULL, NULL}, "wakeup action",                           WAKEUP_ACTION,         NULL},
    {ST_BOOLEAN, 3, sizeof(SORT),                   {"SORT_DB",                NULL, NULL, NULL, NULL}, "sort database on startup",                &SORT,                 NULL},
#ifdef ENABLE_CHANNEL
    {ST_INTEGER, 3, sizeof(AUTOTOPIC_TIME),         {"TOPIC_TIME",             NULL, NULL, NULL, NULL}, "topic setting seconds",                   &AUTOTOPIC_TIME,       NULL},
#endif
    {ST_STRING,  3, sizeof(myVariables),            {"VARIABLES_TEXT",         NULL, NULL, NULL, NULL}, "data variables help text",                myVariables,           NULL},
#ifdef ENABLE_CHANNEL
    {ST_BOOLEAN, 3, sizeof(VOICE_USERS_ON_JOIN),    {"VOICE_ON_JOIN",          NULL, NULL, NULL, NULL}, "voice users on join",                     &VOICE_USERS_ON_JOIN,  NULL},
#endif
    {ST_STRING,  3, sizeof(WHUT),                   {"WHUT_TEXT",              NULL, NULL, NULL, NULL}, "no text complaint",                       WHUT,                  NULL},
    {ST_BOOLEAN, 3, sizeof(RANDOM_WHUT),            {"WHUT_RANDOM_TEXT",       NULL, NULL, NULL, NULL}, "random no text complaint",                &RANDOM_WHUT,          NULL},
// Cant find CANT_FIND.  B-)
//    {ST_STRING,  3, sizeof(CANT_FIND),              {"CANT_FIND",              NULL, NULL, NULL, NULL}, "can't find search complaint",             CANT_FIND,             NULL},
    {ST_STRING,  4, 0, {NULL, NULL, NULL, NULL, NULL}, NULL, NULL, NULL}
};


struct setup_parameter *
set_parameter(char *input)
{
    struct setup_parameter *result = NULL;

    /* ignore comments. */
    if (*input != '#') 
    {
	int i, found = -1;
	char *dat = NULL, *ptr = NULL;

	dat = strdup(input);
	if ((ptr = strchr(dat, '=')) != NULL)
	    *ptr++ = '\0';
	for (result = &parameters[0]; result->parameter[0] != NULL; result++)
	{
	    for (i = 0; result->parameter[i] != NULL; i++)
	    {
		if (strcasecmp(dat, result->parameter[i]) == 0)
		{
		    found = i;
		    break;
		}
	    }
	    if (found != -1)
		break;
	}

	if (found == -1)
	    result = NULL;
	else
	{
	    if ((ptr) && (result->func))
	    {
		ptr = result->func(result, ptr);
		if (ptr == NULL)
		    result = NULL;
	    }
	    if (ptr)
	    {
#ifdef	ENABLE_VERBOSE
		printf("Setting %s = %s\n", result->summary, ptr);
#endif
		switch (result->type)
		{
		    case ST_BOOLEAN : 
		    {
			bool *variable = result->value;

			*variable = isBoolean(ptr);
			break;
		    }

		    case ST_INTEGER : 
		    {
			long *variable = result->value;

			*variable = atoi(ptr);
			break;
		    }

		    case ST_STRING  : 
		    {
			char *variable = result->value;

			strncpy(variable, ptr, result->max_size);
			break;
		    }
		}
	    }
	}
	free(dat);
    }

    return result;
}

void
save_setup (void)
{
    struct setup_parameter *result = NULL;

    printf("*** Writing setup file: %s (%s)\n", SETUP, date());
    remove(TMP_FILE);

    for (result = &parameters[0]; result->parameter[0] != NULL; result++)
    {
	switch (result->type)
	{
	    case ST_BOOLEAN : 
	    {
		bool *variable = result->value;

		db_log(TMP_FILE, "%s=%d\n", result->parameter[0], (*variable) ? 1 : 0);
		break;
	    }

	    case ST_INTEGER : 
	    {
		long *variable = result->value;

		db_log(TMP_FILE, "%s=%ld\n", result->parameter[0], *variable);
		break;
	    }

	    case ST_STRING  : 
	    {
		char *variable = result->value;

		db_log(TMP_FILE, "%s=%s\n", result->parameter[0], variable);
		break;
	    }
	}
    }

    rename(TMP_FILE, SETUP);
}
