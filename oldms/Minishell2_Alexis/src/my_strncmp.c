/*
** my_strncmp.c for my_strncmp.c in /home/Alexisbonk/PSU_2016_minishell2
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Mar 22 15:24:37 2017 Alexis Knob
** Last update Fri Mar 24 15:34:59 2017 Alexis Knob
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] && s2[i] && i < n)
    i++;
  if ((s1[i] == '\0' && s2[i] == '\0') || i == n)
    return (0);
  else if (s1[i] > s2[i])
    return (1);
  else
    return (-1);
}
