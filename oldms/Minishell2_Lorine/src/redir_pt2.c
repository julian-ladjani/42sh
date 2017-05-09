/*
** redir_pt2.c for minishell in /home/lorine/semester_2/PSU/PSU_2016_minishell2
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Thu Apr  6 22:50:13 2017 Lorine Forfert
** Last update Thu Apr  6 23:37:16 2017 Lorine Forfert
*/

#include "my.h"

void	which_redir(char **env, char *path, char *line)
{
  char	**val;

  if (is_redir(line) == 1)
    {
      val = str_to_tab(line, '>', 0, 0);
      simple_r(env, val, path);
    }
  else if (is_redir(line) == 2)
    {
      val = str_to_tab(line, '<', 0, 0);
      simple_l(env, val, path);
    }
  else if (is_redir(line) == 3)
    {
      val = str_to_tab(line, '>', 0, 0);
      double_r(env, val, path);
    }
  else if (is_redir(line) == 4)
    {
      val = str_to_tab(line, '<', 0, 0);
      double_l(env, val, path);
    }
}

char    **concat_tabs(char **ft, char **sd)
{
  char  **new;
  int   i;
  int   j;

  new = malloc(sizeof(char *) * (nb_args(ft) + nb_args(sd) + 1));
  i = 0;
  while (i != (nb_args(ft) + nb_args(sd)))
    {
      j = -1;
      while (ft[++j] != NULL)
	{
	  new[i] = malloc(sizeof(char) * (my_strlen(ft[j]) + 1));
	  new[i] = my_strcpy(new[i], ft[j]);
	  ++i;
	}
      j = -1;
      while (sd[++j] != NULL)
	{
	  new[i] = malloc(sizeof(char) * (my_strlen(sd[j]) + 1));
	  new[i] = my_strcpy(new[i], sd[j]);
	  ++i;
	}
    }
  new[i] = NULL;
  return (new);
}
