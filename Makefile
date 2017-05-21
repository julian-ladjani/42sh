##
## Makefile for 42sh in /home/julian-ladjani/Rendu/PSU/PSU_2016_42sh
## 
## Made by Ladjani Julian
## Login   <julian.ladjani@epitech.eu>
## 
## Started on  Fri May 19 03:16:22 2017 Ladjani Julian
## Last update Sun May 21 21:49:32 2017 Ladjani Julian
##

TARGET   	 =	42sh

CC     		 = 	gcc

DEBUGFLAG	 =	-g

CFLAGS 		 = 	-Wall -I./include

LINKER 		 =	gcc
LFLAGS  	 =	-Wall -I./include

SRCDIR 		 =	src
OBJDIR  	 =	src
INCLUDEDIR	 =	include
BINDIR		 =	.

SOURCES 	 := 	$(SRCDIR)/buildin/alias/alias.c \
			$(SRCDIR)/buildin/alias/list/aliaslist.c \
			$(SRCDIR)/buildin/alias/list/aliaslist2.c \
			$(SRCDIR)/buildin/cd/cd.c \
			$(SRCDIR)/buildin/cd/cd_back.c \
			$(SRCDIR)/buildin/cd/cd_dir.c \
			$(SRCDIR)/buildin/cd/cd_noargs.c \
			$(SRCDIR)/buildin/cd/list/cdlist.c \
			$(SRCDIR)/buildin/cd/list/cdlist2.c \
			$(SRCDIR)/buildin/echo/echo.c \
			$(SRCDIR)/buildin/env/env.c \
			$(SRCDIR)/buildin/exit/exit.c \
			$(SRCDIR)/buildin/history/history.c \
			$(SRCDIR)/buildin/setenv/setenv.c \
			$(SRCDIR)/buildin/unsetenv/unsetenv.c \
			$(SRCDIR)/env/envmanagement.c \
			$(SRCDIR)/env/list/envlist.c \
			$(SRCDIR)/env/list/envlist2.c \
			$(SRCDIR)/init_prog.c \
			$(SRCDIR)/main.c \
			$(SRCDIR)/miscellaneous/basicfonc1.c \
			$(SRCDIR)/miscellaneous/basicfonc2.c \
			$(SRCDIR)/miscellaneous/basicfonc3.c \
			$(SRCDIR)/miscellaneous/get_next_line.c \
			$(SRCDIR)/miscellaneous/match.c \
			$(SRCDIR)/miscellaneous/my_str_to_wordtab.c \
			$(SRCDIR)/miscellaneous/nmatch.c \
			$(SRCDIR)/parsor/cmp_ope.c \
			$(SRCDIR)/parsor/epur_cmd.c \
			$(SRCDIR)/parsor/get_next_word.c \
			$(SRCDIR)/parsor/list/cmdlist.c \
			$(SRCDIR)/parsor/list/cmdlist2.c \
			$(SRCDIR)/parsor/list/cmdlist3.c \
			$(SRCDIR)/parsor/makespace_cmd.c \
			$(SRCDIR)/parsor/parse_cmd.c \
			$(SRCDIR)/parsor/parse_list_pipe.c \
		  	$(SRCDIR)/parsor/parse_list_redirs.c \
		  	$(SRCDIR)/parsor/parse_list_redirs_make.c \
		  	$(SRCDIR)/parsor/parse_ope.c \
		  	$(SRCDIR)/parsor/parse_to_type.c \
		  	$(SRCDIR)/parsor/start_cmd.c \
		  	$(SRCDIR)/prompt/pre_read.c \
		  	$(SRCDIR)/prompt/prompt.c \
			$(SRCDIR)/parsor/parse_list_sep.c \
			$(SRCDIR)/exec/do_args.c \
			$(SRCDIR)/exec/do_buildin.c \
			$(SRCDIR)/exec/do_check_cmd.c \
			$(SRCDIR)/exec/do_cmd.c \
			$(SRCDIR)/exec/do_redirs.c \
			$(SRCDIR)/exec/exec_cmd.c \
			$(SRCDIR)/exit_prog.c

OBJECTS		   :=	$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm		   =	rm -f

$(BINDIR)/$(TARGET):	$(OBJECTS)
		     	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
		     	@echo -e "\e[1;31mLinking complete!\e[1;00m"

.PHONY		   :	all
all		   :	$(BINDIR)/$(TARGET)

$(OBJECTS)	   : 	$(OBJDIR)/%.o : $(SRCDIR)/%.c
	     		@$(CC) $(CFLAGS) -c $< -o $@
			@if [ "$(CC)" = "gcc" ]; then echo -e "\e[1;32mCompiled "$<" successfully!\e[1;00m"; else echo -e "\e[1;32mCompiled "$<" successfully! \e[1;31mWARNING DEBUG\e[1;00m"; fi

.PHONY		   : 	clean
clean		   :
		     	@$(rm) $(OBJECTS)
		    	@echo -e "\e[1;31mCleanup complete!\e[1;00m"

.PHONY		   : 	fclean
fclean		   : 	clean
		     	@$(rm) $(BINDIR)/$(TARGET)
		     	@echo -e "\e[1;31mExecutable removed!\e[1;00m"

.PHONY		   : 	re
re		   : 	fclean
		     	@make --silent
		     	@echo -e "\e[1;31mremake done!\e[1;00m"

.PHONY		   :	clear
clear		   :
			@find . -name "*~" -a -type f -delete -o -name "#*#" -a -type f -delete
			@echo -e "\e[1;31mTemp file removed!\e[1;00m"
