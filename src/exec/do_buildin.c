/*
** do_buildin.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 20 13:42:10 2017 Ladjani Julian
** Last update Sat May 20 20:04:51 2017 Ladjani Julian
*/

#include "sh.h"

void	exec_buildin(t_mysh *vars, t_cmdlist *cmd)
{
  if (strcmp(cmd->data->cmd, BUILDIN_CD) == 0)
    cmd->data->exitval = cd_main(vars, cmd);
  else if (strcmp(cmd->data->cmd, BUILDIN_ECHO) == 0)
    cmd->data->exitval = echo_main(cmd->data->av);
  else if (strcmp(cmd->data->cmd, BUILDIN_ENV) == 0)
    cmd->data->exitval = env_main(vars, cmd);
  else if (strcmp(cmd->data->cmd, BUILDIN_UNSETENV) == 0)
    cmd->data->exitval = unsetenv_main(vars,cmd);
  else if (strcmp(cmd->data->cmd, BUILDIN_HISTORY) == 0)
    cmd->data->exitval = history_main(vars);
  else if (strcmp(cmd->data->cmd, BUILDIN_ALIAS) == 0)
    cmd->data->exitval = alias_main(vars, cmd);
  else if (strcmp(cmd->data->cmd, BUILDIN_SETENV) == 0)
    cmd->data->exitval = setenv_main(vars, cmd);
  else
    cmd->data->exitval = ERROR_RETURN;
  if (cmd->data->stdtype[1] == PIPE)
        close(cmd->data->std[1]);
}
