/*
** exec_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/exec
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 12:51:41 2017 Ladjani Julian
** Last update Sat May 20 17:50:47 2017 Ladjani Julian
*/

#include "sh.h"

static void	my_return_wait(t_mysh *vars, t_cmdlist *cmd)
{
  if (WIFEXITED(cmd->data->status))
    {
      cmd->data->status = WEXITSTATUS(cmd->data->status);
      cmd->data->exitval = WEXITSTATUS(cmd->data->status);
    }
  else if (WIFSIGNALED(cmd->data->status))
    {
      if (WTERMSIG(cmd->data->status) == SIGSEGV)
        cmd->data->exitval = 139;
      else if (WTERMSIG(cmd->data->status) == SIGFPE)
        cmd->data->exitval = 136;
      if (WTERMSIG(cmd->data->status) == SIGSEGV &&
          WCOREDUMP(cmd->data->status))
        printf("Segmentation fault (core dumped)\n");
      else if (WTERMSIG(cmd->data->status) == SIGSEGV)
        printf("Segmentation fault\n");
      else if (WTERMSIG(cmd->data->status) == SIGFPE &&
	       WCOREDUMP(cmd->data->status))
        printf("Floating exception (core dumped)\n");
      else if (WTERMSIG(cmd->data->status) == SIGFPE)
        printf("Floating exception\n");
    }
}

static void	my_putexecerror(t_mysh *vars, t_cmdlist *cmd)
{
  printf("%s: ", cmd->data->av[0]);
  if (strcmp(strerror(errno), "Exec format error") == 0)
    printf("Exec format error. Binary file not executable.\n");
  else
    printf("%s.\n", strerror(errno));
  cmd->data->exitval = 1;
  exit(cmd->data->exitval);
}

static void	my_exec(t_mysh *vars, t_cmdlist *cmd)
{
  int		childpid;

  childpid = fork();
  if (childpid == 0)
    {
      if (cmd->data->stdtype[0] != NOTHING)
	dup2(cmd->data->std[0], 0);
      if (cmd->data->stdtype[1] != NOTHING)
	dup2(cmd->data->std[1], 1);
      if (cmd->data->cmdtype == EXEC)
	execve(cmd->data->cmd, cmd->data->av, cmd->data->ae);
      else
	exec_buildin(vars, cmd);
      my_putexecerror(vars, cmd);
    }
  else
    {
      if (cmd->data->stdtype[0] == BROCKENPIPE)
	write(cmd->data->std[0], "\0", 1);
      if (cmd->data->stdtype[1] == PIPE)
	close(cmd->data->std[1]);
      if ((cmd->data->stdtype[0] == PIPE || cmd->data->stdtype[1] == PIPE) &&
	  cmd->data->mode != END)
	waitpid(childpid, &cmd->data->status, WNOHANG);
      else
        waitpid(childpid, &cmd->data->status, 0);
      my_return_wait(vars, cmd);
    }
}

int		do_execution(t_mysh *vars, t_cmdlist *cmd)
{
  if ((cmd->data->exitval = check_my_cmd(vars, cmd)) == ERROR_RETURN)
    return (ERROR_RETURN);
  my_exec(vars, cmd);
  return (cmd->data->exitval);
}
