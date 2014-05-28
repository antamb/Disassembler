
CC_FreeBSD	= gcc

CC_sun4		= /usr/sfw/bin/gcc

CC_ia64-linux	= /usr/bin/gcc

CC		= $(CC_$(HOSTTYPE))

NM		= ./nm

OBJDUMP		= ./objdump

NAME1		= my_nm

NAME2		= my_objdump

MAKE		= $(MAKE_$(HOSTTYPE))

MAKE_ia64-linux	= make

MAKE_FreeBSD	= make

INCLUDE		= -I./nm/include/ -I./objdump/include

RM		= rm -f

DATE		= `date | cut -d' ' -f4,2,3 | tr ' ' '_'`

CFLAGS		= -I./include/ -Werror -ansi -pedantic -ggdb3 -pipe -Wall -W 

all		:
		cd $(NM) && $(MAKE)
		cd $(OBJDUMP) && $(MAKE)
		$(CC) $(NM)/*.o $(CFLAGS) $(LDFLAGS) -o $(NAME1)
		$(CC) $(OBJDUMP)/*.o $(CFLAGS) $(LDFLAGS) -o $(NAME2)

clean		:
		cd $(NM) && $(MAKE) clean
		cd $(OBJDUMP) && $(MAKE) clean

fclean		:clean
		$(RM) $(NAME1) $(NAME2)

re		:fclean all clean

