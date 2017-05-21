/*
** main.c for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:24:47 2017 ilomax
** Last update Sun May 21 01:51:32 2017 Ladjani Julian
*/

#include "sh.h"

int		echo_main(char **av, t_cmdlist *cmd)
{
  int		n;
  int		i;

  n = 0;
  i = 1;
  if (av != NULL && av[1] != NULL && strcmp(av[1], "-n") == 0)
    {
      n = 1;
      i++;
    }
  while (av != NULL && av[i] != NULL && av[i + 1] != NULL)
    {
      dprintf(cmd->data->std[1], "%s ", av[i]);
      i++;
    }
  if (av != NULL && av[i] != NULL)
    dprintf(cmd->data->std[1], "%s", av[i]);
  if (n == 0)
    dprintf(cmd->data->std[1], "\n");
  else if (n == 1)
    return (0);
  return (0);
}
