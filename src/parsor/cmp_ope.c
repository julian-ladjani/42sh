/*
** cmp_ope.c for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/src/parsor
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Mon May 15 11:46:35 2017 Ladjani Julian
** Last update Mon May 15 15:10:35 2017 Ladjani Julian
*/

#include "sh.h"

t_type		cmp_ope(char c1, char c2)
{
  if (c1 == LDREDIR_CHAR[0] && c2 == LDREDIR_CHAR[1])
    return (LDREDIR);
  if (c1 == RDREDIR_CHAR[0] && c2 == RDREDIR_CHAR[1])
    return (RDREDIR);
  if (c1 == AND_CHAR[0] && c2 == AND_CHAR[1])
    return (AND);
  if (c1 == OR_CHAR[0] && c2 == OR_CHAR[1])
    return (OR);
  if (c1 == *PIPE_CHAR)
    return (PIPE);
  if (c1 == *LREDIR_CHAR)
    return (LREDIR);
  if (c1 == *RREDIR_CHAR)
    return (RREDIR);
  if (c1 == *SEP_CHAR)
    return (SEP);
  return (NOTHING);
}
