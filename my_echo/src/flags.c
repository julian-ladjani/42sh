/*
** f_flag.c for 42 in /home/shielder/Projects/PSU/PSU_2016_42sh/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Sat May 20 14:16:38 2017 ilomax
** Last update Sat May 20 16:51:59 2017 ilomax
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	f_flag(char **av)
{
  int	i;
  char	*str;

  i = -1;
  while (av[++i] != NULL)
    {
      write(1, str, strlen(str));
      back_parser(av[i]);
      printf(" ");
    }
}

void	F_flag(char **av)
{
  int	i;

  i = -1;
  while (av[++i] != NULL)
    {
      write(1, av[i], strlen(av[i]));
      printf(" ");
    }
}
