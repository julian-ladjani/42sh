/*
** nmatch.c for nmatch in /home/julian_ladjani/delivery/CPool_match-nmatch
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Sun Oct 16 15:31:38 2016 julian ladjani
** Last update Sun Oct 16 15:31:43 2016 julian ladjani
*/

int	nmatch(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '\0')
    return (1);
  if (*s1 == '\0' && *s2 == '*')
    return (nmatch(s1, s2 + 1));
  if (*s2 == '*' && s1 != '\0')
    return (nmatch(s1 + 1, s2) + nmatch(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0')
    return (nmatch(s1 + 1, s2 + 1));
  return (0);
}
