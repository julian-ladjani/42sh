/*
** parser.c for 42sh in /home/shielder/Projects/PSU/PSU_2016_42sh/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Fri May 19 15:10:53 2017 ilomax
** Last update Sat May 20 17:00:15 2017 ilomax
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_echo.h"

int	check_flag(char *str)
{
  int	i;

  i = 1;
  while (str[i] != '\0')
    {
      if (str[i] != 'n' && str[i] != 'f' && str[i] != 'F')
	return (0);
      i++;
    }
  return (1);
}

char	*back_parser(char *str)
{
  int	i;
  
  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] == '\\')
	{
	  if (char_in_str(str[i + 1], ESC_SEQ) == 1)
	    printf("YES IT FUCKING IS YOU BELLEND\n");
	}
    }
  return (str);
}

t_argv		*echo_parser(char **av, int ac)
{
  int		i;
  int		j;
  int		k;
  t_argv	*argv;

  i = 0;
  j = -1;
  k = -1;
  if ((((argv = malloc(sizeof(t_argv *) + 1)) == NULL))
      || ((argv->flags = malloc(sizeof(char *) *  ac + 1)) == NULL)
      || ((argv->args = malloc(sizeof(char *) * ac + 1)) == NULL))
    return (NULL);
  while (++i < ac)
    {
      if (av[i][0] == '-' && check_flag(av[i]) == 1)
	argv->flags[++j] = strdup(av[i]);
      else
	argv->args[++k] = strdup(av[i]);
    }
  argv->flags[++j] = NULL;
  argv->args[++k] = NULL;
  return (argv);
}

