/*
** my_strcat.c for emacs in /home/lorine/semester_1/PSU/PSU_2016_minishell1
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.eu@epitech.net>
** 
** Started on  Sat Jan 21 16:47:50 2017 Lorine Forfert
** Last update Fri Mar 24 16:24:01 2017 Lorine Forfert
*/

#include "my.h"

char    *mystrcatbis(char *dest, char *src)
{
  int   a;
  int   b;
  char  *new;

  a = -1;
  b = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  if ((new = malloc(sizeof(char) * (my_strlen(dest)
				    + my_strlen(src) + 2))) == NULL)
    return (NULL);
  while (dest[++a] != '\0')
    new[a] = dest[a];
  new[a] = '/';
  a++;
  while (src[b] != '\0')
    {
      new[a] = src[b];
      a++;
      b++;
    }
  new[a] = '\0';
  return (new);
}
