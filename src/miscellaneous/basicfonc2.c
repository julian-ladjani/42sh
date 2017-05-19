/*
** basicfonc4.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu Apr  6 15:27:29 2017 Ladjani Julian
** Last update Fri May 19 22:59:11 2017 Ladjani Julian
*/

#include "sh.h"

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

char	**add_str_to_tab(char **tab, char *str)
{
  char	**tmptab;
  int	tablen;
  int	i;

  tablen = my_tablen(tab);
  i = 0;
  if ((tmptab = malloc((tablen + 2) * sizeof(char *))) == NULL)
    return (NULL);
  while (tab[i] != NULL)
    {
      tmptab[i] = strdup(tab[i]);
      i++;
    }
  tmptab[i] = strdup(str);
  tmptab[i + 1] = NULL;
  free_my_tab(tab);
  return (tmptab);
}

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}

void	my_putstrn(char *str)
{
  my_putstr(str);
  write(1, "\n", 1);
}
