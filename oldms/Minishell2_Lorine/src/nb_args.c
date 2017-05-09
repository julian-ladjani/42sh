/*
** nb_args.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Mon Mar 27 19:15:36 2017 Lorine Forfert
** Last update Mon Mar 27 19:18:16 2017 Lorine Forfert
*/

#include "my.h"

int	nb_args(char **tab)
{
  int	args;

  args = 0;
  while (tab[args] != NULL)
    ++args;
  return (args);
}
