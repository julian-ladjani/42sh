/*
** basicfonc2.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue Apr  4 15:08:31 2017 Ladjani Julian
** Last update Wed May 17 11:17:01 2017 Ladjani Julian
*/

#include "sh.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  char	*temp;
  int	j;

  if (src == NULL)
    return (dest);
  i = strlen(dest);
  j = 0;
  temp = strdup(dest);
  if ((dest = malloc((i + strlen(src) + 1) * sizeof(char))) == NULL)
    return (NULL);
  strcpy(dest, temp);
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
