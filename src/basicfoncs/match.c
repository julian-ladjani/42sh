/*
** match.c for match in /home/julian_ladjani/delivery/CPool_match-nmatch
** 
** Made by julian ladjani
** Login   <julian.ladjani@epitech.net>
** 
** Started on  Fri Oct 14 14:33:35 2016 julian ladjani
** Last update Sun Apr  9 03:08:26 2017 Ladjani Julian
*/

int	match(char *s1, char *s2)
{
  if (*s1 == '\0' && *s2 == '*')
    return (match(s1, s2 + 1));
  if (*s2 == '*' && s1 != '\0')
    return (match(s1 + 1, s2) | match(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0')
    return (match(s1 + 1, s2 + 1));
  if (*s1 != *s2)
    return (0);
  if (*s1 == '\0' && *s2 == '\0')
    return (1);
  if (*s2 == '\0')
    return (0);
  return (0);
}
