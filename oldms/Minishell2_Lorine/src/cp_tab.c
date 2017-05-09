/*
** cp_tab.c for minishell1 in /home/lorine/semester_1/PSU/PSU_2016_minishell1
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Fri Jan 20 20:53:24 2017 Lorine Forfert
** Last update Mon Mar 13 15:02:35 2017 Lorine Forfert
*/

#include "../include/my.h"

int	lines(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

int	nbchar(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char	**cp_tab(char **dest, char **src)
{
  int	i;
  int	j;

  dest = malloc(sizeof(char *) * (lines(src) + 1));
  i = 0;
  while (src[i] != NULL)
    {
      dest[i] = malloc(sizeof(char) * (nbchar(src[i]) + 1));
      j = 0;
      while (src[i][j] != '\0')
	{
	  dest[i][j] = src[i][j];
	  j++;
	}
      dest[i][j] = '\0';
      i++;
    }
  dest[i] = NULL;
  return (dest);
}
