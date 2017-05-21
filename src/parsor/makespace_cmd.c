/*
** makespace_cmd.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Mon May 15 12:00:10 2017 Ladjani Julian
** Last update Sun May 21 00:07:11 2017 Ladjani Julian
*/

#include "sh.h"

static char	*add_cfst(char *str, char c, int pos, int *buffsize)
{
  char		*tempstr;

  if ((int)(strlen(str) + 2) >= *buffsize)
    {
      *buffsize += BUFF_SIZE;
      if ((str = realloc(str, (*buffsize + BUFF_SIZE) * sizeof(char))) == NULL)
	return (NULL);
    }
  tempstr = strdup(str);
  strcpy(str + pos + 1, tempstr + pos);
  str[pos] = c;
  free(tempstr);
  return (str);
}

static void	makespace_cmd_cond(char c, int *inhib, int *inquote)
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

static int	nb_char_op(char *cmd)
{
  t_type	op;

  op = cmp_ope(cmd[0], cmd[1]);
  if (op == NOTHING)
    return (0);
  if (op == LDREDIR || op == RDREDIR ||
      op == AND || op == OR)
    return (2);
  return (1);
}

static int	makespace_see_char(char *cmd, size_t i, int *buffsize)
{
  int		nbchar;

  nbchar = nb_char_op(cmd + i);
  if (nbchar == 0 || i == 0)
    return (i + 1);
  if (cmd[i - 1] != *SPACE_CHAR  && cmd[i - 1] != *INHIB_CHAR
      && nb_char_op(cmd + i - 1) == 0)
    {
      if ((cmd = add_cfst(cmd, *SPACE_CHAR, i, buffsize)) == NULL)
	return (-1);
      i++;
    }
  if (strlen(cmd) < (i + nbchar))
    return (strlen(cmd) - 1);
  if (cmd[i + nbchar] != *SPACE_CHAR && cmd[i + nbchar] != '\0')
    {
      if ((cmd = add_cfst(cmd, *SPACE_CHAR, i + nbchar, buffsize)) == NULL)
	return (-1);
      i += nbchar;
    }
  return (i + 1);
}

char		*makespace_cmd(char *cmd, int *buffsize)
{
  int		inquote;
  int		inhib;
  int		i;

  inquote = 0;
  inhib = 0;
  i = 0;
  while (cmd[i] != '\0')
    {
      if ( i > 0 && cmd[i - 1] != *SPACE_CHAR && inquote == 0 && inhib == 0 &&
	  (cmd[i] == *DQUOTE_CHAR || cmd[i] == *SQUOTE_CHAR))
	{
	  if ((cmd = add_cfst(cmd, *SPACE_CHAR, i, buffsize)) == NULL)
	    return (NULL);
	  i++;
	}
      makespace_cmd_cond(cmd[i], &inhib, &inquote);
      if (cmd[i + 1] != *SPACE_CHAR && inquote == 0 && inhib == 0 &&
          (cmd[i] == *DQUOTE_CHAR || cmd[i] == *SQUOTE_CHAR)
	  && cmd[i - 1] != *INHIB_CHAR)
        {
          if ((cmd = add_cfst(cmd, *SPACE_CHAR, i + 1, buffsize)) == NULL)
            return (NULL);
          i++;
        }
      if (inquote == 0 && inhib == 0)
	{	  
	  if ((i = makespace_see_char(cmd, i, buffsize)) <= 0)
	    return (NULL);
	}
      else
	i++;
    }
  return (cmd);
}
