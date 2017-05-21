/*
** cd_dir.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/cd
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 21:45:42 2017 Ladjani Julian
** Last update Sun May 21 19:58:27 2017 Ladjani Julian
*/

#include "sh.h"

int		my_cd(t_mysh *vars, t_cmdlist *cmd)
{
  return (my_chdir(cmd->data->av[1], vars));
}
