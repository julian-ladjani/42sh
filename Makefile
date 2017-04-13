##
## Makefile for makefile in /home/julian-ladjani/delivery/PSU/my_printf
##
## Made by julian ladjani
## Login   <julian.ladjani@epitech.net>
##
## Started on  Mon Nov  7 16:31:28 2016 julian ladjani
## Last update Sun Apr  9 13:59:41 2017 Ladjani Julian
##

CC 		=	gcc -g

SRC		=	src/builtin/bluitin.c			\
			src/builtin/bluitin2.c			\
			src/list/list.c				\
			src/list/list2.c			\
			src/list/list3.c			\
			src/my_exec.c				\
			src/basicfoncs/my_str_to_wordtab.c	\
			src/basicfoncs/basicfonc1.c		\
			src/basicfoncs/basicfonc2.c		\
			src/basicfoncs/basicfonc3.c		\
			src/basicfoncs/basicfonc4.c		\
			src/basicfoncs/basicfonc5.c		\
			src/basicfoncs/basicfonc6.c		\
			src/basicfoncs/match.c			\
			src/basicfoncs/nmatch.c			\
			src/execfonc.c				\
			src/execfonc2.c				\
			src/basicfoncs/get_next_line.c		\
			src/main.c				\
			src/prompt.c				\
			src/envmanagement.c			\

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		=	-I./include/ -Wall -Wextra -W

LIBDIR		=	./lib/

NAME 		=	mysh

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L$(LIBDIR)

clean:
			$(RM) $(OBJ)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
