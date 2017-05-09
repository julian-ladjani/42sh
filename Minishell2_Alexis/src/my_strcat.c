/*
** main.c for main.c in /home/Alexisbonk/PSU_2016_tetris
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Mon Feb 20 11:06:20 2017 Alexis Knob
** Last update Wed Mar 22 16:57:27 2017 Alexis Knob
*/

#include "my.h"

char	*my_strcat(char *str, char *str_bis)
{
  char	*result;
  int	i;
  int	i_bis;

  i = 0;
  i_bis = 0;
  result = malloc(sizeof(char *) * (my_strlen(str) + my_strlen(str_bis)) + 1);
  while (str[i] != '\0')
    result[i_bis++] = str[i++];
  i = 0;
  while (str_bis[i] != '\0')
    result[i_bis++] = str_bis[i++];
  return (result);
}
