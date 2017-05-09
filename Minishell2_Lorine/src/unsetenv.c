/*
** unsetenv.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 00:41:04 2017 Lorine Forfert
** Last update Fri Mar 24 00:58:55 2017 Lorine Forfert
*/

#include "my.h"

t_env	*my_unsetenv(t_env *env, char *name)
{
  t_env	*tmp;

  tmp = env;
  while ((env = env->next) != NULL)
    {
      if (my_strcmp(env->name, name) == 0)
	{
	  tmp->next = env->next;
	  free(env);
	}
      tmp = env;
    }
  return (env);
}
