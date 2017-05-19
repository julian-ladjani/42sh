/*
** cd_back.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 22:24:10 2017 Ladjani Julian
** Last update Thu May 18 01:50:42 2017 Ladjani Julian
*/

#include "sh.h"

t_cdlist	*get_cd_field(t_mysh *vars, int nb)
{
  int		i;
  t_cdlist	*field;

  i = 0;
  field = vars->cdstack->prev;
  while (i <= nb && field != vars->cdstack)
    field = field->prev;
  if (i != nb)
    return (NULL);
  return (field);
}

int		my_cd_back(t_mysh *vars)
{
  int		nback;
  t_cdlist	*oldpwd;
  t_envlist	*pwdelem;
  char		*pwd;
 
  nback = atoi(vars->cmd->data->av[1] + 1);
  if ((pwdelem = search_in_envlist(vars->env, "$PWD")) == NULL)
    pwd = strdup(getcwd(NULL, 0));
  else
    pwd = strdup(pwdelem->envvalue);
  if ((oldpwd = get_cd_field(vars, nback)) == NULL)
    {
      printf("cd: no such entry in dir stack.\n");
      return (ERROR_RETURN);
    }
  if (chdir(oldpwd->path) < 0)
    {
      printf("%s: %s.\n", oldpwd->path, strerror(errno));
      return (ERROR_RETURN);
    }
  my_cd_back2(vars, oldpwd, pwd);
  return (SUCCES_RETURN);
}

void		my_cd_back2(t_mysh *vars, t_cdlist *oldpwd, char *pwd)
{
  delcdelem(oldpwd);
  addcdelem_before(vars->cdstack);
  oldpwd = vars->cdstack->prev;
  oldpwd->path = strdup(pwd);
  free(pwd);
  str_to_env(vars, "$PWD", getcwd(NULL, 0));
}
