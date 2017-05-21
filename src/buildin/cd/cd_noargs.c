/*
** cd_fonctions.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 17:10:16 2017 Ladjani Julian
** Last update Sun May 21 20:03:08 2017 Ladjani Julian
*/

#include "sh.h"

int		cd_no_args(t_mysh *vars)
{
  t_envlist	*home;
  char		*pwd;
  t_cdlist	*cdfield;

  if ((home = search_in_envlist(vars->env, "HOME")) == NULL ||
      home->envvalue == NULL)
    {
      printf("cd: No home directory.");
      return (ERROR_RETURN);
    }
  pwd = get_my_pwd(vars);
  if (chdir(home->envvalue) < 0)
    {
      printf("cd: Can't change to home directory.\n");
      return (ERROR_RETURN);
    }
  if ((cdfield = addcdelem_before(vars->cdstack)) == NULL)
    return (ERROR_RETURN);
  cdfield->path = strdup(pwd);
  pwd = strdup(getcwd(NULL, 0));
  str_to_env(vars, "PWD", pwd);
  return (SUCCES_RETURN);
}
