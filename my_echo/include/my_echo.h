*
** my_echo.h for my_echo in /home/shielder/Projects/PSU/my_echo
** 
** Made by ilomax
** Login   <maxime.picot@epitech.eu>
** 
** Started on  Wed May 10 12:33:21 2017 ilomax
** Last update Sat May 20 17:00:19 2017 ilomax
*/

#ifndef MY_ECHO_H_
# define MY_ECHO_H_

# define ANSI_RESET	"\x1b[0m"
# define ANSI_RED	"\x1b[31m"
# define ANSI_GREEN	"\x1b[32m"
# define ANSI_YELLOW	"\x1b[33m"
# define ANSI_BLUE	"\x1b[34m"
# define ANSI_MAGENTA	"\x1b[35m"
# define ANSI_CYAN	"\x1b[36m"

# define ESC_SEQ	"\abcefnrtv"

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

int	char_in_str(char c, char *str);
int	cnt_flags(char **av, int ac);

char	*find_flags(char **av);

t_argv	*echo_parser(char **av, int ac);
t_opt	init_opt();

#endif  /* !MY_ECHO_H_ */
