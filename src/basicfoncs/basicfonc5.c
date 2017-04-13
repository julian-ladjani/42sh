/*
** basicfonc5.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun Apr  9 12:11:27 2017 Ladjani Julian
** Last update Sun Apr  9 19:41:07 2017 Ladjani Julian
*/

#include "minishell.h"

void	my_putexecerror(t_mysh *vars)
{
  my_putstr(vars->cmd);
  write(1, ": ", 2);
  if (my_strcmp(strerror(errno), "Exec format error") == 0)
    my_putstr("Exec format error. Binary file not executable");
  else
    my_putstr(strerror(errno));
  write(1, ".\n", 2);
  exit(1);
}

void	search_my_builtin(t_mysh *vars)
{
  vars->scmd->cmdtype = EXEC;
  if (my_strcmp(vars->scmd->av[0], "exit") == 0)
    vars->scmd->cmdtype = EXIT;
  else if (my_strcmp(vars->scmd->av[0], "cd") == 0)
    vars->scmd->cmdtype = CD;
  else if (my_strcmp(vars->scmd->av[0], "unsetenv") == 0)
    vars->scmd->cmdtype = UNSETENV;
  else if (my_strcmp(vars->scmd->av[0], "setenv") == 0)
    vars->scmd->cmdtype = SETENV;
  else if (my_strcmp(vars->scmd->av[0], "env") == 0)
    vars->scmd->cmdtype = ENV;
  if (vars->scmd->cmdtype != EXEC)
    vars->scmd->cmd = vars->scmd->av[0];
}

void	my_pipetype(t_mysh *vars, char **tab, int *fdin, int i)
{
  if (i == 0)
    vars->scmd->mode = START;
  else if (tab[i + 1] == NULL)
    vars->scmd->mode = END;
  else
    vars->scmd->mode = NORMAL;
  my_execpipe2(vars, fdin);
}

int	pre_my_cmd(t_mysh *vars, t_type type, char *cmd)
{
  vars->scmd->av = my_str_to_wordtab(cmd, ' ');
  vars->cmd = vars->scmd->av[0];
  search_my_builtin(vars);
  if (vars->scmd->cmdtype == EXEC)
    vars->scmd->cmd = set_my_cmd(vars->scmd->av[0], vars);
  vars->scmd->ae = env_to_tabenv(vars->env);
  if (vars->scmd->cmd == NULL)
    {
      my_putstr(vars->scmd->av[0]);
      write(1, ": ", 2);
      my_putstrn("Command not found.");
      vars->exitval = 1;
      return (84);
    }
  if (type == PIPE)
    {
      vars->scmd->type = PIPE;
      pipe(vars->scmd->fd);
    }
  return (0);
}
