/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Fri Mar 24 15:48:37 2017 Alexis Knob
*/

#include "my.h"

char    *searchenv(char **env, char *search)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    if (my_strncmp(env[i], search, my_strlen(search)) == 0)
      return (env[i] + my_strlen(search) + 1);
  return (0);
}

int	searchinenv(char **env, char *search, char **s)
{
  int	i;

  i = -1;
  if (s[1] != NULL)
    {
      while (env[++i] != NULL)
	if (my_strncmp(env[i], search, my_strlen(search)) == 0)
	  return (i);
    }
  return (-1);
}
