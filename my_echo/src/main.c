/*
** main.c for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:24:47 2017 ilomax
** Last update Wed May 17 19:07:31 2017 ilomax
*/

#include <stdio.h>
#include <unistd.h>
#include "my_echo.h"

int     my_strlen(char *str)
{
  int   i;

  if (str == NULL)
    return (-1);
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int     my_strcmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  if (!s1 || !s2)
    return (-1);
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] != '\0')
    {
      if ((s1[i] != s2[i]) || s1 == '\0' || s2 == '\0')
        return (1);
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  int		n;
  int		i;

  n = 0;
  i = 1;
  (void)ac;
  if (my_strcmp(av[1], "-n") == 0)
    {
      n = 1;
      i++;
    }
  while (av[i] != NULL)
    printf("%s ", av[i++]);
  if (n == 0)
    printf("\n");
  else if (n == 1)
    return (0);
  return (0);
}
