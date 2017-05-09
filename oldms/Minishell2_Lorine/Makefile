##
## Makefile for minishell1 in /home/lorine/semester_1/PSU/PSU_2016_minishell1
## 
## Made by Lorine Forfert
## Login   <lorine.forfert@epitech.eu@epitech.net>
## 
## Started on  Tue Jan 17 16:29:47 2017 Lorine Forfert
## Last update Sun Apr  9 12:58:22 2017 Lorine Forfert
##

SRC	=	src/main.c		\
		src/my_str_to_tab.c	\
		src/cp_tab.c		\
		src/str_tab.c		\
		src/my_strncpy.c	\
		src/list_to_tab.c	\
		src/my_strcpy.c		\
		src/my_strcat_bis.c	\
		src/env.c		\
		src/unsetenv.c		\
		src/my_strcmp.c		\
		src/cd.c		\
		src/list.c		\
		src/free_tab.c		\
		src/nb_args.c		\
		src/redir.c		\
		src/pipe.c		\
		src/redir_pt2.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CC	=	gcc -g

RM	=	rm -f	\
		rm src/*~ ./*~ include/*~

INC	=	include

LIB	=	lib/libmy.a lib/libgnl.a

CFLAGS	=	-I$(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LIB) -Llib

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		clean all

.PHONY:		all clean fclean re
