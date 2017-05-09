##
## Makefile for infin_add in /home/Alexisbonk/test/DoMakefile
##
## Made by Alexisbonk
## Login   <Alexisbonk@epitech.eu>
##
## Started on  Tue Oct 25 09:55:00 2016 Alexisbonk
## Last update Fri Apr  7 10:59:35 2017 Alexis Knob
##

CC	=	gcc -g

RM	=	rm -f\
		rm *~

NAME	=	mysh

OBJS	=	$(SRCS:.c=.o)

SRCS	=	src/minishell.c\
		src/minishell2.c\
		src/my_str_to_wordtab.c\
		src/my_strcmp.c\
		src/my_strncmp.c\
		src/my_strcat.c\
		src/check.c\
		src/searchinenv.c\
		src/supp.c\
		src/arrow.c\
		src/strcpy.c\
		src/epurstr.c

CFLAGS	=	-I./include -W -Wall -Wextra

LIB	=	lib/libmy.a\
		lib/mygnl.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
