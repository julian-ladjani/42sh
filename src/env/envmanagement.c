/*
** envmanagement.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Jan 22 21:08:00 2017 Julian Ladjani
** Last update Sat May 20 04:22:03 2017 Ladjani Julian
*/

#include "sh.h"

char		**env_to_tabenv(t_envlist *root)
{
  int		i;
  char		**env;
  t_envlist	*elem;

  i = 0;
  elem = root->next;
  while (elem != root)
    {
      i++;
      elem = elem->next;
    }
  if ((env = malloc((i + 1) * sizeof(char *))) == NULL)
    return (NULL);
  elem = elem->next;
  i = 0;
  while (elem != root)
    {
      env[i] = elem->env;
      elem = elem->next;
      i++;
    }
  env[i] = NULL;
  return (env);
}

t_envlist	*search_in_envlist(t_envlist *root, char *word)
{
  t_envlist	*elem;

  elem = root->next;
  while (elem != root)
    {
      if (strcmp(elem->envkey, word) == 0)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}

void		str_to_env(t_mysh *vars, char *envvar, char *value)
{
  t_envlist	*elem;

  if ((elem = search_in_envlist(vars->env, envvar)) == NULL)
    {
      addenvelem_before(vars->env);
      elem = vars->env->prev;
    }
  elem->envkey = strdup(envvar);
  elem->envvalue = strdup(value);
  elem->env = strdup(elem->envkey);
  elem->env = my_strcat(elem->envkey, "=\0");
  elem->env = my_strcat(elem->envkey, elem->envvalue);
}
