/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Mar Jan 24 10:23:06 2017 Julian Ladjani
*/

#include "minishell.h"

void		addelem_first(t_list *root)
{
  addelem_after(root);
}

void		addelem_last(t_list *root)
{
  addelem_before(root);
}

void		delelem_first(t_list *root)
{
  if (root->next != root)
    delelem(root->next);
}

void		delelem_last(t_list *root)
{
  if (root->prev != root)
    delelem(root->prev);
}

void		delelem(t_list *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
