/*
** basicfonc1.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2/src/basicfoncs
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed Mar 22 16:13:21 2017 Ladjani Julian
** Last update Thu Apr  6 22:59:53 2017 Ladjani Julian
*/

#include <minishell.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_getunbr(char *str)
{
  int	nb;

  nb = 0;
  while (str != NULL && *str != '\0')
    {
      nb = nb * 10 + *str - 48;
      str++;
    }
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  char	sign;

  nb = 0;

  if (str != NULL && *str == '-')
    {
      sign = '-';
      str++;
    }
  else
    sign = '+';
  while (str != NULL && *str != '\0')
    {
      nb = nb * 10 + *str - 48;
      str++;
    }
  if (sign == '+')
    return (nb);
  else
    return (nb * -1);
}

char	*my_strdup(char *src)
{
  int	i;
  char	*dest;

  i = 0;
  if ((dest = malloc((my_strlen(src) + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	*my_strndup(char *src, int n)
{
  int   i;
  char	*dest;

  i = 0;
  if ((dest = malloc((n + 1) * sizeof(char))) == NULL)
    return (NULL);
  while (i < n)
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
