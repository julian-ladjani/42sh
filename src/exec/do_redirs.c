/*
** do_redirs.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 10:36:22 2017 Ladjani Julian
** Last update Sat May 20 23:03:25 2017 Ladjani Julian
*/

#include "sh.h"

static int		do_lredir(t_cmdlist *elem)
{
  int			fd;

  if ((fd = open(elem->data->lredirword, O_RDONLY)) <= 0)
    {
      printf("%s: %s.\n", elem->data->lredirword, strerror(errno));
      return (ERROR_RETURN);
    }
  elem->data->std[0] = fd;
  return (SUCCES_RETURN);
}

static int		do_rredir(t_cmdlist *elem)
{
  int			fd;

  if ((fd = open(elem->data->rredirword, O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
    {
      printf("%s: %s.\n", elem->data->rredirword, strerror(errno));
      return (ERROR_RETURN);
    }
  elem->data->std[1] = fd;
  return (SUCCES_RETURN);
}

static int		do_ldredir(t_cmdlist *cmd)
{
  int			fd[2];
  char			*line;
  int			exit;

  exit = 0;
  if (pipe(fd) < 0)
    {
      printf("%s: %s.\n", cmd->data->cmd, strerror(errno));
      return (ERROR_RETURN);
    }
  cmd->data->std[0] = fd[0];
  cmd->data->eofstd = fd[1];
  write(1, "> ", 2);
  while ((line = get_next_line(0, &exit)) != NULL && exit == 0 &&
	 strcmp(line, cmd->data->lredirword) != 0)
    {
      write(1, "> ", 2);
      write(cmd->data->eofstd, line, strlen(line));
      write(cmd->data->eofstd, "\n", 1);
      free(line);
    }
  close(fd[1]);
  return (SUCCES_RETURN);
}

static int		do_rdredir(t_cmdlist *cmd)
{
  int			fd;

  if ((fd = open(cmd->data->rredirword, O_CREAT | O_APPEND | O_WRONLY, 0644)) < 0)
    {
      printf("%s: %s.\n", cmd->data->rredirword, strerror(errno));
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
