/*
** parse_list_sep.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/exec
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 11:02:53 2017 Ladjani Julian
** Last update Fri May 19 14:10:47 2017 Ladjani Julian
*/

#include "sh.h"

static t_cmdlist	*get_next_sep(t_cmdlist *elem, t_cmdlist *root)
{
  while (elem->data->type != SEP &&
         elem->data->type != OR &&
         elem->data->type != AND && elem != root)
    elem = elem->next;
  if (elem == root)
    return (NULL);
  return (elem);
}

static int	check_sep(t_cmdlist *elem, t_cmdlist *root)
{
  t_type	prevtype;
  t_type	nexttype;

  if (elem->prev == root || elem->next == root)
    {
      printf("%s\n", "Invalid null command.");
      return (ERROR_RETURN);
    }
  prevtype = elem->prev->data->type;
  nexttype = elem->next->data->type;
  if (prevtype == SEP || prevtype == OR || prevtype == AND ||
      nexttype == SEP || nexttype == OR || nexttype == AND)
    {
      printf("%s\n", "Invalid null command.");
      return (ERROR_RETURN);
    }
  return (SUCCES_RETURN);
}

int		parse_list_sep(t_cmdlist *root)
{
  t_cmdlist	*elem;

  elem = root;
  while ((elem = get_next_sep(elem->next, root)) != NULL)
    {
      if (check_sep(elem, root) == ERROR_RETURN)
	return (ERROR_RETURN);
    }
  return (SUCCES_RETURN);
}
