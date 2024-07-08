NAME	= libftprintf.a

SRCS	= 	ft_putchar.c\
			ft_printf.c\
			ft_puthexa.c\
			ft_printptr.c\
			ft_putstr.c\
			ft_printunsigned.c\
			ft_atoi.c\
			ft_strlen.c\
			ft_putnbr.c\

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re	
	
