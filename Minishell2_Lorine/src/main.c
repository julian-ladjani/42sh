/*
** main.c for minishell1 in /home/lorine/semester_1/PSU/PSU_2016_minishell1
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Tue Jan 17 16:24:03 2017 Lorine Forfert
** Last update Sun Apr  9 13:03:20 2017 Lorine Forfert
*/

#include "my.h"

char	*my_getpath(char **env, char *elem)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      if (my_strncmp(env[i], "PATH=", 5) == 0)
	  return (env[i] + 5);
      i++;
    }
  return (NULL);
}

char	**progs(char **tab, t_env *new_env, char **nenv, t_ms *ms)
{
  if (my_strcmp(tab[0], "setenv") == 0)
    {
      my_setenv(new_env, tab, 0);
      nenv = my_list_to_tab(new_env, nenv);
    }
  else if (my_strcmp(tab[0], "env") == 0)
    my_env(new_env);
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    {
      my_unsetenv(new_env, tab[1]);
      nenv = my_list_to_tab(new_env, nenv);
    }
  else if (my_strcmp(tab[0], "cd") == 0)
    my_cd(tab, nenv);
  else
    {
      my_printf("%s: Command not found.\n", tab[0]);
      ms->ret = 1;
    }
  return (nenv);
}

int	exec(t_ms *ms, t_env *new_env, char **env, char *line)
{
  ms->tab = str_to_tab(line, 32, 0, 0);
  ms->i = 0;
  while (access(mystrcatbis(ms->path[ms->i], ms->tab[0]), F_OK) != 0
	 && ms->path[ms->i] != NULL)
    ms->i++;
  if (is_pipe(line) == 1)
    return (0);
  if (is_redir(line) != 0)
    which_redir(env, ms->path[ms->i], line);
  else if (ms->path[ms->i] == NULL)
    ms->nenv = progs(ms->tab, new_env, env, ms);
  else
    {
      ms->pid = fork();
      if (ms->pid < 0)
	return (84);
      else if (ms->pid == 0)
	execve(mystrcat(ms->path[ms->i], ms->tab[0]), ms->tab, ms->nenv);
      wait(0);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_env	*new_env;
  t_ms	ms;

  ms.i = -1;
  new_env = NULL;
  while (env[++ms.i] != NULL)
    new_env = init(new_env, env[ms.i]);
  ms.nenv = my_list_to_tab(new_env, ms.nenv);
  ms.path = str_tab(my_getpath(ms.nenv, "PATH="));
  while (42)
    {
      my_printf("$>");
      if ((ms.gnl = get_next_line(0)) == NULL)
	return (ms.ret);
      ms.ret = 0;
      ms.args = str_to_tab(ms.gnl, ';', 0, 0);
      ms.j = -1;
      while (ms.args[++ms.j] != NULL)
	{
	  if (my_strcmp(ms.args[ms.j], "exit") == 0)
	    exit(0);
	  exec(&ms, new_env, env, ms.args[ms.j]);
	}
      free_tab(ms.args);
    }
}
