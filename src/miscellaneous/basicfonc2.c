/*
** basicfonc4.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Thu Apr  6 15:27:29 2017 Ladjani Julian
** Last update Sun May 21 21:56:07 2017 Ladjani Julian
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

  if (tab == NULL || tab[0] == NULL)
    {
      if ((tab = malloc(2 * sizeof(char *))) == NULL)
	return (NULL);
      tab[1] = NULL;
      tab[0] = strdup(str);
    }
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
