/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Fri May 12 23:05:58 2017 Ladjani Julian
*/

#include "42sh.h"

t_list		*cmdlist_create()
{
  t_cmdlist	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void		clean_cmdlist(t_cmdlist *list)
{
  while (list->next != NULL && list->next->first == 1)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
}

void		delete_cmdlist(t_cmdlist *list)
{
  clean_cmdlist(list);
  free(list);
}

t_cmdlist	*addcmdelem_before(t_cmdlist *elem)
{
  t_cmdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->path = NULL;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
      return (new_elem);
    }
  return (NULL);
}

t_cmdlist	*addcmdelem_after(t_cdlist *elem)
{
  t_cdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->path = NULL;
      new_elem->next = elem->next;
      new_elem->prev = elem;
      elem->next->prev = new_elem;
      elem->next = new_elem;
      return (new_elem);
    }
  return (NULL);
}
