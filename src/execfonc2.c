/*
** execfonc2.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun Apr  9 03:03:59 2017 Ladjani Julian
** Last update Sun Apr  9 03:04:25 2017 Ladjani Julian
*/

#include "minishell.h"

char	**str_to_av(t_mysh *vars)
{
  char	**av;

  av = my_str_to_wordtab(vars->cmd, ' ');
  return (av);
}

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
        my_putstrn("Segmentation fault (core dumped)");
      else if (WTERMSIG(vars->childstatus) == SIGSEGV)
	my_putstrn("Segmentation fault");
      else if (WTERMSIG(vars->childstatus) == SIGFPE &&
          WCOREDUMP(vars->childstatus))
        my_putstrn("Floating exception (core dumped)");
      else if (WTERMSIG(vars->childstatus) == SIGFPE)
        my_putstrn("Floating exception");
    }
}
