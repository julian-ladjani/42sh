/*
** cmdlist3.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Tue May 16 19:59:17 2017 Ladjani Julian
** Last update Tue May 16 19:59:32 2017 Ladjani Julian
*/

#include "sh.h"

void	delete_cmdlist(t_cmdlist *list)
{
  clean_cmdlist(list);
  free(list);
}
