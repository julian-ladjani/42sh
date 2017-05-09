/*
** my_strcmp.c for emacs in /home/lorine.forfert/CPool_Day06
** 
** Made by Lorine Forfert
** Login   <lorine.forfert@epitech.net>
** 
** Started on  Mon Oct 10 16:27:14 2016 Lorine Forfert
** Last update Mon Oct 10 17:19:28 2016 Lorine Forfert
*/

int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  while (s1[a] == s2[a])
    {
      if (s1[a] == '\0' && s2[a] == '\0')
	return (0);
	  a++;
    }
  if (s1[a] > s2[a])
    return (1);
  else
    return (-1);
}
