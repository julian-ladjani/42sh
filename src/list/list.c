/*
** list.c for my_pushswap in /home/julian-ladjani/delivery/CPE/PushSwap/CPE_2016_Pushswap/src
**
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
**
** Started on  Wed Nov 23 12:18:54 2016 julian ladjani
** Last update Mar Jan 24 20:58:46 2017 Julian Ladjani
*/

#include "minishell.h"

t_list		*list_create()
{
  t_list	*root;

  if (((root = malloc(sizeof(*root))) != NULL))
    {
      root->env = NULL;
      root->envkey = NULL;
      root->envvalue = NULL;
      root->first = 1;
      root->prev = root;
      root->next = root;
    }
  return (root);
}

void		clean_list(t_list *list)
{
  while (list->next != NULL && list->next->first == 1)
    {
      list = list->next;
      free(list->prev);
    }
  free(list);
}

void		delete_list(t_list *list)
{
  clean_list(list);
  free(list);
}

void		addelem_before(t_list *elem)
{
  t_list	*new_elem;

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
    }
}

void		addelem_after(t_list *elem)
{
  t_list	*new_elem;

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
    }
}
