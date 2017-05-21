/*
** exit_prog.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun May 21 21:06:49 2017 Ladjani Julian
** Last update Sun May 21 21:58:28 2017 Ladjani Julian
*/

#include "sh.h"

void	exit_my_sh(t_mysh *vars)
{
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(HISTORY_FILE, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
    return ;
  while (vars->history[i] != NULL)
    {
      write(fd, vars->history[i], strlen(vars->history[i]));
      write(fd, "\n", 1);
      i++;
    }
}
