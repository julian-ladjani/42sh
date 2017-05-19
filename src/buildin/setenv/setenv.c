/*
** setenv.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/setenv
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 13:24:29 2017 Ladjani Julian
** Last update Wed May 17 11:58:19 2017 Ladjani Julian
*/

#include "sh.h"

int	setenv_main(t_mysh *vars)
{
  if (my_tablen(vars->cmd->data->av) == 1)
    {
      env_main(vars);
      return (0);
    }
  else if (my_tablen(vars->cmd->data->av) > 3)
    {
      printf("%s\n", "setenv: Too many arguments.");
      return (1);
    }
  if (my_str_isalpha(vars->cmd->data->av[1]) == 0)
    {
      printf("%s", "setenv: Variable name must");
      printf("%s\n", " contain alphanumeric characters.");
      return (1);
    }
  str_to_env(vars, vars->cmd->data->av[1], vars->cmd->data->av[2]);
  return (0);
}
