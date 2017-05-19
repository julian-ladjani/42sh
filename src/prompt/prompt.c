/*
** prompt.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/prompt
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed May 17 02:30:41 2017 Ladjani Julian
** Last update Fri May 19 13:57:30 2017 Ladjani Julian
*/

#include "sh.h"

static void	write_prompt(t_mysh *vars)
{
  int		i;

  i = 0;
  if (vars->prompt == NULL || vars->prompt[0] == NULL)
    {
      write(1, "NoPrompt> ", 10);
      return ;
    }
  while (vars->prompt[i] != NULL)
    {
      call_cmd(vars, strdup(vars->prompt[i]));
      i++;
    }
}

int		my_prompt(t_mysh *vars)
{
  char		*cmd;

  while (vars->exit == 0)
    {
      write_prompt(vars);
      cmd = get_next_line(0, &vars->exit);
      if (cmd != NULL && vars->exit == 0)
	call_cmd(vars, cmd);
      clean_cmdlist(vars->cmd);
    }
  return (vars->exitval);
}
