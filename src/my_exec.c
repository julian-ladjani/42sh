/*
** my_exec.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src/liste
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Jan 22 21:07:02 2017 Julian Ladjani
** Last update Sun Apr  9 16:04:01 2017 Ladjani Julian
*/

#include "minishell.h"

void	my_exec2(t_mysh *vars)
{
  if (vars->scmd->cmdtype != EXEC)
    {
      my_builtin(vars, 1);
      return ;
    }
  vars->childpid = fork();
  if (vars->childpid == 0)
    {
      execve(vars->scmd->cmd, vars->scmd->av, vars->scmd->ae);
      my_putexecerror(vars);
    }
  else
    {
      wait(&vars->childstatus);
      my_return_wait(vars);
    }
}

void	my_pipe_dup(t_mysh *vars, int *fdin, int type)
{
  if (type == 1)
    {
      if (vars->scmd->mode != START)
	dup2(*fdin, 0);
      if (vars->scmd->mode != END)
	{
	  dup2(vars->scmd->fd[1], 1);
	  close(vars->scmd->fd[0]);
	}
    }
  else if (type == 2)
    {
      close(vars->scmd->fd[1]);
      *fdin = vars->scmd->fd[0];
    }
}

void	my_execpipe2(t_mysh *vars, int *fdin)
{
  if (vars->scmd->cmdtype != EXEC)
    {
      if (vars->scmd->mode != END)
	my_builtin(vars, vars->scmd->fd[1]);
      else
	my_builtin(vars, 1);
      close(vars->scmd->fd[1]);
      *fdin = vars->scmd->fd[0];
      return ;
    }
  vars->childpid = fork();
  if (vars->childpid == 0)
    {
      my_pipe_dup(vars, fdin, 1);
      execve(vars->scmd->cmd, vars->scmd->av, vars->scmd->ae);
      my_putexecerror(vars);
    }
  else
    {
      waitpid(vars->childpid, &vars->childstatus, 0);
      my_pipe_dup(vars, fdin, 2);
      my_return_wait(vars);
    }
}

void	my_execpipe(t_mysh *vars)
{
  char	**tab;
  int	fdin;
  int	i;

  i = 0;
  fdin = 0;
  tab = my_str_to_wordtab(vars->cmd, PIPE_CHAR);
  if (vars->cmd[0] == '|' || my_tablen(tab) < 2)
    {
      my_putstrn("Invalid null command.");
      return ;
    }
  while (tab[i] != NULL)
    {
      if (pre_my_cmd(vars, PIPE, tab[i]) != 84)
	{
	  my_pipetype(vars, tab, &fdin, i);
	  i++;
	}
      else
	tab++;
    }
}

void	my_exec(t_mysh *vars)
{
  if (match(vars->cmd, "*|*") > 0)
    my_execpipe(vars);
  else
    {
      if (pre_my_cmd(vars , NOTHING, vars->cmd) == 84)
	return ;
      my_exec2(vars);
    }
}
