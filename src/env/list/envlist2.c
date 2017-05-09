/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Tue May  9 13:15:54 2017 Ladjani Julian
*/

#include "minishell.h"

void		addenvelem_first(t_envlist *root)
{
  addenvelem_after(root);
}

void		addenvelem_last(t_envlist *root)
{
  addenvelem_before(root);
}

void		delenvelem_first(t_envlist *root)
{
  if (root->next != root)
    delenvelem(root->next);
}

void		delenvelem_last(t_envlist *root)
{
  if (root->prev != root)
    delenvelem(root->prev);
}

void		delenvelem(t_envlist *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
