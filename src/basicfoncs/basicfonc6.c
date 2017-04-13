/*
** basicfonc6.c for minishell in /home/julian-ladjani/Rendu/PSU/PSU_2016_minishell2
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Sun Apr  9 13:57:26 2017 Ladjani Julian
** Last update Sun Apr  9 14:04:39 2017 Ladjani Julian
*/

#include "minishell.h"

void	my_putstrfd(char *str, int fd)
{
  write(fd, str, my_strlen(str));
}

void	my_putstrnfd(char *str, int fd)
{
  my_putstrfd(str, fd);
  write(fd, "\n", 1);
}
