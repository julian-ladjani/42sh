/*
** my_strcpy.c for emacs in /home/lorine.forfert/CPool_Day06
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.net>
** 
** Started on  Mon Oct 10 08:33:16 2016 Lorine Forfert
** Last update Wed Mar 22 17:01:02 2017 Lorine Forfert
*/

#include "my.h"

int	len(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    ++i;
  return (i);
}

char	*my_strcpy(char *dest, char *src)
{
  int	a;

  a = 0;
  dest = malloc(sizeof (char) * (len(src) + 1));
  while (src[a] != '\0')
    {
      dest[a] = src[a];
      a++;
    }
  dest[a] = '\0';
  return (dest);
}
