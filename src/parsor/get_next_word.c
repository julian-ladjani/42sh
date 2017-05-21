/*
** get_next_word.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Mon May 15 12:03:01 2017 Ladjani Julian
** Last update Sun May 21 00:02:59 2017 Ladjani Julian
*/

#include "sh.h"

static void	cmd_checkquote(char c, int *inhib, int *inquote)
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

static void	get_next_word_end(char *word, int i, int *cursor)
{
  while (word[i] != ' ' && word[i] != '\0')
    i++;
  word[i] = '\0';
  *cursor += (i + 1);
}

char		*get_next_word(char *word, int *cursor)
{
  int		inquote;
  int		inhib;
  int		i;

  i = 0;
  inquote = 0;
  inhib = 0;
  word += *cursor;
  cmd_checkquote(word[i], &inhib, &inquote);
  if (inquote != 0)
    {
      while (inquote != 0 && word[i] != '\0')
        cmd_checkquote(word[++i], &inhib, &inquote);
      word[i] = '\0';
      word++;
      i++;
      while (word[i] == ' ')
	i++;
      *cursor += (i + 1);
      return (word);
    }
  get_next_word_end(word, i, cursor);
  return (word);
}
