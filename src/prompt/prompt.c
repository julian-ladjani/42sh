/*
** prompt.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/prompt
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Wed May 17 02:30:41 2017 Ladjani Julian
** Last update Thu May 18 02:59:59 2017 Ladjani Julian
*/

#include "sh.h"

void	write_prompt(t_mysh *vars)
{
  (void)vars;
  write(1, "?>", 2);
}
