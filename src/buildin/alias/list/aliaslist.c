/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Sat May 13 15:11:01 2017 Ladjani Julian
*/

#include "42h.h"

t_aliaslist	*aliaslist_create()
{
  t_aliaslist	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->aliaskey = NULL;
      root->aliasvalue = NULL;
      root->first = 1;
      root->prev = root;
      root->next = root;
      return (root);
    }
  return (NULL);
}

void		clean_aliaslist(t_aliaslist *list)
{
  while (list->next != NULL && list->next->first == 1)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
}

void		delete_aliaslist(t_aliaslist *list)
{
  clean_cdlist(list);
  free(list);
}

t_aliaslist	*addaliaselem_before(t_aliaslist *elem)
{
  t_aliaslist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->aliaskey = NULL;
      new_elem->aliasvalue = NULL;
      new_elem->first = 0;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
      return (new_elem);
    }
  return (NULL);
}

t_aliaslist	addaliaselem_after(t_aliaslist *elem)
{
  t_aliaslist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->aliaskey = NULL;
      new_elem->aliasvalue = NULL;
      new_elem->first = 0;
      new_elem->next = elem->next;
      new_elem->prev = elem;
      elem->next->prev = new_elem;
      elem->next = new_elem;
      return (new_elem);
    }
  return (NULL);
}
