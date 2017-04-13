/*
** basicfonc4.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu Apr  6 15:27:29 2017 Ladjani Julian
** Last update Fri Apr  7 15:36:11 2017 Ladjani Julian
*/

#include "minishell.h"

int     my_str_isalpha(char *str)
{
  while (*str != '\0')
    {
      if ((*str < 65 || *str > 90) &&
          (*str < 97 || *str > 122) &&
          (*str < 48 || *str > 57))
        return (0);
      str++;
    }
  return (1);
}

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putstrn(char *str)
{
  my_putstr(str);
  write(1, "\n", 1);
}

char	*epur_str(char *str)
{
  char	*res;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      res[j++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	res[j++] = ' ';
    }
  res[j] = '\0';
  return (res);
}
