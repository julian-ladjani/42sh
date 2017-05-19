/*
** return_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/exec
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 12:37:25 2017 Ladjani Julian
** Last update Fri May 19 12:41:42 2017 Ladjani Julian
*/

#include "sh.h"

void	my_return_wait(t_mysh *vars)
{
  if (WIFEXITED(vars->childstatus))
    {
      vars->childreturn = WEXITSTATUS(vars->childstatus);
      vars->exitval = WEXITSTATUS(vars->childstatus);
    }
  else if (WIFSIGNALED(vars->childstatus))
    {
      if (WTERMSIG(vars->childstatus) == SIGSEGV)
        vars->exitval = 139;
      else if (WTERMSIG(vars->childstatus) == SIGFPE)
        vars->exitval = 136;
      if (WTERMSIG(vars->childstatus) == SIGSEGV &&
          WCOREDUMP(vars->childstatus))
	printf("Segmentation fault (core dumped)\n");
      else if (WTERMSIG(vars->childstatus) == SIGSEGV)
        my_putstrn("Segmentation fault");
      else if (WTERMSIG(vars->childstatus) == SIGFPE &&
          WCOREDUMP(vars->childstatus))
        printf("Floating exception (core dumped)\n");
      else if (WTERMSIG(vars->childstatus) == SIGFPE)
        printf("Floating exception\n");
    }
}
