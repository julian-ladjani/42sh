/*
** init_prog.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu May 11 18:32:34 2017 Ladjani Julian
** Last update Sun May 21 22:08:25 2017 Ladjani Julian
*/

#include "sh.h"

static t_mysh	*init_my_env(t_mysh *vars, char **ae)
{
  int		i;
  t_envlist	*elem;
  char		**tab;

  i = 0;
  while (ae[i] != NULL)
    {
      if ((tab = my_str_to_wordtab(ae[i], '=')) == NULL ||
	  addenvelem_before(vars->env) == NULL)
	return (NULL);
      elem = vars->env->prev;
      if (tab != NULL && tab[0] != NULL)
        {
          elem->envkey = tab[0];
          if ((elem->env = strdup(ae[i])) == NULL)
	    return (NULL);
        }
      if (tab != NULL && tab[0] != NULL && tab[1] != NULL)
        elem->envvalue = tab[1];
      i++;
    }
  return (vars);
}

static char	**read_myhistory()
{
  int		fd;
  char		**history;
  char		*line;
  int		i;
  int		exit;

  exit = 0;
  if ((history = malloc(2 * sizeof(char *))) == NULL)
    return (NULL);
  history[0] = NULL;
  if ((fd = open(HISTORY_FILE, O_RDONLY)) < 0)
    return (history);
  i = 0;
  while ((line = get_next_line(fd, &exit)) != NULL)
    {
      if ((history = realloc(history, (i  + 2) * sizeof(char *))) == NULL ||
	  (history[i] = strdup(line)) == NULL)
	return (NULL);
      free(line);
      i++;
    }
  history[i] = NULL;
  close(fd);
  return (history);
}

static char	**read_myrc()
{
  int		fd;
  char		**rc;
  char		*line;
  int		i;
  int		exit;

  exit = 0;
  if ((rc = malloc(2 * sizeof(char *))) == NULL)
    return (NULL);
  rc[0] = NULL;
  if ((fd = open(RC_FILE, O_RDONLY)) < 0)
    return (rc);
  i = 0;
  while ((line = get_next_line(fd, &exit)) != NULL)
    {
      if ((rc = realloc(rc, (i  + 2) * sizeof(char *))) == NULL ||
	  (rc[i] = strdup(line)) == NULL)
	return (NULL);
      free(line);
      i++;
    }
  rc[i] = NULL;
  close(fd);
  return (rc);
}

static char	**read_myprompt()
{
  int		fd;
  char		**prompt;
  char		*line;
  int		i;
  int		exit;

  exit = 0;
  if ((prompt = malloc(2 * sizeof(char *))) == NULL)
    return (NULL);
  prompt[0] = NULL;
  if ((fd = open(PROMPT_FILE, O_RDONLY)) < 0)
    return (prompt);
  i = 0;
  while ((line = get_next_line(fd, &exit)) != NULL)
    {
      if ((prompt = realloc(prompt, (i  + 2) * sizeof(char *))) == NULL ||
	  (prompt[i] = strdup(line)) == NULL)
	return (NULL);
      free(line);
      i++;
    }
  prompt[i] = NULL;
  close(fd);
  return (prompt);
}

t_mysh		*init_prog(char **ae)
{
  t_mysh	*mysh;

  avoid_signaux();
  if ((mysh = malloc(sizeof(*mysh))) == NULL)
    return (NULL);
  mysh->exitval = 0;
  mysh->exit = 0;
  mysh->pcmdcurs = 0;
  mysh->buffsize = BUFF_SIZE;
  if ((mysh->env = envlist_create()) == NULL ||
      (init_my_env(mysh, ae)) == NULL ||
      (mysh->cmd = cmdlist_create()) == NULL ||
      (mysh->alias = aliaslist_create()) == NULL ||
      (mysh->cdstack = cdlist_create()) == NULL ||
      addcdelem_before(mysh->cdstack) == NULL ||
      (mysh->cdstack->prev->path = strdup(getcwd(NULL, 0))) == NULL ||
      (mysh->cmdbuffer = malloc(BUFF_SIZE * sizeof(char))) == NULL ||
      (mysh->history = read_myhistory()) == NULL ||
      (mysh->rc = read_myrc()) == NULL ||
      (mysh->prompt = read_myprompt()) == NULL)
    return (NULL);
  memset(mysh->cmdbuffer, '\0', BUFF_SIZE);
  return (mysh);
}
