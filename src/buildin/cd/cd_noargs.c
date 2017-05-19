/*
** cd_fonctions.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 17:10:16 2017 Ladjani Julian
** Last update Thu May 18 01:52:27 2017 Ladjani Julian
*/

#include "sh.h"

int		cd_no_args(t_mysh *vars)
{
  t_envlist	*home;
  t_envlist	*pwdelem;
  char		*pwd;

  if ((home = search_in_envlist(vars->env, "$HOME")) == NULL)
    {
      printf("cd: No home directory.");
      return (ERROR_RETURN);
    }
  if ((pwdelem = search_in_envlist(vars->env, "$PWD")) == NULL)
    pwd = strdup(getcwd(NULL, 0));
  else
    pwd = strdup(pwdelem->envvalue);
  if (chdir(home->envvalue) < 0)
    {
      printf("cd: Can't change to home directory.\n");
      return (ERROR_RETURN);
    }
  return (cd_no_args2(vars, pwd)); 
}

int		cd_no_args2(t_mysh *vars, char *pwd)
{
  t_cdlist	*cdfield;

  addcdelem_before(vars->cdstack);
  if ((cdfield = vars->cdstack->prev) == NULL)
    return (ERROR_RETURN);
  cdfield->path = strdup(pwd);
  free(pwd);
  str_to_env(vars, "$PWD", getcwd(NULL, 0));
  return (SUCCES_RETURN);
}
