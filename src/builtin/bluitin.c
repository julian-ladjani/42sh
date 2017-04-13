/*
** bluitin.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Jan 24 06:06:47 2017 Julian Ladjani
** Last update Sun Apr  9 15:02:13 2017 Ladjani Julian
*/

#include "minishell.h"

int		my_builtin(t_mysh *vars, int fd)
{
  if (vars->scmd->cmdtype == EXIT)
    {
      if (vars->scmd->av[1] != NULL)
        vars->exitval = my_getnbr(vars->scmd->av[1]);
      vars->exit = 1;
    }
  else if (vars->scmd->cmdtype == CD)
    my_cd(vars, fd);
  else if (vars->scmd->cmdtype == UNSETENV)
    my_unsetenv(vars, fd);
  else if (vars->scmd->cmdtype == SETENV)
    my_setenv(vars, fd);
  else if (vars->scmd->cmdtype == ENV)
    my_env(vars, fd);
  return (vars->exitval);
}

void		my_cd(t_mysh *vars, int fd)
{
  t_list	*pwd;
  char		*spwd;

  if (my_tablen(vars->scmd->av) > 1 && my_strcmp(vars->scmd->av[1], "~") != 0)
    {
      if ((pwd = search_in_list(vars->env, "OLDPWD\0")) != NULL)
	spwd = my_strdup(pwd->envvalue);
      else if ((pwd = search_in_list(vars->env, "PWD\0")) != NULL)
	spwd = my_strdup(pwd->envvalue);
      else
	spwd = my_strdup(getcwd(NULL, 0));
      if (my_strcmp(vars->scmd->av[1], "-") == 0)
	vars->scmd->av[1] = spwd;
      if (chdir(vars->scmd->av[1]) < 0)
	{
	  my_cd_error(vars->scmd->av[1], fd);
	  return ;
	}
      my_cd_env(vars, fd);
    }
  else
    my_cd_home(vars, fd);
}

void		my_unsetenv(t_mysh *vars, int fd)
{
  int		i;
  t_list	*elem;

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
      my_putstrfd("unsetenv: Too few arguments.\n", fd);
      vars->exitval = 1;
    }
}

void		my_env(t_mysh *vars, int fd)
{
  t_list 	*elem;

  elem = vars->env->next;
  while (elem != vars->env)
    {
      my_putstrnfd(elem->env, fd);
      elem = elem->next;
    }
}

void		my_setenv(t_mysh *vars, int fd)
{
  if (my_tablen(vars->scmd->av) == 1)
    {
      my_env(vars, fd);
      return ;
    }
  else if (my_tablen(vars->scmd->av) > 3)
    {
      my_putstrnfd("setenv: Too many arguments.", fd);
      vars->exitval = 1;
      return ;
    }
  if (my_str_isalpha(vars->scmd->av[1]) == 0)
    {
      my_putstrfd("setenv: Variable name must", fd);
      my_putstrnfd(" contain alphanumeric characters.", fd);
      vars->exitval = 1;
      return ;
    }
  vars->cmd = my_strdup(vars->scmd->av[1]);
  vars->cmd = my_strcat(vars->cmd,"=");
  vars->cmd = my_strcat(vars->cmd, vars->scmd->av[2]);
  str_to_env(vars);
}
