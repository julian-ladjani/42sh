/*
** list.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Sun Mar 26 16:31:22 2017 Lorine Forfert
** Last update Sun Mar 26 16:31:57 2017 Lorine Forfert
*/

#include "my.h"

t_env   *push_back(t_env *new, char *env)
{
  int   i;
  int   j;

  i = 0;
  while (env[i] != '=')
    ++i;
  if ((new->name = malloc(sizeof (char) * (i + 1))) == NULL)
    return (NULL);
  new->name = my_strncpy(new->name, env, i);
  if ((new->value = malloc(sizeof (char) * (my_strlen(env) - i + 1))) == NULL)
    return (NULL);
  new->value[my_strlen(env) - i] = '\0';
  j = -1;
  while (env[++i] != '\0')
    new->value[++j] = env[i];
  new->next = NULL;
  return (new);
}

t_env   *init(t_env *new_env, char *env)
{
  t_env *new;
  t_env *tmp;

  if ((new = malloc(sizeof (t_env))) == NULL)
    return (NULL);
  new = push_back(new, env);
  if (new_env == NULL)
    return (new);
  else
    {
      tmp = new_env;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (new_env);
}
