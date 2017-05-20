/*
** do_redirs.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 10:36:22 2017 Ladjani Julian
** Last update Sat May 20 15:00:24 2017 Ladjani Julian
*/

#include "sh.h"

static int		do_lredir(t_cmdlist *elem)
{
  int			fd;

  if ((fd = open(elem->data->cmd, O_RDONLY)) < 0)
    {
      return (ERROR_RETURN);
    }
  elem->data->std[0] = fd;
  return (SUCCES_RETURN);
}

static int		do_rredir(t_cmdlist *elem)
{
  int			fd;

  if ((fd = open(elem->data->cmd, O_CREAT | O_RDWR | O_TRUNC)) < 0)
    {
      return (ERROR_RETURN);
    }
  elem->data->std[1] = fd;
  return (SUCCES_RETURN);
}

static int		do_ldredir(t_cmdlist *cmd)
{
  int			fd[2];

  if (pipe(fd) < 0)
    return (ERROR_RETURN);
  cmd->data->std[0] = fd[0];
  cmd->data->eofstd = fd[1];
  return (ERROR_RETURN);
}

static int		do_rdredir(t_cmdlist *cmd)
{
  int			fd;

  if ((fd = open(cmd->data->cmd, O_CREAT | O_RDWR | O_APPEND)) < 0)
    {
      return (ERROR_RETURN);
    }
  cmd->data->std[1] = fd;
  return (SUCCES_RETURN);
}

int			do_redir(t_cmdlist *cmd)
{
  if (cmd->data->stdtype[1] == RREDIR)
    return (do_rredir(cmd));
  if (cmd->data->stdtype[0] == LREDIR)
    return (do_lredir(cmd));
  if (cmd->data->stdtype[1] == RDREDIR)
    return (do_rdredir(cmd));
  if (cmd->data->stdtype[0] == LDREDIR)
    return (do_ldredir(cmd));
  return (ERROR_RETURN);
}
