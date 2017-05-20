/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/exam/rendu/task05
**
** Made by exam user
** Login   <exam@epitech.net>
**
** Started on  Sat Oct 15 09:20:16 2016 exam user
** Last update Sat May 20 16:35:03 2017 Ladjani Julian
*/

#include "sh.h"

static int	is_sep(char c, char sep)
{
  if (c != sep)
    return (1);
  return (0);
}

static int	tab_count(char *str, char sep)
{
  int		tabc;
  int		c;

  c = 0;
  tabc = 0;
  while (str[c] != '\0')
    {
      if (is_sep(str[c], sep) == 0 && c != 0 && is_sep(str[c - 1], sep) == 1)
	tabc++;
      c++;
    }
  tabc++;
  return (tabc);
}

static int	char_count(char *str, char sep)
{
  int		c;

  c = 0;
  while (is_sep(str[c], sep) == 1 && str[c] != '\0')
    {
      c++;
    }
  return (c);
}

char		**my_str_to_wordtab(char *str, char sep)
{
  int		tab;
  char		**my_array;

  tab = 0;
  if ((my_array = malloc((tab_count(str, sep) + 2) * sizeof(char *))) == NULL)
    exit(84);
  while (*str != '\0')
    {
      while (is_sep(*str, sep) == 0)
	str++;
      if (*str != '\0')
	{
	  if ((my_array[tab] = malloc(char_count(str, sep) + 2)) == NULL)
	    exit(84);
	  memset(my_array[tab], '\0', char_count(str, sep) + 2);
	  strncpy(my_array[tab], str, char_count(str, sep));
	  tab++;
	  str = str + char_count(str, sep);
	}
    }
  my_array[tab++] = NULL;
  return (my_array);
}
