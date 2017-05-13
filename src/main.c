/*
** main.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu May 11 12:44:05 2017 Ladjani Julian
** Last update Fri May 12 16:34:43 2017 Ladjani Julian
*/

#include "42sh.h"

void		avoid_signaux()
{
  signal(SIGINT, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
  signal(SIGSTOP, SIG_IGN);
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
}

int		main(int ac, char **av, char **ae)
{
  t_mysh	*mysh;

  (void)ac;
  (void)av;
  if ((mysh = init_prog(ae)) == NULL)
    return (ERROR_RETURN);
  
}
