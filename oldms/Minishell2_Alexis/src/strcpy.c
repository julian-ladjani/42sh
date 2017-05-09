/*
** strcpy.c for strcpy.c in /home/Alexisbonk/PSU_2016_minishell2
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Thu Apr  6 12:01:13 2017 Alexis Knob
** Last update Thu Apr  6 12:01:23 2017 Alexis Knob
*/

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
