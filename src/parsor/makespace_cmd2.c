/*
** makespace_cmd2.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun May 21 22:20:05 2017 Ladjani Julian
** Last update Sun May 21 23:09:48 2017 Ladjani Julian
*/

#include "sh.h"

char	*makespace_cmd2_3(t_makespace *space)
{
  if (space->i > 0 && space->cmd[space->i - 1] != *SPACE_CHAR
      && space->inquote == 0 && space->inhib == 0 &&
       (space->cmd[space->i] == *DQUOTE_CHAR ||
	space->cmd[space->i] == *SQUOTE_CHAR))
    {
      if ((space->cmd = add_cfst(space->cmd, *SPACE_CHAR, space->i,
			  space->buffsize)) == NULL)
	return (NULL);
      space->i++;
    }
  return (space->cmd);
}

char	*makespace_cmd2_2(t_makespace *space)
{
  if (makespace_cmd2_3(space) == NULL)
    return (NULL);
  makespace_cmd_cond(space->cmd[space->i],
		     &space->inhib, &space->inquote);
  if (space->cmd[space->i + 1] != *SPACE_CHAR &&
      space->inquote == 0 && space->inhib == 0 &&
      (space->cmd[space->i] == *DQUOTE_CHAR ||
       space->cmd[space->i] == *SQUOTE_CHAR)
      && space->cmd[space->i - 1] != *INHIB_CHAR)
    {
      if ((space->cmd = add_cfst(space->cmd, *SPACE_CHAR,
				 space->i + 1,
				 space->buffsize)) == NULL)
	return (NULL);
      space->i++;
    }
  return (space->cmd);
}

char	*makespace_cmd2(t_makespace *space)
{
  if (makespace_cmd2_2(space) == NULL)
    return (NULL);
  if (space->inquote == 0 && space->inhib == 0)
    {
      if ((space->i = makespace_see_char(space->cmd,
					 space->i,
					 space->buffsize)) <= 0)
	return (NULL);
    }
  else
    space->i++;
  return (space->cmd);
}
