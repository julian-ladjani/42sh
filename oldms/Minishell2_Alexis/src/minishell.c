/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Fri Apr  7 17:17:25 2017 Alexis Knob
*/

#include "my.h"

void	handler(int sig)
{
  signal(sig, SIG_IGN);
  my_printf("\n%s> ", getcwd(0, 0));
}

char	**first_step(char **s_bis_bis, char **env, char **path)
{
  int	i;
  char	**s_bis;

  i = 0;
  while (s_bis_bis[i] != NULL)
    {
      if ((s_bis_bis[i] != NULL) && (my_strcmp(s_bis_bis[i], "") != 0))
	{
	  s_bis = blc(env, 0, path, s_bis_bis[i]);
	  env = supp_bis(s_bis, env, 0, 0);
	}
      if ((my_strcmp(s_bis_bis[i], "") != 0) &&
	  (my_strcmp(s_bis[0], "exit") == 0))
	exit(0);
      i++;
    }
  return (env);
}

void	checkifpipe(char *s, int i)
{
  while (s[++i] != '\0')
    if (s[i] == '|')
      exit(0);
}

int	main(int ac, char **av, char **env)
{
  char	**s_bis_bis;
  char	**path;
  char	*s;

  av[0]++;
  signal(SIGINT, handler);
  path = my_str_to_wordtab(searchenv(env, "PATH"), ':', 0, 0);
  while (42 && ac == 1)
    {
      my_printf("%s> ", getcwd(0, 0));
      s = get_next_line(0);
      if (s == NULL)
	{
	  my_printf("exit\n");
	  if (bag.wreturn != 0)
	    return (1);
	  else
	    return (0);
	}
      checkifpipe(s, -1);
      s = epurstr(s);
      s_bis_bis = my_str_to_wordtab(s, ';', 0, 0);
      env = first_step(s_bis_bis, env, path);
    }
  return (0);
}
