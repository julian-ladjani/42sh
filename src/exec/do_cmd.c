/*
** do_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/exec
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 10:53:47 2017 Ladjani Julian
** Last update Fri May 19 10:55:45 2017 Ladjani Julian
*/

#include "sh.h"

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

char            *set_my_cmd(t_mysh *vars)
{
  int           i;
  char          *cmd2;
  char          **pathlist;
  t_list        *elem;

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

char    **str_to_av(t_mysh *vars)
{
  char  **av;

  av = my_str_to_wordtab(vars->cmd, ' ');
  return (av);
}

void    my_return_wait(t_mysh *vars)
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
