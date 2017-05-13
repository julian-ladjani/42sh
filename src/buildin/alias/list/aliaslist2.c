/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Sat May 13 04:02:40 2017 Ladjani Julian
*/

#include "minishell.h"

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

void		delcdelem_last(t_aliaslist *root)
{
  if (root->prev != root)
    delaliaselem(root->prev);
}

void		delcdelem(t_aliaslist *elem)
{
  if (elem->path != NULL)
    free(elem->path);
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
