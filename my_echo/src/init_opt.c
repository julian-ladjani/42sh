/*
** init_opt.c for 42 in /home/shielder/Projects/PSU/PSU_2016_42sh/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Sat May 20 12:42:07 2017 ilomax
** Last update Sat May 20 12:56:38 2017 ilomax
*/

#include "my_echo.h"

t_opt	init_opt()
{
  t_opt	opt;

  opt.n = 0;
  opt.f = 0;
  opt.F = 1;
  return (opt);
}
