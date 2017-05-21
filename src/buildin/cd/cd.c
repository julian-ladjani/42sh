/*
** cd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 13:31:19 2017 Ladjani Julian
** Last update Sun May 21 23:25:00 2017 Ladjani Julian
*/

#include "sh.h"

char		*get_my_pwd(t_mysh *vars)
{
  t_envlist	*pwdelem;
  char		*pwd;

  if ((pwdelem = search_in_envlist(vars->env, "PWD")) == NULL ||
      pwdelem->envvalue == NULL)
    pwd = strdup(getcwd(NULL, 0));
  else
    pwd = strdup(pwdelem->envvalue);
  return (pwd);
}

int		my_chdir(char *dir, t_mysh *vars)
{
  t_cdlist	*cdfield;

  if (dir == NULL)
    return (ERROR_RETURN);
  if (chdir(dir) < 0)
    {
      printf("%s: %s.\n", dir, strerror(errno));
      return (ERROR_RETURN);
    }
  if ((cdfield = addcdelem_before(vars->cdstack)) == NULL)
    return (ERROR_RETURN);
  cdfield->path = strdup(getcwd(NULL, 0));
  str_to_env(vars, "PWD", strdup(getcwd(NULL, 0)));
  return (SUCCES_RETURN);
}

t_cdlist	*get_cd_back_pwd(t_mysh *vars, int nb)
{
  int		i;
  t_cdlist	*list;

  i = 0;
  list = vars->cdstack->prev;
  while (i < nb && list != vars->cdstack)
    {
      i++;
      list = list->prev;
    }
  if (list == vars->cdstack)
    return (NULL);
  return (list);
}

static int	my_cd_print(t_mysh *vars)
{
  t_cdlist	*elem;
  int		i;

  i = 0;
  elem = vars->cdstack->next;
  while (elem != vars->cdstack)
    {
      if (elem->path != NULL)
	printf("%d: %s\n", i, elem->path);
      i++;
      elem = elem->next;
    }
  return (SUCCES_RETURN);
}

int		cd_main(t_mysh *vars, t_cmdlist *elem)
{
  t_cmddata	*cmd;
  int		returnvalue;

  returnvalue = 0;
  cmd = elem->data;
  if (my_tablen(cmd->av) < 2)
    returnvalue = cd_no_args(vars);
  else if (my_tablen(cmd->av) == 2 && strcmp(cmd->av[1], "-print") == 0)
    returnvalue = my_cd_print(vars);
  else if (my_tablen(cmd->av) == 2 && strncmp(cmd->av[1], "-", 1) == 0)
    returnvalue = my_cd_back(vars, elem);
  else if (my_tablen(cmd->av) == 2)
    returnvalue = my_cd(vars, elem);
  else
    {
      printf("cd: Too many arguments.\n");
      returnvalue = ERROR_RETURN;
    }
  return (returnvalue);
}
