/*
** main.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Tue Jan 10 16:19:36 2017 julian ladjani
** Last update Sun Apr  9 17:24:47 2017 Ladjani Julian
*/

#include "minishell.h"

t_mysh		*init_my_vars()
{
  t_mysh	*vars;

  if ((vars = malloc(sizeof(*vars))) == NULL)
    exit(84);
  vars->exitval = 0;
  vars->exit = 0;
  vars->pid = getpid();
  vars->childpid = 0;
  vars->cmd = NULL;
  vars->childreturn = 0;
  vars->childstatus = 0;
  if ((vars->scmd = malloc(sizeof(*vars->scmd))) == NULL)
    exit(84);
  vars->env = list_create();
  return (vars);
}

void		init_my_env(t_mysh *vars, char **ae)
{
  int		i;
  t_list	*elem;
  char		**tab;

  i = 0;
  while (ae[i] != NULL)
    {
      tab = my_str_to_wordtab(ae[i], '=');
      addelem_before(vars->env);
      elem = vars->env->prev;
      if (tab != NULL && tab[0] != NULL)
	{
	  elem->envkey = tab[0];
	  elem->env = my_strdup(ae[i]);
	}
      if (tab != NULL && tab[0] != NULL && tab[1] != NULL)
	elem->envvalue = tab[1];
      i++;
    }
}

void		avoid_signal_yep()
{
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGSTOP, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
}

int		main(int ac, char **av, char **ae)
{
  t_mysh	*vars;

  (void)av;
  (void)ac;
  avoid_signal_yep();
  vars = init_my_vars();
  init_my_env(vars, ae);
  prompt(vars);
  if (vars->exit == 2)
    {
      my_putstr("\n");
      return (vars->exitval);
    }
  write(1, "exit\n", 5);
  return (vars->exitval);
}
