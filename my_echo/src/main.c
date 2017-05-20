/*
** main.c for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:24:47 2017 ilomax
** Last update Sat May 20 14:31:53 2017 ilomax
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "my_echo.h"

int	char_in_str(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (1);
      i++;
    }
  return (0);
}

void	show_tab(char **tab)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL)
    printf("|- %s \n", tab[i]);
}

void	display_res(t_opt opt, char **av)
{
  if (opt.f == 1)
    f_flag(av);
  else if (opt.F == 1)
    F_flag(av);
  if (opt.n == 1)
    return ;
  else
    printf("\n");
}

int		main(int ac, char **av)
{
  t_argv	*argv;
  t_opt		opt;
  char		*flags;

  argv = echo_parser(av, ac);
  opt = init_opt();
  flags = find_flags(argv->flags);
  if (char_in_str('n', flags) == 1)
      opt.n = 1;
  if (char_in_str('f', flags) == 1)
    {
      opt.f = 1;
      opt.F = 0;
    }
  else if (char_in_str('F', flags) == 1)
    {
      opt.f = 0;
      opt.F = 1;
    }
  display_res(opt, argv->args);
  return (0);
}
