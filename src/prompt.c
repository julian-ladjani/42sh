/*
** prompt.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Mon Jan 16 19:24:29 2017 julian ladjani
** Last update Sun Apr  9 22:23:04 2017 Ladjani Julian
*/

#include "minishell.h"

void	write_my_prompt(t_mysh *vars)
{
  t_list	*elem;
  char		**tab;
  int		i;

  i = 0;
  my_putstr("\e[1;36m");
  if ((elem = search_in_list(vars->env, "PWD\0")) != NULL)
    {
      my_putstr("\e[1;33m➜  \e[1;36m");
      tab = my_str_to_wordtab(elem->envvalue, '/');
      while (tab[i] != NULL)
	i++;
      my_putstr(tab[i - 1]);
      write(1, " ", 1);
    }
  write(1, "?> ", 3);
  my_putstr("\e[0m");
}

void	prompt_loop(t_mysh *vars)
{
  if (vars->cmd[0] == ' ')
    vars->cmd++;
  my_exec(vars);
}

void	prompt(t_mysh *vars)
{
  char	*cmd;
  char	**cmdtab;
  int	i;

  i = 0;
  while (vars->exit == 0)
    {
      cmd = NULL;
      write_my_prompt(vars);
      while ((cmd = get_next_line(0, &vars->exit)) == NULL && vars->exit == 0);
      if (vars->exit == 0)
	{
	  cmd = epur_str(cmd);
	  cmdtab = my_str_to_wordtab(cmd, SEP_CHAR);
	  while (cmdtab[i] != NULL)
	    {
	      vars->cmd = cmdtab[i];
	      prompt_loop(vars);
	      i++;
	    }
	  i = 0;
	}
    }
}
