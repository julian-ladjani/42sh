/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Tue May  9 15:52:32 2017 Ladjani Julian
*/

#include "minishell.h"

t_list		*cdlist_create()
{
  t_cdlist	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->path = NULL;
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void		clean_cdlist(t_cdlist *list)
{
  while (list->next != NULL && list->next->first == 1)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
}

void		delete_cdlist(t_cdlist *list)
{
  clean_list(list);
  free(list);
}

void		addcdelem_before(t_cdlist *elem)
{
  t_cdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->path = NULL;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
    }
}

void		addcdelem_after(t_cdlist *elem)
{
  t_cdlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->path = NULL;
      new_elem->next = elem->next;
      new_elem->prev = elem;
      elem->next->prev = new_elem;
      elem->next = new_elem;
    }
}
