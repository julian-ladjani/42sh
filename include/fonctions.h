/*
** fonctions.h for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/include
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed May 17 11:33:00 2017 Ladjani Julian
** Last update Sun May 21 23:13:32 2017 Ladjani Julian
*/

#ifndef FONCTIONS_H_
# define FONCTIONS_H_

/*
** Misleanous
*/

void		my_putstr(char *str);
void		my_putstrn(char *str);
void		free_my_tab(char **tab);
char		*my_strcat(char *dest, char *src);
char            *get_next_line(const int fd, int *exit);
char		**add_str_to_tab(char **tab, char *str);
char		**my_str_to_wordtab(char *str, char sep);
int		my_str_isalpha(char *str);
int		my_tablen(char **tab);
int		match(char *s1, char *s2);
int		nmatch(char *s1, char *s2);

/*
** CD
*/

void		clean_cdlist(t_cdlist *list);
void		delete_cdlist(t_cdlist *list);
void		addcdelem_first(t_cdlist *root);
void		addcdelem_last(t_cdlist *root);
void		delcdelem_first(t_cdlist *root);
void		delcdelem_last(t_cdlist *root);
void		delcdelem(t_cdlist *elem);
int		my_cd_back(t_mysh *vars, t_cmdlist *cmd);
int		cd_main(t_mysh *vars, t_cmdlist *cmd);
int		my_cd(t_mysh *vars, t_cmdlist *cmd);
int		cd_no_args(t_mysh *vars);
int		my_chdir(char *dir, t_mysh *vars);
char		*get_my_pwd(t_mysh *vars);
t_cdlist	*get_cd_back_pwd(t_mysh *vars, int nb);
t_cdlist	*cdlist_create();
t_cdlist	*addcdelem_before(t_cdlist *elem);
t_cdlist	*addcdelem_after(t_cdlist *elem);
t_cdlist	*get_cd_field(t_mysh *vars, int nb);

/*
** ENV / UNSETENV / SETENV
*/

void		str_to_env(t_mysh *vars, char *envvar, char *value);
void		clean_envlist(t_envlist *list);
void		delete_envlist(t_envlist *list);
void		addenvelem_first(t_envlist *root);
void		addenvelem_last(t_envlist *root);
void		delenvelem_first(t_envlist *root);
void		delenvelem_last(t_envlist *root);
void		delenvelem(t_envlist *elem);
char		**env_to_tabenv(t_envlist *root);
int		env_main(t_mysh *vars, t_cmdlist *list);
int		unsetenv_main(t_mysh *vars, t_cmdlist *cmd);
int		setenv_main(t_mysh *vars, t_cmdlist *cmd);
t_envlist	*search_in_envlist(t_envlist *root, char *word);
t_envlist	*envlist_create();
t_envlist	*addenvelem_before(t_envlist *elem);
t_envlist	*addenvelem_after(t_envlist *elem);

/*
** ECHO
*/

int		echo_main(char **av, t_cmdlist *cmd);

/*
** ALIAS
*/

void		clean_aliaslist(t_aliaslist *list);
void		delete_aliaslist(t_aliaslist *list);
void		addaliaselem_first(t_aliaslist *root);
void		addaliaselem_last(t_aliaslist *root);
void		delaliaselem_first(t_aliaslist *root);
void		delaliaselem_last(t_aliaslist *root);
void		delaliaselem(t_aliaslist *elem);
int		alias_main(t_mysh *vars, t_cmdlist *list);
t_aliaslist	*aliaslist_create();
t_aliaslist	*addaliaselem_before(t_aliaslist *elem);
t_aliaslist	*addaliaselem_after(t_aliaslist *elem);

/*
** HISTORY
*/

int		history_main(t_mysh *vars, t_cmdlist *cmd);

/*
** PROMPT
*/

int		my_prompt(t_mysh *vars);

/*
** EXIT
*/

int		exit_main(char **av);

/*
** INITIALISATION
*/

void		avoid_signaux();
t_mysh		*init_prog(char **ae);
void		exit_my_sh(t_mysh *vars);

/*
** PARSOR
*/

void		clean_cmdlist(t_cmdlist *list);
void		delete_cmdlist(t_cmdlist *list);
void		addcmdelem_first(t_cmdlist *root);
void		addcmdelem_last(t_cmdlist *root);
void		delcmdelem_first(t_cmdlist *root);
void		delcmdelem_last(t_cmdlist *root);
void		delcmdelem(t_cmdlist *elem);
char		*epur_cmd(char *cmd);
char		*makespace_cmd(char *cmd, int *buffsize);
char		*get_next_word(char *word, int *cursor);
char		*makespace_cmd2(t_makespace *space);
char		*add_cfst(char *str, char c, int pos, int *buffsize);
void		makespace_cmd_cond(char c, int *inhib, int *inquote);
int		nb_char_op(char *cmd);
int		makespace_see_char(char *cmd, size_t i, int *buffsize);
int		make_redir(t_cmdlist *elem, t_cmdlist *root);
int		parse_list_redir(t_cmdlist *root);
int		parse_list_pipe(t_cmdlist *root);
int		parse_list_sep(t_cmdlist *root);
t_type		cmp_ope(char c1, char c2);
t_type		check_word(char *word);
t_cmdlist	*cmdlist_create();
t_cmdlist	*addcmdelem_before(t_cmdlist *elem);
t_cmdlist	*addcmdelem_after(t_cmdlist *elem);
t_cmdlist	*parse_my_cmd(t_mysh *vars, t_cmdlist *cmdelem, char *word);
t_cmdlist	*parse_first_word(t_mysh *vars);
t_cmdlist	*parse_to_type(t_mysh *vars, t_cmdlist *cmdelem, char *word);
t_cmdlist	*parse_my_redir(t_mysh *vars, t_cmdlist *cmdelem, char *word);
t_cmdlist	*parse_my_sep(t_mysh *vars, t_cmdlist *cmdelem, char *word);
t_cmdlist	*parse_my_pipe(t_mysh *vars, t_cmdlist *cmdelem, char *word);
int		call_cmd(t_mysh *vars, char *cmd);

/*
** READER
*/

/*
** EXEC
*/

void		exec_buildin(t_mysh *vars, t_cmdlist *cmd);
char		*set_my_cmd_path(t_mysh *vars, t_cmdlist *cmd);
int		do_execution(t_mysh *vars, t_cmdlist *cmd);
int		check_my_cmd(t_mysh *vars, t_cmdlist *cmd);
int		do_redir(t_cmdlist *cmd);

#endif /* !FONCTIONS_H_ */
