/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Fri May 19 14:01:04 2017 Ladjani Julian
*/

#include "sh.h"

t_cmddata	*init_my_cmddata()
{
  t_cmddata	*data;

  if (((data = malloc(sizeof(*data))) != NULL))
    {
      data->mode = NORMAL;
      data->type = NOTHING;
      data->std[0] = STDIN_FILENO;
      data->std[1] = STDOUT_FILENO;
      data->stdtype[0] = NOTHING;
      data->stdtype[1] = NOTHING;
      data->cmd = NULL;
      data->av = NULL;
      data->ae = NULL;
      return (data);
    }
  return (NULL);
}

t_cmdlist	*cmdlist_create()
{
  t_cmdlist	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->data = init_my_cmddata();
      root->data->cmd = strdup("ROOT");
      root->prev = root;
      root->next = root;
      return (root);
    }
  return (NULL);
}

void		clean_cmdlist(t_cmdlist *list)
{
  list->next = list;
  list->prev = list;
}

t_cmdlist	*addcmdelem_before(t_cmdlist *elem)
{
  t_cmdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      if ((new_elem->data = init_my_cmddata()) == NULL)
	return (NULL);
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
      return (new_elem);
    }
  return (NULL);
}

t_cmdlist	*addcmdelem_after(t_cmdlist *elem)
{
  t_cmdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      if ((new_elem->data = init_my_cmddata()) == NULL)
        return (NULL);
      new_elem->next = elem->next;
      new_elem->prev = elem;
      elem->next->prev = new_elem;
      elem->next = new_elem;
      return (new_elem);
    }
  return (NULL);
}
