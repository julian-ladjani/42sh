/*
** list_to_tab.c for minishell in /home/lorine/semester_1/PSU/msh
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Wed Mar 22 15:51:51 2017 Lorine Forfert
** Last update Mon Apr 10 09:44:00 2017 Lorine Forfert
*/

#include "my.h"

char	**my_list_to_tab(t_env *env, char **tab)
{
  t_env	*tmp;
  char	*val;
  int	i;

  i = 0;
  tmp = env;
  while (tmp != NULL && ++i != 0)
    tmp = tmp->next;
  if ((tab = malloc(sizeof (char *) * (i + 1))) == NULL)
    return (NULL);
  tab[i] = NULL;
  tmp = env;
  i = 0;
  while (tmp != NULL)
    {
      val = my_strcpy(val, tmp->name);
      val = my_strcat(val, "=");
      val = my_strcat(val, tmp->value);
      tab[i] = my_strcpy(tab[i], val);
      ++i;
      tmp = tmp->next;
    }
  return (tab);
}
