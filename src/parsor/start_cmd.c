/*
** start_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed May 17 02:24:39 2017 Ladjani Julian
** Last update Sun May 21 01:31:01 2017 Ladjani Julian
*/

#include "sh.h"

static t_cmdlist	*search_ope(t_cmdlist *cmd,
				    t_cmdlist *root,
				    t_type ope)
{
  while (cmd->data->type != ope && cmd->data->type != SEP
	 && cmd != root)
    cmd = cmd->next;
  if (cmd == root)
    return (root);
  return (cmd->next);
}

static t_cmdlist	*get_next_command(t_cmdlist *cmd,
					  t_cmdlist *root,
					  int exitval)
{
  if (cmd->next == root)
    return (root);
  if (cmd->next->data->type == AND && exitval == SUCCES_RETURN)
    return (cmd->next->next);
  if (cmd->next->data->type == OR && exitval != SUCCES_RETURN)
    return (cmd->next->next);
  if (cmd->next->data->type == SEP)
    return (cmd->next->next);
  if (cmd->next->data->type == AND && exitval != SUCCES_RETURN)
    return (search_ope(cmd, root, OR));
  if (cmd->next->data->type == OR && exitval == SUCCES_RETURN)
    return (search_ope(cmd, root, SEP));
  return (root);
}

static int	call_cmd_do(t_mysh *vars, t_cmdlist *cmd)
{
  int		exitval;

  exitval = SUCCES_RETURN;
  while (cmd != vars->cmd)
    {
      if (strcmp(cmd->data->cmd, EXIT_CMD) == 0)
	vars->exitval = exit_main(cmd->data->av);
      else
	vars->exitval = do_execution(vars, cmd);
      if (cmd->data->exitval != SUCCES_RETURN)
        if (cmd->data->stdtype[1] == PIPE)
          close(cmd->data->std[1]);
      if (vars->exitval != SUCCES_RETURN)
	exitval = vars->exitval;
      if (cmd->next->data->type == CMD || cmd->next == vars->cmd)
	cmd = cmd->next;
      else
	{
	  cmd = get_next_command(cmd, vars->cmd, exitval);
	  if (cmd != vars->cmd)
	    exitval = SUCCES_RETURN;
	}
    }
  return (exitval);
}

int		call_cmd(t_mysh *vars, char *cmd)
{
  t_cmdlist	*cmdelem;

  vars->pcmdcurs = 0;
  if (strlen(cmd) < 1)
    return (ERROR_RETURN);
  memset(vars->cmdbuffer, '\0', vars->buffsize);
  strcpy(vars->cmdbuffer, cmd);
  if ((vars->cmdbuffer = epur_cmd(vars->cmdbuffer)) == NULL ||
      vars->cmdbuffer[0] == '\0' ||
      (vars->cmdbuffer = makespace_cmd(vars->cmdbuffer,
				       &vars->buffsize)) == NULL ||
      vars->cmdbuffer[0] == '\0' ||
      parse_first_word(vars) == NULL ||
      parse_list_redir(vars->cmd) == ERROR_RETURN ||
      parse_list_pipe(vars->cmd) == ERROR_RETURN ||
      parse_list_sep(vars->cmd) == ERROR_RETURN)
    return (ERROR_RETURN);
  cmdelem = vars->cmd->next;
  return ((vars->exitval = call_cmd_do(vars, cmdelem)));
}
