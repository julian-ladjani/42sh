/*
** parse_list_pipe.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu May 18 14:15:37 2017 Ladjani Julian
** Last update Fri May 19 02:39:26 2017 Ladjani Julian
*/

#include "sh.h"

static t_cmdlist	*get_next_pipe(t_cmdlist *elem, t_cmdlist *root)
{
  while (elem->data->type != PIPE && elem != root)
    elem = elem->next;
  if (elem == root)
    return (NULL);
  return (elem);
}

static int	        check_pipe(t_cmdlist *elem, t_cmdlist *root)
{
  t_cmdlist		*firstpiped;
  t_cmdlist		*secondpiped;

  firstpiped = elem->prev;
  secondpiped = elem->next;
  if (firstpiped == root || firstpiped->data->type != CMD ||
      secondpiped == root || secondpiped->data->type != CMD)
    {
      printf("%s\n", "Invalid null command.");
      return (ERROR_RETURN);
    }
  if (firstpiped->data->stdtype[1] != NOTHING)
    {
      printf("%s\n", "Ambiguous output redirect.");
      return (ERROR_RETURN);
    }
  if (secondpiped->data->stdtype[0] != NOTHING)
    {
      printf("%s\n", "Ambiguous input redirect.");
      return (ERROR_RETURN);
    }
  return (SUCCES_RETURN);
}

static int		make_pipe(t_cmdlist *elem)
{
  int			pipedfd[2];
  t_cmdlist		*firstpiped;
  t_cmdlist		*secondpiped;

  firstpiped = elem->prev;
  secondpiped = elem->next;
  if (pipe(pipedfd) < 0)
    return (ERROR_RETURN);
  if (firstpiped->data->stdtype[0] == PIPE)
    firstpiped->data->mode = NORMAL;
  else
    firstpiped->data->mode = START;
  secondpiped->data->mode = END;
  firstpiped->data->std[1] = pipedfd[1];
  secondpiped->data->std[0] = pipedfd[0];
  firstpiped->data->stdtype[1] = PIPE;
  secondpiped->data->stdtype[0] = PIPE;
  return (SUCCES_RETURN);
}

int			parse_list_pipe(t_cmdlist *root)
{
  t_cmdlist		*elem;

  while ((elem = get_next_pipe(root->next, root)) != NULL)
    {
      if (check_pipe(elem, root) == ERROR_RETURN)
	return (ERROR_RETURN);
      if (make_pipe(elem) == ERROR_RETURN)
	return (ERROR_RETURN);
      delcmdelem(elem);
    }
  return (SUCCES_RETURN);
}
