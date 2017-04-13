/*
** minishell.h for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell1
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed Mar 22 15:18:50 2017 Ladjani Julian
** Last update Sun Apr  9 16:04:56 2017 Ladjani Julian
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

# define READ_SIZE 100
# define PIPE_CHAR '|'
# define LREDIR_CHAR '<'
# define RREDIR_CHAR '>'
# define LDREDIR_CHAR "<<"
# define RDREDIR_CHAR ">>"
# define SEP_CHAR ';'

typedef enum	e_type
  {
    NOTHING,
    PIPE,
    LREDIR,
    RREDIR,
    LDREDIR,
    RDREDIR,
  }		t_type;

typedef enum	e_cmdtype
  {
    EXEC,
    CD,
    EXIT,
    SETENV,
    UNSETENV,
    ENV,
  }		t_cmdtype;

typedef enum	e_mode
  {
    START,
    NORMAL,
    END,
  }		t_mode;

typedef struct	s_list
{
  char		*env;
  char		*envkey;
  char		*envvalue;
  char		first;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

typedef struct	s_cmd
{
  t_mode	mode;
  t_type	type;
  t_cmdtype	cmdtype;
  int		fd[2];
  char		*cmd;
  char		**av;
  char		**ae;
}		t_cmd;

typedef struct	s_mysh
{
  int		exitval;
  int		exit;
  pid_t		pid;
  pid_t		childpid;
  int		childstatus;
  int		childreturn;
  char		*cmd;
  t_cmd		*scmd;
  struct s_list	*env;
}		t_mysh;

char		*get_next_line(const int fd, int *exit);
char		*set_my_cmd(char *cmd, t_mysh *vars);
char		*set_my_path(char *path, char *cmd);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strdup(char *src);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int n);
char		*epur_str(char *str);

char		**arg_to_argv(t_mysh *vars);
char		**env_to_tabenv(t_list *root);
char		**my_str_to_wordtab(char *str, char sep);

int		my_strncmp(char *s1, char *s2, int n);
int		my_strcmp(char *s1, char *s2);
int		my_getnbr(char *str);
int		my_strlen(char *str);
int		my_tablen(char **tab);
int		my_str_isalpha(char *str);
int		match(char *s1, char *s2);
int		pre_my_cmd(t_mysh *vars, t_type type, char *cmd);
int		my_builtin(t_mysh *vars, int fd);

void		init_my_env(t_mysh *vars, char **ae);
void		write_my_prompt(t_mysh *vars);
void		prompt(t_mysh *vars);
void		str_to_env(t_mysh *vars);
void		clean_list(t_list *list);
void		delete_list(t_list *list);
void		addelem_before(t_list *elem);
void		addelem_after(t_list *elem);
void		addelem_first(t_list *root);
void		addelem_last(t_list *root);
void		delelem_first(t_list *root);
void		delelem_last(t_list *root);
void		delelem(t_list *elem);
void		my_setenv(t_mysh *vars, int fd);
void		my_env(t_mysh *vars, int fd);
void		my_unsetenv(t_mysh *vars, int fd);
void		my_cd(t_mysh *vars, int fd);
void		my_cd_env(t_mysh *vars, int fd);
void		my_cd_home(t_mysh *vars, int fd);
void		my_cd_error(char *str, int fd);
void		my_exec(t_mysh *vars);
void		my_return_wait(t_mysh *vars);
void		my_putstr(char *str);
void		my_putstrn(char *str);
void		my_putstrfd(char *str, int fd);
void		my_putstrnfd(char *str, int fd);
void		my_putexecerror(t_mysh *vars);
void		my_pipetype(t_mysh *vars, char **tab, int *fdin, int i);
void		my_execpipe2(t_mysh *vars, int *fdin);

t_list		*search_in_list(t_list *root, char *word);
t_list		*list_create();
t_mysh		*init_my_vars();

#endif /* !MINISHELL_H_ */
