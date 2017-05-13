/*
** 42structs.h for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh/include
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Mon May  8 17:22:03 2017 Ladjani Julian
** Last update Fri May 12 16:33:22 2017 Ladjani Julian
*/

#ifndef 42STRUCTS_H_
# define 42STRUCTS_H_

typedef enum		e_type
  {
    NOTHING,
    CMD,
    PIPE,
    LREDIR,
    RREDIR,
    LDREDIR,
    RDREDIR,
    AND,
    OR,
    NEXT,
  }			t_type;

typedef enum		e_cmdtype
  {
    EXEC,
    BUILTIN,
  }			t_cmdtype;

typedef enum		e_cmdmode
  {
    START,
    NORMAL,
    END,
    OPERATOR,
  }			t_cmdmode;

typedef struct		s_envlist
{
  char			*env;
  char			*envkey;
  char			*envvalue;
  char			first;
  struct s_envlist	*next;
  struct s_envlist	*prev;
}			t_envlist;

typedef struct		s_aliaslist
{
  char			*aliaskey;
  char			*aliasvalue;
  char			first;
  struct s_envlist	*next;
  struct s_envlist	*prev;
}			t_aliaslist;

typedef struct		s_cmddata
{
  t_cmdmode		mode;
  t_type		type;
  t_cmdtype		cmdtype;
  int			std[2];
  char			*cmd;
  char			**av;
  char			**ae;
}			t_cmddata;

typedef struct		s_cmdlist
{
  t_cmddata		*data;
  struct s_cmdlist	*next;
  struct s_cmdlist	*prev;
}			t_cmdlist;

typedef struct		s_cdlist
{
  char			*path;
  struct s_cdlist	*next;
  struct s_cdlist	*prev;  
}			t_cdlist;

typedef struct		s_mysh
{
  int			exitval;
  int			exit;
  t_cmdlist		*cmd;
  char			*cmdbuffer;
  char			**history;
  char			**rc;
  char			**prompt;
  t_cdlist		*cdstack;
  t_aliaslist		*alias;
  t_envlist		*env;
  struct termios	newt;
  struct termios	oldt;
}			t_mysh;

#endif /* !42STRUCTS_H_ */
