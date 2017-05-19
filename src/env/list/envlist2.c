/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Wed May 17 02:43:33 2017 Ladjani Julian
*/

#include "sh.h"

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
  if (elem->envkey != NULL)
    free(elem->envkey);
  if (elem->envvalue != NULL)
    free(elem->envvalue);
  if (elem->env != NULL)
    free(elem->env);
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
