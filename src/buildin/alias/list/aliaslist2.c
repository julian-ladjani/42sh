/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Wed May 17 11:18:52 2017 Ladjani Julian
*/

#include "sh.h"

void		addaliaselem_first(t_aliaslist *root)
{
  addaliaselem_after(root);
}

void		addaliaselem_last(t_aliaslist *root)
{
  addaliaselem_before(root);
}

void		delaliaselem_first(t_aliaslist *root)
{
  if (root->next != root)
    delaliaselem(root->next);
}

void		delaliaselem_last(t_aliaslist *root)
{
  if (root->prev != root)
    delaliaselem(root->prev);
}

void		delaliaselem(t_aliaslist *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
