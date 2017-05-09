/*
** my.h for minishell1 in /home/lorine/semester_1/PSU/PSU_2016_minishell1
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 17 16:35:52 2017 Lorine Forfert
** Last update Sun Apr  9 12:58:30 2017 Lorine Forfert
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef MY_H_
#define MY_H_

typedef struct		s_env
{
  char			*name;
  char			*value;
  struct s_env		*next;
}		        t_env;

typedef	struct	s_ms
{
  char	**tab;
  char	**path;
  char	**nenv;
  char	**arg;
  char	*gnl;
  int	i;
  int	pid;
  int	ret;
  char	**args;
  int	j;
}		t_ms;
  
char	*get_next_line(int);
char	**str_to_tab(char *, char, int, int);
char	*my_strncmp(char *, char *, int);
char	**cp_tab(char **, char **);
char	**str_tab(char *);
char	*mystrcat(char *, char *);
void	my_putstr(char *);
void	free_tab(char **);
char	*my_strncpy(char *, char *, int);
char	**my_list_to_tab(t_env *, char **);
char	*my_strcpy(char *, char *);
char	*mystrcatbis(char *, char *);
int	my_strlen(char *);
char	*my_strcat(char *, char *);
void	my_env(t_env *);
t_env	*my_setenv(t_env *, char **, int);
t_env	*my_unsetenv(t_env *, char *);
int	my_strcmp(char *, char *);
void	my_cd(char **, char **);
int	my_printf(char *, ...);
t_env	*init(t_env *, char *);
t_env	*push_back(t_env *, char *);
void	free_tab(char **);
int	nb_args(char **);
int	simple_r(char **, char **, char *);
char	*my_getpath(char **, char *);
int	is_redir(char *);
int	double_r(char **, char **, char *);
int	is_pipe(char *);
int	simple_l(char **, char **, char *);
void	which_redir(char **, char *, char *);
char	**concat_tabs(char **, char **);
int	double_l(char **, char **, char *);

#endif /* MY_H_ */
