/*
** parse_list_redirs.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun May 21 00:00:52 2017 Ladjani Julian
** Last update Sun May 21 00:00:53 2017 Ladjani Julian
*/

#include "sh.h"

static t_cmdlist	*get_next_redir(t_cmdlist *elem, t_cmdlist *root)
{
  while (elem->data->type != LREDIR &&
	 elem->data->type != RREDIR &&
	 elem->data->type != LDREDIR &&
	 elem->data->type != RDREDIR && elem != root)
    elem = elem->next;
  if (elem == root)
    return (NULL);
  return (elem);
}

static int		check_input_redir(t_cmdlist *elem,
					  t_cmdlist *root)
{
  if (elem->prev->data->type == CMD)
    elem = elem->prev;
  while (elem->data->type != CMD && elem != root &&
	 elem->data->type != PIPE &&
        elem->data->type != AND && elem->data->type != OR &&
	 elem->data->type != SEP &&
	 elem->data->type != LREDIR && elem->data->type != LDREDIR)
    elem = elem->next;
  if (elem->data->type != CMD && elem->data->type != LREDIR &&
      elem->data->type != LDREDIR)
    {
      printf("%s\n", "Invalid null command.");
      return (ERROR_RETURN);
    }
  if (elem->data->stdtype[0] != NOTHING || elem->data->type == LREDIR
      || elem->data->type == LDREDIR)
    {
      printf("%s\n", "Ambiguous input redirect.");
      return (ERROR_RETURN);
    }
  return (SUCCES_RETURN);
}

static int		check_output_redir(t_cmdlist *elem,
					   t_cmdlist *root)
{
  if (elem->prev->data->type == CMD)
    elem = elem->prev;
  while (elem->data->type != CMD && elem != root &&
	 elem->data->type != PIPE &&
        elem->data->type != AND && elem->data->type != OR &&
	 elem->data->type != SEP &&
	 elem->data->type != RREDIR && elem->data->type != RDREDIR)
    elem = elem->next;
  if (elem->data->type != CMD && elem->data->type != RREDIR &&
      elem->data->type != RDREDIR)
    {
      printf("%s\n", "Invalid null command.");
      return (ERROR_RETURN);
    }
  if (elem->data->stdtype[1] != NOTHING || elem->data->type == RREDIR
      || elem->data->type == RDREDIR)
    {
      printf("%s\n", "Ambiguous output redirect.");
      return (ERROR_RETURN);
    }
  return (SUCCES_RETURN);
}

int			parse_list_redir(t_cmdlist *root)
{
  t_cmdlist             *elem;

  while ((elem = get_next_redir(root->next, root)) != NULL)
    {
      if (elem->data->type == RREDIR || elem->data->type == RDREDIR)
	if (check_output_redir(elem, root) == ERROR_RETURN)
	  return (ERROR_RETURN);
      if (elem->data->type == LREDIR || elem->data->type == LDREDIR)
        if (check_input_redir(elem, root) == ERROR_RETURN)
          return (ERROR_RETURN);
      if (make_redir(elem, root) == ERROR_RETURN)
        return (ERROR_RETURN);
      delcmdelem(elem);
    }
  return (SUCCES_RETURN);
}
