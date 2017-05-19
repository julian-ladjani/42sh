/*
** do_redirs.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 10:36:22 2017 Ladjani Julian
** Last update Fri May 19 10:44:34 2017 Ladjani Julian
*/

#include "sh.h"

static int              make_lredir(t_cmdlist *elem)
{
  int                   fd;

  if ((fd = open(elem->data->cmd, O_RDONLY)) < 0)
    {
      return (RETURN_ERROR);
    }
  elem->std[0] = fd;
  return (SUCCES_RETURN);
}

static int		do_rredir(t_cmdlist *elem,
				    t_cmdlist *root,
				    t_cmdlist *redirelem)
{
  int			fd;

  if ((fd = open(elem->data->cmd, O_CREAT | O_RDWR | O_TRUNC)) < 0)
    return (RETURN_ERROR);
  elem->std[1] = fd;
  return (SUCCES_RETURN);
}

static int		do_ldredir(t_cmdlist *cmd)
{
  int			fd[2];

  if (pipe(fd) < 0)
    return (ERROR_RETURN);
  cmd->data->std[0] = fd[0];
  cmd->data->eofstd = fd[1];
}

static int		do_rdredir(t_cmdlist *cmd)
{
  int			fd;

  if ((fd = open(elem->data->cmd, O_CREAT | O_RDWR | O_APPEND)) < 0)
    return (RETURN_ERROR);
  return (SUCCES_RETURN);
}

int			do_redir(t_cmdlist *cmd)
{
  if (cmd->data->type == RREDIR)
    return (do_rredir(cmd));
  if (cmd->data->type == LREDIR)
    return (do_lredir(cmd));
  if (cmd->data->type == RDREDIR)
    return (do_rdredir(cmd));
  if (cmd->data->type == LDREDIR)
    return (do_ldredir(cmd));
  return (ERROR_RETURN);
}
