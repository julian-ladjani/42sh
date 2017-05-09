/*
** pipe.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 22:05:51 2017 Lorine Forfert
** Last update Thu Apr  6 22:08:03 2017 Lorine Forfert
*/

#include "my.h"

int	is_pipe(char *str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '|')
      return (1);
  return (0);
}
