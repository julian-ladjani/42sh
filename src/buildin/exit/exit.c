/*
** exit.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/exit
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 15:33:32 2017 Ladjani Julian
** Last update Sat May 20 16:14:56 2017 Ladjani Julian
*/

#include "sh.h"

static int	my_exitisnum(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-' && i != 0)
	{
	  printf("%s\n", "exit: Badly formed number.");
	  return (ERROR_RETURN);
	}
      if (i == 0 && ((str[i] < '0' || str[i] > '9') && str[i] != '-'))
	{
	  printf("%s\n", "exit: Expression Syntax.");
	  return (ERROR_RETURN);
	}
      if (i > 0 && (str[i] < '0' || str[i] > '9'))
	{
	  printf("%s\n", "exit: Badly formed number.");
          return (ERROR_RETURN);
	}
      i++;
    }
  return (SUCCES_RETURN);
}

int		exit_main(char **av)
{
  if (my_tablen(av) == 1)
    {
      printf("exit\n");
      exit(0);
    }
  if (my_tablen(av) > 2)
    {
      printf("%s\n", "exit: Expression Syntax.");
      return (ERROR_RETURN);
    }
  if (my_exitisnum(av[1]) == ERROR_RETURN)
    return (ERROR_RETURN);
  printf("exit\n");
  exit(atoi(av[1]));
}
