NAME 		= libftprintf.a
FLAGS 		= -Wall -Werror -Wextra
SRC 		= ft_printchar.c\

OBJECTS = $(SRC:.c=.o)

.c.o:
		gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean:
		rm -f $(OBJECTS) 

fclean:	clean
		rm -f $(NAME) 

re: fclean all

.PHONY : all bonus re fclean clean