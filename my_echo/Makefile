##
## Makefile for makefile in /home/julian-ladjani/delivery/PSU/my_printf
##
## Made by julian ladjani
## Login   <julian.ladjani@epitech.net>
##
## Started on  Mon Nov  7 16:31:28 2016 julian ladjani
## Last update Sat May 20 14:33:10 2017 ilomax
##

CC 		=	gcc -g

SRC		=	src/main.c		\
			src/find_flags.c	\
			src/init_opt.c		\
			src/parser.c		\
			src/flags.c		

OBJ		=	$(SRC:.c=.o)

RM		=	rm -f

CFLAGS		=	-I./include/ -Wall -Wextra -W	

NAME 		=	my_echo

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CC) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)
			$(RM) *~

fclean:			clean
			$(RM) $(NAME)

re:			fclean all
