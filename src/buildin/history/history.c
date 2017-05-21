/*
** history.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/history
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 14:05:18 2017 Ladjani Julian
** Last update Sun May 21 22:13:42 2017 Ladjani Julian
*/

#include "sh.h"

int	history_main(t_mysh *vars, t_cmdlist *cmd)
{
  int	i;

  i = 0;
  while (vars->history[i] != NULL)
    {
      dprintf(cmd->data->std[1], "%d: %s\n", i, vars->history[i]);
      i++;
    }
  return (SUCCES_RETURN);
}
