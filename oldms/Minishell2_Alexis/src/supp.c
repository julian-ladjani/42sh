/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Fri Apr  7 10:40:05 2017 Alexis Knob
*/

#include <string.h>
#include "my.h"

int	supp_bis_bis(char **s, char **env)
{
  int	i;

  i = 0;
  if (my_strncmp("./", s[0], 2) == 0)
    {
      if (access(s[0], F_OK) != 0)
	{
	  my_printf("%s: Command not found.\n", s[0]);
	  return (1);
	}
      i = fork();
      if (i < 0)
	return (84);
      if (i == 0)
	execve(s[0], s, env);
      wait(0);
    }
  else
    return (0);
  return (1);
}

int	supp(char **s, char **env, int i)
{
  if (my_strcmp("exit", s[0]) == 0)
    {
      my_printf("exit\n");
      return (2);
    }
  else if (my_strcmp("env", s[0]) == 0)
    while (env[i] != '\0')
      printf("%s\n", env[i++]);
  else if (my_strcmp("cd", s[0]) == 0)
    {
      if (s[1] == NULL)
	{
	  i = chdir(searchenv(env, "HOME"));
	  my_printf("Directory: %s\n", getcwd(0, 0));
	  return (1);
	}
      i = chdir(s[1]);
      if (i == -1)
	my_printf("%s: Not a directory.\n", s[1]);
      if (i == 0)
	my_printf("Directory: %s\n", getcwd(0, 0));
    }
  else
    return (0);
  return (1);
}

char	**supp_bis(char **s, char **env, int i, int i_bis)
{
  if (my_strcmp("setenv", s[0]) == 0)
    {
      i_bis = searchinenv(env, s[1], s);
      if (s[1] == NULL)
	while (env[i] != '\0')
	  printf("%s\n", env[i++]);
      else if (s[3] != NULL && s[2] != NULL)
	my_printf("setenv: Too many arguments.\n");
      else if (i_bis != -1)
	env = replace(env, s[2], i_bis, s);
      else
	env = wordtab(env, s[1], s[2]);
    }
  else if (my_strcmp("unsetenv", s[0]) == 0)
    {
      i = 0;
      if (s[1] == NULL)
	my_printf("unsetenv: Too few arguments.");
      else
	while (s[++i] != NULL)
	  env = removeinenv(env, s[i]);
    }
  return (env);
}
