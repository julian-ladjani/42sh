/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Fri Apr  7 11:06:43 2017 Alexis Knob
*/

#include "my.h"

int	finalcheck(char **path, char **s, char **env)
{
  int	i;
  int	i_bis;

  i = 0;
  while (access(my_strcat(my_strcat(path[i], "/"), s[0]), F_OK) != 0 &&
	 path[i + 1] != NULL)
    i++;
  if (path[i + 1] == NULL)
    {
      bag.wreturn++;
      my_printf("%s: Command not found.\n", s[0]);
    }
  else
    {
      i_bis = fork();
      if (i_bis < 0)
	return (84);
      if (i_bis == 0)
	execve(my_strcat(my_strcat(path[i], "/"), s[0]), s, env);
      wait(0);
    }
  return (0);
}

char	**blc(char **env, int i, char **path, char *s)
{
  char	**s_bis;

  s_bis = my_str_to_wordtab(s, ' ', 0, 0);
  if (my_strcmp(s_bis[0], "setenv") == 0 ||
      my_strcmp(s_bis[0], "unsetenv") == 0)
    i++;
  if (i == 0)
    i = arrow(s, env);
  if (i == 0)
    i = supp(s_bis, env, 0);
  if (i == 0)
    i = supp_bis_bis(s_bis, env);
  if (i == 0)
    bag.wreturn = 0;
  if (i == 0)
    finalcheck(path, s_bis, env);
  return (s_bis);
}
