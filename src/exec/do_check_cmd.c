/*
** do_check_cmd.c for 42sg in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 04:20:23 2017 Ladjani Julian
** Last update Tue Jun  6 19:46:43 2017 Ladjani Julian
*/

#include "sh.h"

int		check_my_cmd(t_mysh *vars, t_cmdlist *elem)
{
  if (elem->data->cmdtype == EXEC)
    elem->data->cmd = set_my_cmd_path(vars, elem);
  if (elem->data->cmd == NULL)
    {
      dprintf(1, "%s: Command not found.\n", elem->data->av[0]);
      return (ERROR_RETURN);
    }
  if ((elem->data->ae = env_to_tabenv(vars->env)) == NULL)
    return (ERROR_RETURN);
  return (SUCCES_RETURN);
}
