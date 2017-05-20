/*
** find_flags.c for 42 in /home/shielder/Projects/PSU/PSU_2016_42sh/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Fri May 19 21:21:32 2017 ilomax
** Last update Sat May 20 12:58:43 2017 ilomax
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	cnt_flags(char **av, int ac)
{
  int	i;
  int	count;

  i = 1;
  count = 0;
  while (i < ac)
    {
      if (av[i][0] == '-')
	++count;
      else
	return (count);
      i++;
    }
  return (count);
}

char	*find_flags(char **av, int ac)
{
  int	i;
  int	j;
  int	k;
  int	n;
  char	*flags;

  n = cnt_flags(av, ac);
  if ((flags = malloc(sizeof(char) * (n * 2))) == NULL)
    return (NULL);
  i = 1;
  k = 0;
  while (i <= n)
    {
      j = 1;
      while (av[i][j] != '-' && av[i][j] != '\0')
	{
	  flags[k] = av[i][j];
	  ++k;
	  ++j;
	}
      ++i;
    }
  flags[k] = '\0';
  return (flags);
}
