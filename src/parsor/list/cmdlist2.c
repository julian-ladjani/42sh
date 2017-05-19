/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Thu May 18 02:52:31 2017 Ladjani Julian
*/

#include "sh.h"

void		addcmdelem_first(t_cmdlist *root)
{
  addcmdelem_after(root);
}

void		addcmdelem_last(t_cmdlist *root)
{
  addcmdelem_before(root);
}

void		delcmdelem_first(t_cmdlist *root)
{
  if (root->next != root)
    delcmdelem(root->next);
}

void		delcmdelem_last(t_cmdlist *root)
{
  if (root->prev != root)
    delcmdelem(root->prev);
}

void		delcmdelem(t_cmdlist *elem)
{
  if (elem->data != NULL)
    free(elem->data);
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
