/* ------------ Below are function declarations --------------- */

#ifdef ENABLE_STATUS
void	parse_252				(char *), 
	parse_251				(char *), 
	parse_255				(char *);
#endif

char    **tokenize				(char *, size_t *);
size_t	count_lines				(char *);
void	show_seen				(char *, char *, char *),
	count_seen				(char *, char *), 
	show_info2				(const char *, const char *);

long	save_seen				(char *, char *, char *);
void	do_randomtopic				(int, char *, char *, char *, char *);



#ifdef	RANDOM_STUFF

void	do_random_stuff				(void),
	check_idle_channels			(void),
	get_rand_stuff_time			(void),
	del_autotopic				(const char *), 
	add_randomstuff				(char *, char *, char *), 
	do_autotopics				(void);
#endif

#ifdef	RANDQ
void	do_randq				(char *, const int, const char *, const char *);
#endif

void	datasearch				(const char *, char *, char *),
	display_url				(char *, char *, char *), 
	set_pass				(char *, char *, char *, char *),
	do_modes				(char *, char *), 
	process_nick				(char *, char *);
long	verify_pass				(char *, char *, char *, char *), 
	ifexist_autotopic			(char *);

#ifdef ENABLE_CHANNEL
void	save_permbans				(void);
#endif

void	do_quit					(const char *, long);

#ifdef	ENABLE_MATH
void	do_math					(const char *, char *, char *);
#endif

void	parse_who				(char *);
void	set_autotopic				(char *, char *, char *);
void	delete_user_ram				(char *, char *), 
	get_s					(void),
	delete_url				(const char *, char *, char *),
	update_setinfo				(const char *, const char *, const char *);

#ifdef ENABLE_CHANNEL
void	add_permban				(const char *, size_t, const char *);
int	del_permban				(const char *, const char *);
#endif

int	check_existing_url			(const char *, char *, char *);
void	*check_nick_parameter			(struct setup_parameter *parameter, char *ptr);
void	show_helper_list			(const char *, long),
	set_paths				(void),
	show_banlist				(const char *), 
	chanserv				(char *, char *, char *),
	raw_now					(char *), 
	find_url				(const char *, char *, char *), 
	save_changes				(void),
	show_url				(char *, char *, char *, long, long, char *, long);
char	*strlwr					(char *), 
	*rand_reply				(const char *), 
	*date					(void),
	*get_multiword_topic			(char *), 
	*revert_topic				(char *),
	*get_rand_nick				(const char *), 
	*get_word				(long, char *, char *);

void	info					(const char *, char *), 
	load_helpers				(void),
	scan_chan_users				(char *, char *, char *), 
	do_login				(char *, char *);
long	do_lastcomm				(char *, char *, char *), 
	setinfo_lastcomm			(char *);
void	parse					(char *), 
	add_helper				(const char *, const char *, long, size_t,
						 const char *, const char *, char);

int	get_connection				(const char *, const char *, int), 
	readln					(void),
	writeln					(const char *);

bool	check_permban				(const char *, const char *, const char *);
long	cf					(char *, char *, char *), 
	f_f					(char *), 
	get_passwd				(char *);
time_t	return_useridle				(const char *, const char *, int);
void	a_f					(char *), 
	reset_					(void), 
	delete_user				(const char *, char *),
	add_user				(char *, char *, char *, long);
void	set_fds					(void), 
	sig_hup					(int), 
	sig_segv				(int), 
	save_setup				(void);
void	stripline				(char *), 
	init_bot				(void), 
	sig_alrm				(int);
void	parse_server_msg			(fd_set *);
void	trailing_blanks				(char *),
	db_log					(const char *, const char *,...),
	gs26					(void), 
	add_s25					(char *, long, char *),
	add_banned_server			(char *, char *), 
	S					(const char *,...), 
	del_sendq				(long), 
	clear_sendq				(long, long);

char	L[524], 
	*random_word				(char **);

int	socketfd, 
	alarmed,	
	check_access				(char *, char *, int, char *),
	match_wild				(const char *, const char *), 
	Send					(void), 
	get_sendq_count				(long);
void	check_dbtimers				(void);

void	register_bot				(void);
void	prepare_bot				(void);
int	create_connection			(char *, char *, long);
int	Snow					(const char *, ...);
void	show_chaninfo				(const char *, const char *, const char *);
void	show_chanusers				(const char *, const char *);

const 	char		*run_program		(const char *);

void	do_autotopics				(void);
void	add_stats				(char *, char *, long, long, long);
void	load_stats				(void);
void	get_stats				(char *, char *);
#ifdef ENABLE_QUIZ
void	run_quiz_question			(char *);
void	run_quiz_answer				(void);
#endif
void	check_files				(void);
void	run_perform				(void);
int 	web_post_query				(char *trigger, char *source, char *uh, char *target, char *query, int size);
int	add_ignore_user_ram			(char *);
int	delete_ignore_user_ram			(char *);
int	check_ignore_user_ram			(char *);
void	call_reserved_1				(char *, char *, char *);
void	call_reserved_2				(char *, char *, char *);
size_t	count_char				(const char *, const char);
bool	isBoolean				(char *aBoolean);
void	reverse					(char *);
char	*mask_from_nick				(char *, const char *);
char	*uh_from_nick				(char *, const char *);
long	is_op					(char *, const char *);
void	do_op					(char *, const char *, long);

struct setup_parameter *set_parameter		(char *input);
