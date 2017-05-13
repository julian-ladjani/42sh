/*
** epur_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 13 15:18:44 2017 Ladjani Julian
** Last update Sat May 13 17:00:07 2017 Ladjani Julian
*/

#include <unistd.h>
#include <stdlib.h>

static char	*rm_cfst(char *str, int pos)
{
  while (str && str[pos] != '\0')
    {
      str[pos] = str[pos + 1];
      pos++;
    }
  return (str);
}

static void	*epur_cmd_cond(char c, int *inhib, int *inquote)
{
  if (c == DQUOTE_CHAR && *inhib == 0 && *inquote == 0)
    *inquote = 1;
  else if (c == DQUOTE_CHAR && *inhib == 0 && *inquote == 1)
    *inquote = 0;
  if (c == DQUOTE_CHAR && *inquote == 0)
    {
      *inhib = 2;
      *inquote = 1;
    }
  else if (c == DQUOTE_CHAR && *inquote == 1)
    {
      *inhib = 0;
      *inquote = 0;
    }
  if (c == INHIB_CHAR && *inhib == 0)
    *inhib = 1;
  else if (*inhib == 1)
    *inhib = 0;
}

static int	epur_see_char(char *cmd, int i)
{
  if (cmd[i] != SPACE_CHAR && cmd[i] != TAB_CHAR)
    return (i + 1);
  if (cmd[i] == TAB_CHAR)
    cmd[i] = ' ';
  if (cmd[i] == SPACE_CHAR && i == 0)
    {
      rm_cfst(cmd, i);
      return (i);
    }
  if (cmd[i] == SPACE_CHAR &&
      (cmd[i + 1] == SPACE_CHAR || cmd[i + 1] == TAB_CHAR))
    {
      rm_cfst(cmd, i);
      return (i);
    }
}

char		*epur_cmd(char *cmd)
{
  int	inquote;
  int	inhib;
  int	i;

  inquote = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      epur_cmd_cond(cmd[i], &inhib, &inquote);
      if (inquote == 0)
	i = epur_see_char(cmd, i);
      else
	i++;
    }
  return (cmd);
}
