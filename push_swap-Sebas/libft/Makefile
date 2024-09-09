NAME 		= libft.a
FLAGS 		= -Wall -Werror -Wextra
SRC 		= ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isdigit.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strncmp.c\
				ft_split.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_substr.c\
				ft_memcpy.c\
				ft_strdup.c\


OBJECTS = $(SRC:.c=.o)

.c.o:
		gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean:
		rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME) $(OBJECTS)

re: fclean all

.PHONY : all bonus re fclean clean
