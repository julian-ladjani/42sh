TARGET   = projectname

CC       = gcc
CFLAGS   =  -Wall -I.

LINKER   = gcc
LFLAGS   = -Wall -I. -lm

SRCDIR   = src
OBJDIR   = obj
INCLUDEDIR = include
BINDIR   = bin

SOURCES  := $(SRCDIR)/buildin/alias/alias.c \
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
	  $(SRCDIR)/prompt/prompt.c
INCLUDES := $(INCLUDEDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f

$(BINDIR)/$(TARGET): $(OBJECTS)
    @$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
    @echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
    @$(CC) $(CFLAGS) -c $< -o $@
    @echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
    @$(rm) $(OBJECTS)
    @echo "Cleanup complete!"

.PHONY: remove
remove: clean
    @$(rm) $(BINDIR)/$(TARGET)
    @echo "Executable removed!"
