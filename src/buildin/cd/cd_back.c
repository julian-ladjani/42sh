/*
** cd_back.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 22:24:10 2017 Ladjani Julian
** Last update Sun May 21 20:11:12 2017 Ladjani Julian
*/

#include "sh.h"

static int	str_is_num(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      i++;
    }
  return (1);
}

int		my_cd_back(t_mysh *vars, t_cmdlist *cmd)
{
  int		nback;
  t_cdlist	*oldpwd;

  if (str_is_num(cmd->data->av[1] + 1) == 0)
    {
      printf("cd: Bad Number.\n");
      return (ERROR_RETURN);
    }
  nback = atoi(cmd->data->av[1] + 1);
  if (nback == 0)
    nback++;
  if ((oldpwd = get_cd_back_pwd(vars, nback)) == NULL ||
      oldpwd->path == NULL)
    {
      printf("cd: no such entry in dir stack.\n");
      return (ERROR_RETURN);
    }
  return (my_chdir(oldpwd->path, vars));
}
