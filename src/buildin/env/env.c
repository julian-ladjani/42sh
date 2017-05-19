/*
** env.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/buildin/env
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May  9 13:17:45 2017 Ladjani Julian
** Last update Mon May 15 23:59:57 2017 Ladjani Julian
*/

#include "sh.h"

int		env_main(t_mysh *vars)
{
  t_envlist	*elem;

  elem = vars->env->next;
  while (elem != vars->env)
    {
      printf("%s\n", elem->env);
      elem = elem->next;
    }
  return (0);
}
