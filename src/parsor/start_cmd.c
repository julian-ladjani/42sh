/*
** start_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed May 17 02:24:39 2017 Ladjani Julian
** Last update Fri May 19 21:38:04 2017 Ladjani Julian
*/

#include "sh.h"

t_mysh		*call_cmd(t_mysh *vars, char *cmd)
{
  t_cmdlist	*cmdelem;

  vars->pcmdcurs = 0;
  memset(vars->cmdbuffer, '\0', vars->buffsize);
  strcpy(vars->cmdbuffer, cmd);
  if ((vars->cmdbuffer = epur_cmd(vars->cmdbuffer)) == NULL ||
      vars->cmdbuffer[0] == '\0' ||
      (vars->cmdbuffer = makespace_cmd(vars->cmdbuffer, &vars->buffsize)) == NULL ||
      vars->cmdbuffer[0] == '\0' ||
      parse_first_word(vars) == NULL ||
      parse_list_redir(vars->cmd) == ERROR_RETURN ||
      parse_list_pipe(vars->cmd) == ERROR_RETURN ||
      parse_list_sep(vars->cmd) == ERROR_RETURN)
    return (NULL);
  cmdelem = vars->cmd->next;
  while (cmdelem != vars->cmd)
    {
      if (cmdelem->data->type == CMD)
	printf("%s\n", cmdelem->data->cmd);
      else
	{
	  if (cmdelem->data->type == PIPE)
	    printf("PIPE\n");
	  if (cmdelem->data->type == LREDIR)
	    printf("%s %s\n", "REDIR", cmdelem->data->cmd);
	  if (cmdelem->data->type == AND)
	    printf("AND\n");
	  else
	    printf("OP %d\n", cmdelem->data->type);
	}
      cmdelem = cmdelem->next;
    }
  return (vars);
}
