/*
** envmanagement.c for minishell in /home/julian-ladjani/delivery/Shell/PSU_2016_minishell1/src
**
** Made by Julian Ladjani
** Login  <julian.ladjani@epitech.eu>
**
** Started on  Jan Jan 22 21:08:00 2017 Julian Ladjani
** Last update Fri Apr  7 00:01:19 2017 Ladjani Julian
*/

#include "minishell.h"

char		**env_to_tabenv(t_list *root)
{
  int		i;
  char		**env;
  t_list	*elem;

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

t_list		*search_in_list(t_list *root, char *word)
{
  t_list	*elem;

  elem = root->next;
  while (elem != root)
    {
      if (my_strcmp(elem->envkey, word) == 0)
	return (elem);
      elem = elem->next;
    }
  return (NULL);
}

void		str_to_env(t_mysh *vars)
{
  t_list	*elem;
  char		**tab;

  elem = vars->env;
  tab = my_str_to_wordtab(vars->cmd, '=');
  if ((elem = search_in_list(elem, tab[0])) == NULL)
    {
      addelem_before(vars->env);
      elem = vars->env->prev;
    }
  if (tab != NULL && tab[0] != NULL)
    {
      elem->envkey = tab[0];
      elem->env = vars->cmd;
    }
  if (tab != NULL && tab[0] != NULL && tab[1] != NULL)
    elem->envvalue = tab[1];
  if (tab != NULL)
    free(tab);
}

char		*set_my_path(char *path, char *cmd)
{
  char		*dest;

  dest = my_strdup(path);
  dest = my_strcat(dest, "/");
  dest = my_strcat(dest, cmd);
  return (dest);
}
