/*
** main.c for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:24:47 2017 ilomax
** Last update Sat May 20 13:06:37 2017 ilomax
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_echo.h"

void	show_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    printf("|- %s \n", tab[i]);
}

int		main(int ac, char **av)
{
  t_argv	*argv;

  argv = echo_parser(av, ac);
  printf("FLAGS = \n");
  show_tab(argv->flags);
  printf("ARGS = \n");
  show_tab(argv->args);
}
