/*
** main.c for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:24:47 2017 ilomax
** Last update Sat May 20 14:09:30 2017 Ladjani Julian
*/

#include "sh.h"

int		echo_main(char **av)
{
  int		n;
  int		i;

  n = 0;
  i = 1;
  if (strcmp(av[1], "-n") == 0)
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
