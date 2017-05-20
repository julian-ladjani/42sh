/*
** my_echo.h for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:33:21 2017 ilomax
** Last update Sat May 20 14:35:09 2017 ilomax
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

void	f_flag(char **av);
void	F_flag(char **av);

int	cnt_flags(char **av, int ac);

char	*find_flags(char **av);

t_argv	*echo_parser(char **av, int ac);
t_opt	init_opt();

#endif  /* !MY_ECHO_H_ */
