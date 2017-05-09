/*
** cd_fonctions.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 17:10:16 2017 Ladjani Julian
** Last update Tue May  9 17:34:56 2017 Ladjani Julian
*/

#include "42sh.h"

int		cd_no_args(t_mysh *vars)
{
  t_envlist	*home;

  if ((home = search_in_envlist(vars->env, "$HOME")) == NULL)
    {
      printf("cd: No home directory.");
      return (ERROR_RETURN);
    }
  str_to_env(vars, "$PWD", getcwd(NULL, 0));
  chdir
}
