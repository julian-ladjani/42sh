/*
** test.c for main.c in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:20 2017 Alexis Knob
** Last update Wed Mar 29 15:04:58 2017 Alexis Knob
*/

#include <string.h>
#include "my.h"

char	**replace(char **env, char *s2, int i_bis, char **s)
{
  int	i;
  int	y;

  i = 0;
  y = 0;
  while (env[i_bis][i] != '=')
    i++;
  i++;
  if (s[2] != NULL)
    while (s2[y] != '\0')
      env[i_bis][i++] = s2[y++];
  env[i_bis][i] = '\0';
  return (env);
}

char	**wordtab(char **str, char *s1, char *s2)
{
  char	**tab;
  int	i;
  int	i_bis;
  int	j;

  tab = malloc(sizeof(char *) * 224);
  i = -1;
  j = 0;
  while (str[++i] != NULL)
    {
      tab[i] = malloc(sizeof(char) * 102);
      tab[i] = str[i];
    }
  i_bis = i;
  tab[i_bis] = malloc(sizeof(char) * 102);
  i = 0;
  while (s1[i] != '\0')
    tab[i_bis][j++] = s1[i++];
  tab[i_bis][j++] = '=';
  i = 0;
  if (s2 == NULL)
    return (tab);
  while (s2[i] != '\0')
  tab[i_bis][j++] = s2[i++];
  return (tab);
}

char	**removeinenv(char **env, char *s)
{
  int	i;

  i = 0;
  while (env[++i] != NULL)
    if (my_strncmp(env[i], s, my_strlen(s)) == 0)
      {
	while (env[i] != NULL)
	  {
	    env[i] = env[i + 1];
	    i++;
	  }
	return (env);
      }
  return (env);
}
