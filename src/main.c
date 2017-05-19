/*
** main.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu May 11 12:44:05 2017 Ladjani Julian
** Last update Fri May 19 13:40:14 2017 Ladjani Julian
*/

#include "sh.h"

void		avoid_signaux()
{
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGSTOP, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
}

static void	my_input_cmd(t_mysh *vars)
{
  int		exit;
  char		*cmd;
  int		i;
  int		flag;

  exit = 0;
  i = 0;
  flag = fcntl(0, F_GETFL, 0 );
  fcntl(0, F_SETFL, flag | O_NONBLOCK);
  tcgetattr(STDIN_FILENO, &vars->oldt);
  vars->newt = vars->oldt;
  vars->newt.c_lflag &= ~(ICANON | ECHO);
  while ((cmd = get_next_line(0, &exit)) != NULL && exit == 0)
    {
      call_cmd(vars, cmd);
      i++;
    }
  fcntl(0, F_SETFL, flag);
  if (i != 0)
    _exit(vars->exitval);
}

int		main(int ac, char **av, char **ae)
{
  t_mysh	*mysh;

  (void)ac;
  (void)av;
  if ((mysh = init_prog(ae)) == NULL)
    return (ERROR_RETURN);
  my_input_cmd(mysh);
  return (my_prompt(mysh));
}
