
CC_FreeBSD	= gcc

CC_sun4		= /usr/sfw/bin/gcc

CC_ia64-linux	= /usr/bin/gcc

CC		= $(CC_$(HOSTTYPE))

SRC		= \
		main.c			\
		sort.c			\
		mmap.c			\
		my_nm.c			\
		error.c			\
		print.c			\
		parser.c		\
		get_helf.c		\
		get_self.c		\
		free_list.c		\
		add_symbol.c		\
		miscellaneous.c		\
		miscellaneous_ext.c	\

OBJ		= $(SRC:.c=.o)

RM		= rm -f

DATE		= `date | cut -d' ' -f4,2,3 | tr ' ' '_'`

CFLAGS		= -I./include/ -Werror -ansi -pedantic -ggdb3 -pipe -Wall -W 

all		:$(OBJ)

clean		:
		$(RM) *.o *~ *#

