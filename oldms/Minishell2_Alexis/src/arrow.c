/*
** arrow.c for arrow.c in /home/Alexisbonk/PSU_2016_minishell2
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Apr  5 13:58:40 2017 Alexis Knob
** Last update Fri Apr  7 10:39:25 2017 Alexis Knob
*/

#include <string.h>
#include "my.h"

int	getpath(char **path, char **s_bis_bis, int i)
{
  while (access(my_strcat(my_strcat(path[i], "/"), s_bis_bis[0]), F_OK) != 0 &&
	 path[i + 1] != NULL)
    i++;
  if (path[i + 1] == NULL)
    {
      my_printf("%s: Command not found.\n", s_bis_bis[0]);
      return (84);
    }
  else
    return (i);
}

int	arrow_one(char *s, int i, char **env, int fd)
{
  pid_t pid;
  char	**path;
  char	**s_bis;
  char	**s_bis_bis;

  path = my_str_to_wordtab(searchenv(env, "PATH"), ':', 0, 0);
  s_bis = my_str_to_wordtab(s, '>', 0, 0);
  s_bis_bis = my_str_to_wordtab(s_bis[0], ' ', 0, 0);
  i = getpath(path, s_bis_bis, 0);
  if (i == 84)
    return (1);
  else
    {
      fd = open(s_bis[1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
      pid = fork();
      if (pid == 0)
	{
	  dup2(fd, 1);
	  execve(my_strcat(my_strcat(path[i], "/"), s_bis_bis[0]), s_bis_bis, env);
	}
      wait(0);
      close(fd);
      return (0);
    }
}

int	arrow_two(char *s, int i, char **env, int fd)
{
  pid_t pid;
  char	**path;
  char	**s_bis;
  char	**s_bis_bis;

  path = my_str_to_wordtab(searchenv(env, "PATH"), ':', 0, 0);
  s_bis = my_str_to_wordtab(s, '>', 0, 0);
  s_bis_bis = my_str_to_wordtab(s_bis[0], ' ', 0, 0);
  i = getpath(path, s_bis_bis, 0);
  if (i == 84)
    return (1);
  else
    {
      fd = open(s_bis[2], O_CREAT | O_APPEND | O_WRONLY, 0644);
      pid = fork();
      if (pid == 0)
	{
	  dup2(fd, 1);
	  execve(my_strcat(my_strcat(path[i], "/"), s_bis_bis[0]), s_bis_bis, env);
	}
      wait(0);
      close(fd);
    }
  return (0);
}

int	checkifarrow(char **s, int i)
{
  while (s[++i] != NULL)
    {
      if (my_strcmp(s[i], ">") == 0)
	return (1);
      if (my_strcmp(s[i], "<") == 0)
	return (2);
      if (my_strcmp(s[i], ">>") == 0)
	return (3);
      if (my_strcmp(s[i], "<<") == 0)
	return (4);
    }
  return (0);
}

int	arrow(char *s, char **env)
{
  char	**s_bis;

  s_bis = my_str_to_wordtab(s, ' ', 0, 0);
  if (checkifarrow(s_bis, -1) == 1)
    arrow_one(s, 0, env, 0);
  else if (checkifarrow(s_bis, -1) == 2)
    arrow_two(s, 0, env, 0);
  else
    return (0);
  return (1);
}
