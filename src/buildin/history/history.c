/*
** history.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/history
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 14:05:18 2017 Ladjani Julian
** Last update Sat May 20 14:06:39 2017 Ladjani Julian
*/

#include "sh.h"

int	history_main(t_mysh *vars)
{
  int	i;

  while (vars->history[i] != NULL)
    {
      printf("%s\n", vars->history[i]);
      i++;
    }
  return (SUCCES_RETURN);
}
