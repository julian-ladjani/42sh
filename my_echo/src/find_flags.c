/*
** find_flags.c for 42 in /home/shielder/Projects/PSU/PSU_2016_42sh/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Fri May 19 21:21:32 2017 ilomax
** Last update Sat May 20 13:56:31 2017 ilomax
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

char	*find_flags(char **av)
{
  int	i;
  int	j;
  int	k;
  char	*flags;

  i = -1;
  k = -1;
  if ((flags = malloc(sizeof(char) * 4)) == NULL)
    return (NULL);
  while (av[++i] != NULL)
    {
      j = 0;
      while (av[i][++j] != '\0')
	flags[++k] = av[i][j];
    }
  return (flags);
}
