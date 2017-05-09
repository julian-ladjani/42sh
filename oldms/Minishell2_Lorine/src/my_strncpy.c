/*
** my_strncpy.c for emacs in /home/lorine.forfert/CPool_Day06
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.net>
** 
** Started on  Mon Oct 10 10:05:40 2016 Lorine Forfert
** Last update Mon Oct 10 13:57:59 2016 Lorine Forfert
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	a;

  a = 0;
  while ((src[a] != '\0') && (n > 0))
    {
      dest[a] = src[a];
      a++;
      n--;
    }
  dest[a] = '\0';
  return (dest);
}
