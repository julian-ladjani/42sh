/*
** gnl.h for gnl.h in /home/Alexisbonk/PSU_2016_minishell1
** 
** Made by Alexis Knob
** Login   <Alexisbonk@epitech.net>
** 
** Started on  Wed Jan 18 10:09:43 2017 Alexis Knob
** Last update Fri Apr  7 11:00:15 2017 Alexis Knob
*/

#ifndef		__my_h__
#define		__my_h__

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

typedef struct	s_struct
{
  int	wreturn;
}		t_struct;

t_struct	bag;
char	*get_next_line(int );
void	my_printf(char *, ...);
char	**my_str_to_wordtab(char *, char, int, int);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
char	*my_strcat(char *, char *);
int	my_strlen(char *);
int	supp(char **, char **, int);
char	**supp_bis(char **, char **, int, int);
int	supp_bis_bis(char **, char **);
int	searchinenv(char **, char *, char **);
char	*searchenv(char **, char *);
char	**replace(char **, char *, int, char **);
char	**wordtab(char **, char *, char *);
char	**blc(char **, int, char **, char *);
char	**removeinenv(char **, char *);
int	arrow(char *, char **);
char	*my_strcpy(char *, char *);
char	*epurstr(char *);

#endif
