/*
** free_tab.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 26 18:04:50 2017 Lorine Forfert
** Last update Mon Mar 27 19:00:27 2017 Lorine Forfert
*/

#include "my.h"

void	free_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    free(tab[i]);
  free(tab);
}
