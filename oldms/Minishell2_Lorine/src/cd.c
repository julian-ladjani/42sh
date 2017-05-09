/*
** cd.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Fri Mar 24 15:40:25 2017 Lorine Forfert
** Last update Sun Apr  2 12:19:12 2017 Lorine Forfert
*/

#include "my.h"

char	*home(char **env)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    if (my_strncmp(env[i], "HOME=", 5) == 0)
      return (env[i] + 5);
  return (NULL);
}

  void	my_cd(char **tab, char **env)
{
  int	i;
  int	args;

  args = nb_args(tab);
  if (args > 2)
    my_printf("cd: Too many arguments.\n");
  else if (args == 1)
    {
      if (home(env) != NULL)
	i = chdir(home(env));
    }
  else
    {
      i = chdir(tab[1]);
      if (i == -1)
	my_printf("%s: Not a directory.\n", tab[1]);
      else if (i == 0)
	my_printf("Directory: %s\n", tab[1]);
    }
}
