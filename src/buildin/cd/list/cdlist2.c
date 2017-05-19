/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Mon May 15 23:59:25 2017 Ladjani Julian
*/

#include "sh.h"

void		addcdelem_first(t_cdlist *root)
{
  addcdelem_after(root);
}

void		addcdelem_last(t_cdlist *root)
{
  addcdelem_before(root);
}

void		delcdelem_first(t_cdlist *root)
{
  if (root->next != root)
    delcdelem(root->next);
}

void		delcdelem_last(t_cdlist *root)
{
  if (root->prev != root)
    delcdelem(root->prev);
}

void		delcdelem(t_cdlist *elem)
{
  if (elem->path != NULL)
    free(elem->path);
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
