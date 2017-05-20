/*
** parse_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 13 17:13:08 2017 Ladjani Julian
** Last update Sat May 20 13:35:35 2017 Ladjani Julian
*/

#include "sh.h"

static t_type	get_my_cmdtype(char *cmd)
{
  if (strcmp(cmd, BUILDIN_CD) == 0 || strcmp(cmd, BUILDIN_ECHO) == 0 ||
      strcmp(cmd, BUILDIN_ENV) == 0 || strcmp(cmd, BUILDIN_UNSETENV) == 0 ||
      strcmp(cmd, BUILDIN_HISTORY) == 0 || strcmp(cmd, BUILDIN_ALIAS) == 0 ||
      strcmp(cmd, BUILDIN_SETENV) == 0)
    return (BUILDIN);
  return (EXEC);
}

t_cmdlist	*parse_my_cmd(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  if (word == NULL || word[0] == '\0')
    return (cmdelem);
  if (cmdelem->data->type == NOTHING)
    {
      cmdelem->data->type = CMD;
      cmdelem->data->cmd = strdup(word);
      cmdelem->data->cmdtype = get_my_cmdtype(cmdelem->data->cmd);
      if ((cmdelem->data->av = malloc(2 * sizeof(char *))) == NULL)
	return (NULL);
      cmdelem->data->av[0] = strdup(word);
      cmdelem->data->av[1] = NULL;
      return (parse_to_type(vars,
			    cmdelem,
			    strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))));
    }
  else if (check_word(word) == CMD && cmdelem->data->type == CMD)
    {
      if ((cmdelem->data->av = add_str_to_tab(cmdelem->data->av, word)) == NULL)
	return (NULL);
      return (parse_to_type(vars,
			    cmdelem,
			    strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))));
    }
  return (parse_to_type(vars, cmdelem, word));
}

t_cmdlist	*parse_first_word(t_mysh *vars)
{
  t_cmdlist	*cmdelem;
  char		*word;

  if ((cmdelem = addcmdelem_before(vars->cmd)) == NULL)
    return (NULL);
  if ((word = strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))) == NULL)
    return (NULL);
  return (parse_to_type(vars, vars->cmd->next, word));
}
