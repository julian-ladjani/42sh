/*
** epur_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sat May 13 15:18:44 2017 Ladjani Julian
** Last update Thu May 18 16:34:06 2017 Ladjani Julian
*/

#include "sh.h"

static char	*rm_cfst(char *str, int pos)
{
  while (str && str[pos] != '\0')
    {
      str[pos] = str[pos + 1];
      pos++;
    }
  return (str);
}

static void	epur_cmd_cond(char c, int *inhib, int *inquote)
{
  if (c == *DQUOTE_CHAR && *inhib == 0 && *inquote == 0)
    *inquote = 1;
  else if (c == *DQUOTE_CHAR && *inhib == 0 && *inquote == 1)
    *inquote = 0;
  if (c == *SQUOTE_CHAR && *inquote == 0)
    {
      *inhib = 2;
      *inquote = 1;
    }
  else if (c == *SQUOTE_CHAR && *inquote == 1)
    {
      *inhib = 0;
      *inquote = 0;
    }
  if (c == *INHIB_CHAR && *inhib == 0)
    *inhib = 1;
  else if (*inhib == 1)
    *inhib = 0;
}

static int	epur_see_char(char *cmd, int i)
{
  if (cmd[i] != *SPACE_CHAR && cmd[i] != *TAB_CHAR)
    return (i + 1);
  if (cmd[i] == *TAB_CHAR)
    cmd[i] = *SPACE_CHAR;
  if (cmd[i] == *SPACE_CHAR && i == 0)
    {
      rm_cfst(cmd, i);
      return (i);
    }
  if (cmd[i] == *SPACE_CHAR &&
      (cmd[i + 1] == *SPACE_CHAR || cmd[i + 1] == *TAB_CHAR))
    {
      rm_cfst(cmd, i);
      return (i);
    }
  return (i + 1);
}

static void	epur_cmd_error(char *cmd, int i, int inquote, int inhib)
{
  if (inquote > 0 && inhib == 2)
    {
      memset(cmd, '\0', i);
      printf("Unmatched '''.\n");
    }
  else if (inquote > 0)
    {
      memset(cmd, '\0', i);
      printf("Unmatched '\"'.\n");
    }
}

char		*epur_cmd(char *cmd)
{
  int	inquote;
  int	inhib;
  int	i;

  inquote = 0;
  inhib = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      epur_cmd_cond(cmd[i], &inhib, &inquote);
      if (inquote == 0)
	i = epur_see_char(cmd, i);
      else
	i++;
    }
  epur_cmd_error(cmd, i, inquote, inhib);
  return (cmd);
}
