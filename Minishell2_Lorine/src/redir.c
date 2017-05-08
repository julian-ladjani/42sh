/*
** redir.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Wed Apr  5 16:53:47 2017 Lorine Forfert
** Last update Thu Apr  6 23:53:19 2017 Lorine Forfert
*/

#include "my.h"

int	is_redir(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '>' && str[i + 1] != '>')
	return (1);
      else if (str[i] == '<' && str[i + 1] != '<')
	return (2);
      else if (str[i] == '>' && str[i + 1] == '>')
	return (3);
      else if (str[i] == '<' && str[i + 1] == '<')
	return (4);
    }
  return (0);
}

int	simple_r(char **env, char **tab, char *path)
{
  int	fd;
  pid_t	pid;
  char	**args;

  args = str_to_tab(tab[0], ' ', 0, 0);
  if (path == NULL)
    {
      my_printf("%s: Command not found.\n", args[0]);
      return (0);
    }
  if ((fd = open(tab[1], O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
    return (84);
  pid = fork();
  if (pid == 0)
    {
      close(1);
      dup2(fd, 1);
      execve(mystrcat(path, args[0]), args, env);
    }
  close(fd);
  wait(0);
  return (0);
}

int     double_r(char **env, char **tab, char *path)
{
  int   fd;
  pid_t pid;
  char  **args;

  args = str_to_tab(tab[0], ' ', 0, 0);
  if (path == NULL)
    {
      my_printf("%s: Command not found.\n", args[0]);
      return (0);
    }
  if ((fd = open(tab[2], O_CREAT | O_APPEND | O_WRONLY, 0644)) == -1)
    return (84);
  pid = fork();
  if (pid == 0)
    {
      close(1);
      dup2(fd, 1);
      execve(mystrcat(path, args[0]), args, env);
    }
  close(fd);
  wait(0);
  return (0);
}

int	simple_l(char **env, char **tab, char *path)
{
  char	**cmd;
  pid_t	pid;
  char	**args;
  char	**cat;

  cmd = str_to_tab(tab[0], ' ', 0, 0);
  args = str_to_tab(tab[1], ' ', 0, 0);
  cat = concat_tabs(cmd, args);
  if (path == NULL)
    {
      my_printf("%s: Command not found.\n", cmd[0]);
      return (0);
    }
  pid = fork();
  if (pid == 0)
    execve(mystrcat(path, cmd[0]), cat, env);
  wait(0);
  return (0);
}

int	double_l(char **env, char **tab, char *path)
{
  char	*gnl;
  pid_t	pid;
  char	**args;

  my_printf("?");
  gnl = get_next_line(0);
  while (my_strcmp(gnl, tab[2]) != 0 && gnl != NULL)
    {
      my_printf("?");
      gnl = get_next_line(0);
    }
  if (path == NULL)
    {
      my_printf("%s: Command not found.\n");
      return (0);
    }
  args = str_to_tab(tab[0], ' ', 0, 0);
  pid = fork();
  if (pid == 0)
    execve(mystrcat(path, args[0]), args, env);
  wait(0);
  return (0);
}
