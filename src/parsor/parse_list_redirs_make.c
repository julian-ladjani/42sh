/*
** parse_list_redirs_make.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 00:26:08 2017 Ladjani Julian
** Last update Fri May 19 02:38:36 2017 Ladjani Julian
*/

#include "sh.h"

static int		make_lredir(t_cmdlist *elem,
				    t_cmdlist *redirelem)
{
  redirelem->data->stdtype[0] = LREDIR;
  redirelem->data->lredirword = strdup(elem->data->cmd);
  return (SUCCES_RETURN);
}

static int		make_rredir(t_cmdlist *elem,
				    t_cmdlist *redirelem)
{
  redirelem->data->stdtype[1] = RREDIR;
  redirelem->data->rredirword = strdup(elem->data->cmd);
  return (SUCCES_RETURN);
}

static int		make_ldredir(t_cmdlist *elem,
				     t_cmdlist *redirelem)
{
  redirelem->data->stdtype[0] = LDREDIR;
  redirelem->data->lredirword = strdup(elem->data->cmd);
  return (SUCCES_RETURN);
}

static int		make_rdredir(t_cmdlist *elem,
				     t_cmdlist *redirelem)
{
  redirelem->data->stdtype[1] = RDREDIR;
  redirelem->data->rredirword = strdup(elem->data->cmd);
  return (SUCCES_RETURN);
}

int			make_redir(t_cmdlist *elem, t_cmdlist *root)
{
  t_cmdlist		*redirelem;

  if (elem->prev->data->type == CMD)
    redirelem = elem->prev;
  else
    redirelem = elem;
  while (redirelem->data->type != CMD && redirelem != root)
    redirelem = redirelem->next;
  if (redirelem->data->type == LREDIR)
    return (make_lredir(elem, redirelem));
  if (redirelem->data->type == RREDIR)
    return (make_rredir(elem, redirelem));
  if (redirelem->data->type == LDREDIR)
    return (make_ldredir(elem, redirelem));
  if (redirelem->data->type == RDREDIR)
    return (make_rdredir(elem, redirelem));
  return (ERROR_RETURN);
}
