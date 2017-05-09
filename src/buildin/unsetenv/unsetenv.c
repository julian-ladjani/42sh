/*
** setenv.c for setenv in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/setenv
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 13:21:32 2017 Ladjani Julian
** Last update Tue May  9 13:28:53 2017 Ladjani Julian
*/

#include "42sh.h"

int		unsetenv_main(t_mysh *vars)
{
  int		i;
  t_envlist	*elem;

  i = 1;
  while (vars->scmd->av[i] != NULL)
    {
      if ((elem = search_in_list(vars->env, vars->scmd->av[i])) != NULL)
        {
          delelem(elem);
        }
      i++;
    }
  if (i == 1)
    {
      printf("%s\n", "unsetenv: Too few arguments.");
      return (1);
    }
  return (0);
}
