/*
** cd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 13:31:19 2017 Ladjani Julian
** Last update Tue May  9 21:44:08 2017 Ladjani Julian
*/

#include "42sh.h"

int		cd_main(t_mysh *vars)
{
  t_cmddata	*cmd;
  int		returnvalue;

  returnvalue = 0;
  cmd = vars->cmd->data;
  if (my_tablen(cmd->av) < 2)
    returnvalue = my_cd_no_args(vars, cmd);
  else if (my_tablen(cmd->av) > 1 && strncmp(cmd->av[1], "-", 1) == 0)
    returnvalue = my_cd_back(vars, cmd);
  else
    returnvalue = my_cd(vars, cmd);
  return (returnvalue);
}
