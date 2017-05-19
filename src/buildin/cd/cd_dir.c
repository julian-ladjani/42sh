/*
** cd_dir.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 21:45:42 2017 Ladjani Julian
** Last update Thu May 18 01:51:51 2017 Ladjani Julian
*/

#include "sh.h"

int		my_cd(t_mysh *vars)
{
  t_envlist	*pwdelem;
  char		*pwd;
  t_cdlist	*cdfield;

  if ((pwdelem = search_in_envlist(vars->env, "$PWD")) == NULL)
    pwd = strdup(getcwd(NULL, 0));
  else
    pwd = strdup(pwdelem->envvalue);
  if (chdir(pwdelem->envvalue) < 0)
    {
      printf("%s: %s.\n", vars->cmd->data->av[1], strerror(errno));
      return (ERROR_RETURN);
    }
  addcdelem_before(vars->cdstack);
  if ((cdfield = vars->cdstack->prev) == NULL)
    return (ERROR_RETURN);
  cdfield->path = strdup(pwd);
  free(pwd);
  str_to_env(vars, "$PWD", getcwd(NULL, 0));
  return (SUCCES_RETURN);
}
