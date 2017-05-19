/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Wed May 17 02:43:13 2017 Ladjani Julian
*/

#include "sh.h"

t_envlist	*envlist_create()
{
  t_envlist	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->env = NULL;
      root->envkey = NULL;
      root->envvalue = NULL;
      root->first = 1;
      root->prev = root;
      root->next = root;
      return (root);
    }
  return (NULL);
}

void		clean_envlist(t_envlist *list)
{
  while (list->next != NULL && list->next->first == 1)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
}

void		delete_envlist(t_envlist *list)
{
  clean_envlist(list);
  free(list);
}

t_envlist	*addenvelem_before(t_envlist *elem)
{
  t_envlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->env = NULL;
      new_elem->envkey = NULL;
      new_elem->envvalue = NULL;
      new_elem->first = 0;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
      return (new_elem);
    }
  return (NULL);
}

t_envlist	*addenvelem_after(t_envlist *elem)
{
  t_envlist	*new_elem;

  if (((new_elem = malloc(sizeof(*new_elem))) != NULL))
    {
      new_elem->env = NULL;
      new_elem->envkey = NULL;
      new_elem->envvalue = NULL;
      new_elem->first = 0;
      new_elem->next = elem->next;
      new_elem->prev = elem;
      elem->next->prev = new_elem;
      elem->next = new_elem;
      return (new_elem);
    }
  return (NULL);
}
