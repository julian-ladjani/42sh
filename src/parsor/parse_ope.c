/*
** parse_ope.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May 16 17:53:35 2017 Ladjani Julian
** Last update Sat May 20 16:20:43 2017 Ladjani Julian
*/

#include "sh.h"

t_cmdlist	*parse_my_redir(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  t_type	wordtype;

  wordtype = check_word(word);
  cmdelem->data->type = wordtype;
  if ((word = strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))) == NULL)
    return (NULL);
  if ((wordtype = check_word(word)) != CMD)
    {
      printf("%s\n", "Missing name for redirect.");
      return (NULL);
    }
  cmdelem->data->cmd = word;
  return (parse_to_type(vars,
			addcmdelem_before(vars->cmd),
			strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))));
}

t_cmdlist	*parse_my_sep(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  t_type	wordtype;

  wordtype = check_word(word);
  cmdelem->data->type = wordtype;
  return (parse_to_type(vars,
			addcmdelem_before(vars->cmd),
			strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))));
}

t_cmdlist	*parse_my_pipe(t_mysh *vars, t_cmdlist *cmdelem, char *word)
{
  t_type	wordtype;

  wordtype = check_word(word);
  cmdelem->data->type = wordtype;
  if (cmdelem->prev == NULL || cmdelem->prev->data->type != CMD)
    {
      printf("%s\n", "Invalid null command.");
      return (NULL);
    }
  return (parse_to_type(vars,
			addcmdelem_before(vars->cmd),
			strdup(get_next_word(vars->cmdbuffer, &vars->pcmdcurs))));
}
