/*
** parse_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 13 17:13:08 2017 Ladjani Julian
** Last update Fri May 19 21:54:57 2017 Ladjani Julian
*/

#include "sh.h"

t_cmdlist	*parse_my_cmd(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  if (word == NULL || word[0] == '\0')
    return (cmdelem);
  if (cmdelem->data->type == NOTHING)
    {
      cmdelem->data->type = CMD;
      cmdelem->data->cmd = word;
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
