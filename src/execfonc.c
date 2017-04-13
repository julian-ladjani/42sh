/*
** execfonc.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Mar Jan 24 14:10:52 2017 Julian Ladjani
** Last update Sun Apr  9 17:31:03 2017 Ladjani Julian
*/

#include "minishell.h"

char		*set_my_cmd2(char *cmd, t_mysh *vars)
{
  int		i;

  i = 0;
  while (cmd && cmd[i] != '\0')
    {
      if (cmd[i] == '/')
        return (vars->cmd);
      i++;
    }
  return (NULL);
}

char		*set_my_cmd(char *cmd, t_mysh *vars)
{
  int		i;
  char		*cmd2;
  char		**pathlist;
  t_list	*elem;

  i = 0;
  if (set_my_cmd2(cmd, vars) != NULL)
    return (vars->cmd);
  if ((elem = search_in_list(vars->env, "PATH")) != NULL)
    {
      pathlist = my_str_to_wordtab(elem->envvalue, ':');
      while (pathlist[i] != NULL)
	{
	  cmd2 = set_my_path(pathlist[i], cmd);
	  if (access(cmd2, X_OK) == 0)
	    return (cmd2);
	  i++;
	}
      return (NULL);
    }
  cmd2 = set_my_path("/usr/bin", cmd);
  return (cmd2);
}

char		**arg_to_argv(t_mysh *vars)
{
  char		**argv;
  int		i;

  i = 0;
  while (vars->cmd[i] != ' ' && vars->cmd[i] != '\0')
    {
      if (vars->cmd[i] == '/')
	{
	  vars->cmd = vars->cmd + i;
	  i = 0;
	}
      i++;
    }
  argv = my_str_to_wordtab(vars->cmd, ' ');
  return (argv);
}
