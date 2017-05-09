/*
** env.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Thu Mar 23 16:40:23 2017 Lorine Forfert
** Last update Wed Apr  5 21:43:31 2017 Lorine Forfert
*/

#include "my.h"

void	my_env(t_env *env)
{
  t_env	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      my_printf("%s=%s\n", tmp->name, tmp->value);
      tmp = tmp->next;
    }
}

t_env	*one_more(t_env *env, char *name, char *value)
{
  t_env	*new;
  t_env	*tmp;

  if ((new = malloc(sizeof (t_env))) == NULL)
    return (NULL);
  new->name = my_strcpy(new->name, name);
  new->value = my_strcpy(new->value, value);
  new->next = NULL;
  if (env == NULL)
    return (new);
  else
    {
      tmp = env;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (env);
}

t_env	*my_setenv(t_env *env, char **tab, int i)
{
  t_env	*tmp;
  int	args;

  args = nb_args(tab);
  if (args == 1)
    my_env(env);
  tmp = env;
  if (args == 3)
    {
      while (tmp != NULL)
	{
	  if (my_strncmp(tmp->name, tab[1], my_strlen(tab[1])) == 0)
	    i = 1;
	  tmp = tmp->next;
	}
      if (i == 0)
	env = one_more(env, tab[1], tab[2]);
      else if (i == 1)
	{
	  while (my_strncmp(env->name, tab[1], my_strlen(tab[1])) != 0)
	    env = env->next;
	  free(env->value);
	  env->value = my_strcpy(env->value, tab[2]);
	}
    }
  else if (args > 3)
    my_printf("setenv: Too many arguments.\n");
  return (env);
}
