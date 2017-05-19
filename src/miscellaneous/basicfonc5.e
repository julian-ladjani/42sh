/*
** basicfonc5.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun Apr  9 12:11:27 2017 Ladjani Julian
** Last update Wed May 17 11:11:35 2017 Ladjani Julian
*/

#include "minishell.h"

void	my_putexecerror(t_mysh *vars)
{
  my_putstr(vars->cmd);
  write(1, ": ", 2);
  if (my_strcmp(strerror(errno), "Exec format error") == 0)
    my_putstr("Exec format error. Binary file not executable");
  else
    my_putstr(strerror(errno));
  write(1, ".\n", 2);
  exit(1);
}
