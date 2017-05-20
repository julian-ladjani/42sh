/*
** my_echo.h for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:33:21 2017 ilomax
** Last update Sat May 20 13:00:24 2017 ilomax
*/

#ifndef MY_ECHO_H_
# define MY_ECHO_H_

typedef struct	s_opt
{
  int	n;
  int	f;
  int	F;
}		t_opt;

typedef struct	s_argv
{
  char	**flags;
  char	**args;
}		t_argv;

int	cnt_flags(char **av, int ac);

t_argv	*echo_parser(char **av, int ac);

#endif  /* !MY_ECHO_H_ */
