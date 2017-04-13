/*
** basicfonc2.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue Apr  4 15:08:31 2017 Ladjani Julian
** Last update Fri Apr  7 22:13:47 2017 Ladjani Julian
*/

#include "minishell.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && i < (n - 1) &&
	 s1[i] != '\0')
    i++;
  return (s1[i] - s2[i]);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s1[i] == s2[i])
    i++;
  return (s1[i] - s2[i]);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  char	*temp;
  int	j;

  if (src == NULL)
    return (dest);
  i = my_strlen(dest);
  j = 0;
  temp = my_strdup(dest);
  if ((dest = malloc((i + my_strlen(src) + 1) * sizeof(char))) == NULL)
    return (NULL);
  my_strcpy(dest, temp);
  free(temp);
  while (src[j] != '\0')
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  dest[i] = '\0';
  return (dest);
}

void		my_memset(char *s, int c, size_t n)
{
  size_t	i;

  i = 0;

  while (i < n)
    {
      s[i] = c;
      i++;
    }
}

