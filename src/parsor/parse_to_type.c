/*
** parse_to_type.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May 16 14:55:44 2017 Ladjani Julian
** Last update Fri May 19 22:09:02 2017 Ladjani Julian
*/

#include "sh.h"

t_type		check_word(char *word)
{
  if (word[0] == '\0')
    return (NOTHING);
  if (strcmp(word, PIPE_CHAR) == 0)
    return (PIPE);
  if (strcmp(word, LREDIR_CHAR) == 0)
    return (LREDIR);
  if (strcmp(word, RREDIR_CHAR) == 0)
    return (RREDIR);
  if (strcmp(word, LDREDIR_CHAR) == 0)
    return (LDREDIR);
  if (strcmp(word, RDREDIR_CHAR) == 0)
    return (RDREDIR);
  if (strcmp(word, AND_CHAR) == 0)
    return (AND);
  if (strcmp(word, OR_CHAR) == 0)
    return (OR);
  if (strcmp(word, SEP_CHAR) == 0)
    return (SEP);
  return (CMD);
}

t_cmdlist	*parse_to_type(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  t_type	wordtype;

  if (cmdelem == NULL)
    return (NULL);
  if (word == NULL || word[0] == '\0')
    {
      if (cmdelem->data->type == NOTHING)
	delcmdelem(cmdelem);
      return (cmdelem);
    }
  wordtype = check_word(word);
  if (cmdelem->data->type == CMD && cmdelem->data->type != wordtype)
    if ((cmdelem = addcmdelem_before(vars->cmd)) == NULL)
      return (NULL);
  if (wordtype == CMD)
    return (parse_my_cmd(vars, cmdelem, word));
  if (wordtype == PIPE)
    return (parse_my_pipe(vars, cmdelem, word));
  if (wordtype == LREDIR || wordtype == RREDIR)
    return (parse_my_redir(vars, cmdelem, word));
  if (wordtype == AND || wordtype == OR || wordtype == SEP)
    return (parse_my_sep(vars, cmdelem, word));
  if (wordtype == LDREDIR || wordtype == RDREDIR)
    return (parse_my_redir(vars, cmdelem, word));
  return (cmdelem);
}
