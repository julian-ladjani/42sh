/*
** str_tab.c for minishell in /home/lorine/semester_1/PSU/PSU_2016_minishell1
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Sat Jan 21 15:36:07 2017 Lorine Forfert
** Last update Sun Mar 26 17:54:04 2017 Lorine Forfert
*/

#include "../include/my.h"

int     nblines(char *str)
{
  int   nb;
  int   i;

  nb = 1;
  i = 0;
  while (str && str[i] != '\0')
    {
      if (str[i] == ':')
	nb++;
      i++;
    }
  return (nb);
}

int     nchar(char *str)
{
  int   i;
  int   nbr;
  int   tmp;

  i = 0;
  nbr = 0;
  tmp = 0;
  while (str && str[i] != '\0')
    {
      while (str[i] != '\0' && str[i] != ':')
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

char    **str_tab(char *str)
{
  char  **tab;
  int   i;
  int   j;
  int   k;

  tab = malloc(sizeof(char *) * (nblines(str) + 1));
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      tab[j] = malloc(sizeof(char) * (nchar(str) + 1));
      k = 0;
      while (str[i] != '\0' && str[i] != ':')
	{
	  tab[j][k] = str[i];
	  i++;
	  k++;
	}
      tab[j][k] = '\0';
      j++;
      if (str && str[i])
	i++;
    }
  tab[j] = NULL;
  return (tab);
}
