/*
** do_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/exec
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Fri May 19 10:53:47 2017 Ladjani Julian
** Last update Sat May 20 16:44:55 2017 Ladjani Julian
*/

#include "sh.h"

static char		*set_my_cmd2(char *cmd, t_mysh *vars)
{
  int			i;

  i = 0;
  while (cmd && cmd[i] != '\0')
    {
      if (cmd[i] == '/')
        return (cmd);
      i++;
    }
  return (NULL);
}

static char		*set_my_path(char *path, char *cmd)
{
  char			*dest;

  if ((dest = strdup(path)) == NULL)
    return (NULL);
  if ((dest = realloc(dest, (strlen(dest) + strlen(cmd) + 2)
		      * sizeof(char))) == NULL)
    return (NULL);
  dest = strcat(dest, "/");
  dest = strcat(dest, cmd);
  return (dest);
}

char			*set_my_cmd_path(t_mysh *vars, t_cmdlist *cmd)
{
  int			i;
  char			*cmd2;
  char			**pathlist;
  t_envlist		*elem;

  i = 0;
  if (set_my_cmd2(cmd->data->cmd, vars) != NULL)
    return (cmd->data->cmd);
  if ((elem = search_in_envlist(vars->env, "PATH")) != NULL)
    {
      pathlist = my_str_to_wordtab(elem->envvalue, ':');
      while (pathlist[i] != NULL)
        {
          cmd2 = set_my_path(pathlist[i], cmd->data->av[0]);
	  if (access(cmd2, X_OK) == 0)
            return (cmd2);
          i++;
        }
      return (NULL);
    }
  cmd2 = set_my_path(DEFAULT_BIN_FOLDER, cmd->data->cmd);
  return (cmd2);
}
