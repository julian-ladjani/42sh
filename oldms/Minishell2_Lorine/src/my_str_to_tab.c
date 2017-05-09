/*
** str_to_tab.c for wolf3d in /home/lorine/semester_1/CPG/wolf3d
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Wed Dec 14 15:35:15 2016 Lorine Forfert
** Last update Thu Apr  6 13:09:06 2017 Lorine Forfert
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

int	nb_lines(char *str, char c)
{
  int	nb;
  int	i;

  nb = 1;
  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == c)
	nb++;
      i++;
    }
  return (nb);
}

int	nb_char(char *str, char c)
{
  int	i;
  int	nbr;
  int	tmp;

  i = 0;
  nbr = 0;
  tmp = 0;
  if (str[i] == ' ')
    ++i;
  while (str && str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != c)
	{
	  nbr++;
	  i++;
	}
      tmp = (nbr > tmp) ? nbr : tmp;
      nbr = 0;
      if (str && str[i])
	i++;
    }
  return (tmp);
}

char	**str_to_tab(char *str, char c, int i, int j)
{
  char	**tab;
  int	k;

  tab = malloc(sizeof(char *) * (nb_lines(str, c) + 1));
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (nb_char(str, c) + 1));
      k = 0;
      while (str[i] != '\0' && str[i] != c)
	{
	  if (str[i] == ' ' && i != 0 && str[i - 1] == c)
	    ++i;
	  tab[j][k] = str[i];
	  ++i;
	  ++k;
	}
      tab[j][k] = '\0';
      ++j;
      if (str && str[i])
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
