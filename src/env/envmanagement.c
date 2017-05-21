/*
** envmanagement.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Jan 22 21:08:00 2017 Julian Ladjani
** Last update Sun May 21 00:54:43 2017 Ladjani Julian
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
  int		len;

  if ((elem = search_in_envlist(vars->env, envvar)) == NULL)
    elem = addenvelem_before(vars->env);
  elem->envkey = strdup(envvar);
  if (value != NULL)
    elem->envvalue = strdup(value);
  len = strlen(envvar);
  if (value != NULL)
    len += strlen(value);
  elem->env = strdup(elem->envkey);
  if ((elem->env = realloc(elem->env, len + 2)) == NULL)
    return ;
  elem->env = strcat(elem->env, "=\0");
  if (elem->envvalue != NULL)
    elem->env = strcat(elem->env, elem->envvalue);
}
