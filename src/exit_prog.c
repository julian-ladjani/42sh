/*
** exit_prog.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun May 21 21:06:49 2017 Ladjani Julian
** Last update Wed Jun  7 01:37:28 2017 Ladjani Julian
*/

#include "sh.h"

static char	*get_my_path(t_mysh *vars)
{
  char		*path;

  path = HISTORY_FILE;
  if (vars->cdstack->next->path != NULL)
    if ((path = malloc((strlen(vars->cdstack->next->path)
                        + strlen(HISTORY_FILE) + 2)
                       * sizeof (char))) != NULL)
      {
        if (strcpy(path, vars->cdstack->next->path) == NULL ||
            strcat(path, "/") == NULL ||
            strcat(path, HISTORY_FILE) == NULL)
          path = NULL;
      }
  if (path == NULL)
    path = HISTORY_FILE;
  return (path);
}

void		exit_my_sh(t_mysh *vars)
{
  int		fd;
  int		i;

  i = 0;
  if ((fd = open(get_my_path(vars), O_CREAT | O_TRUNC | O_WRONLY, 0644)) < 0)
    return ;
  while (vars->history[i] != NULL)
    {
      write(fd, vars->history[i], strlen(vars->history[i]));
      write(fd, "\n", 1);
      free(vars->history[i]);
      i++;
    }
  free(vars->history);
}
