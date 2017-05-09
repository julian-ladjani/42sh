/*
** epurstr.c for epurstr.c in /home/Alexisbonk/PSU_2016_minishell2
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Fri Apr  7 10:58:41 2017 Alexis Knob
** Last update Fri Apr  7 11:02:20 2017 Alexis Knob
*/

#include "my.h"

char	*epurstr(char *str)
{
  int	i;

  i = my_strlen(str) - 1;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    {
      str[i] = '\0';
      i = i - 1;
    }
  while ((*str == ' ' || *str == '\t') && *str != '\0')
    str = str + 1;
  return (str);
}
