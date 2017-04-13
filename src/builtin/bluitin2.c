/*
** bluitin2.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri Apr  7 22:43:10 2017 Ladjani Julian
** Last update Sun Apr  9 14:06:02 2017 Ladjani Julian
*/

#include "minishell.h"

void		my_cd_env(t_mysh *vars, int fd)
{
  t_list	*pwd;
  char		*spwd;

  (void)fd;
  if ((pwd = search_in_list(vars->env, "PWD\0")) != NULL)
    spwd = my_strdup(pwd->envvalue);
  vars->cmd = my_strdup("PWD");
  vars->cmd = my_strcat(vars->cmd, "=\0");
  vars->cmd = my_strcat(vars->cmd, getcwd(NULL, 0));
  str_to_env(vars);
  vars->cmd = my_strdup("OLDPWD");
  vars->cmd = my_strcat(vars->cmd,"=");
  if (pwd != NULL)
    vars->cmd = my_strcat(vars->cmd, spwd);
  else
    vars->cmd = my_strcat(vars->cmd, getcwd(NULL, 0));
  str_to_env(vars);
}

void            my_cd_home(t_mysh *vars, int fd)
{
  t_list        *pwd;
  char          *spwd;

  if ((pwd = search_in_list(vars->env, "HOME\0")) != NULL)
    spwd = my_strdup(pwd->envvalue);
  else if ((pwd = search_in_list(vars->env, "PWD\0")) != NULL)
    spwd = my_strdup(pwd->envvalue);
  else
    spwd = my_strdup(getcwd(NULL, 0));
  if (chdir(spwd) < 0)
    {
      my_cd_error(vars->scmd->av[1], fd);
      return ;
    }
  my_cd_env(vars, fd);
}

void		my_cd_error(char *str, int fd)
{
  my_putstrfd(str, fd);
  my_putstrfd(": ", fd);
  my_putstrfd(strerror(errno), fd);
  my_putstrnfd(".", fd);
  return ;
}
