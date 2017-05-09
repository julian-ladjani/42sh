/*
** minishell.h for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
** 
** Made by Ladjani Julian
** Login   <julian.ladjani@epitech.eu>
** 
** Started on  Mon May  8 23:33:12 2017 Ladjani Julian
** Last update Tue May  9 10:55:12 2017 Ladjani Julian
*/

#ifndef 42SH_H_
# define 42SH_H_

# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <ncurses.h>

# include "42structs.h"
# include "42fonctions.h"

/*
GET_NEXT_LINE DEFINE
*/
# define READ_SIZE 512
/*
** 42SH OPERATORS
*/
# define PIPE_CHAR "|"
# define LREDIR_CHAR "<"
# define RREDIR_CHAR ">"
# define LDREDIR_CHAR "<<"
# define RDREDIR_CHAR ">>"
# define SEP_CHAR ";"
# define AND_CHAR "&&"
# define OR_CHAR "||"
# define OPEN_PAR "("
# define CLOSE_PAR ")"
/*
** 42SH FILE NAME
*/
# define HISTORY_FILE ".42sh_history"
# define RC_FILE ".42sh_rc"
# define PROMPT_FILE ".42sh_prompt"
/*
** 42SH BUILDIN
*/
# define BUILDIN_CD "cd"
# define BUILDIN_ENV "env"
# define BUILDIN_SETENV "setenv"
# define BUILDIN_UNSETENV "unsetenv"
# define BUILDIN_ALIAS "alias"
# define BUILDIN_ECHO "echo"
# define BUILDIN_HISTORY "history"
# define ERROR_RETURN 1
# define SUCCES_RETURN 0

#endif /* !MINISHELL_H_ */
