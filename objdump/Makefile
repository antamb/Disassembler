
CC_FreeBSD	= gcc

CC_sun4		= /usr/sfw/bin/gcc

CC_ia64-linux	= /usr/bin/gcc

CC		= $(CC_$(HOSTTYPE))

SRC		= \
		main.c		\
		mmap.c		\
		error.c		\
		xwrite.c	\
		parser.c	\
		display.c	\
		get_helf.c	\
		get_self.c	\
		my_objdump.c	\
		miscellaneous.c	\

OBJ		= $(SRC:.c=.o)

RM		= rm -f

DATE		= `date | cut -d' ' -f4,2,3 | tr ' ' '_'`

CFLAGS		= -I./include/ -Werror -ansi -pedantic -ggdb3 -pipe -Wall -W 

all		:$(OBJ)

clean		:
		$(RM) *.o *~ *#
