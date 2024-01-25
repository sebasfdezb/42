NAME 		= get_next_line
FLAGS 		= -Wall -Werror -Wextra
SRC 		= get_next_line.c\
			  get_next_line_utils.c\
			  get_next_line_bonus.c\
			  get_next_line_utils_bonus.c

OBJECTS = $(SRC:.c=.o)

.c.o:
		@gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
		@ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean:
		@rm -f $(OBJECTS) 

fclean:	clean
		@rm -f $(NAME) 

re: fclean all

.PHONY : all bonus re fclean clean