/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Thu Apr  6 13:26:16 2017 Alexis Knob
*/

#include "my.h"

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

char	**my_str_to_wordtab(char *str, char c, int i, int j)
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
	  if (i != 0 && str[i] == ' ' && str[i - 1] == c)
	    ++i;
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
