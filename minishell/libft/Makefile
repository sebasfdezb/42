NAME 		= libft.a
FLAGS 		= -Wall -Werror -Wextra
SRC 		= ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strncmp.c\
				ft_strrchr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_strnstr.c\
				ft_substr.c\
				ft_strjoin.c\
				ft_strtrim.c\
				ft_putchar_fd.c\
				ft_putstr_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_split.c\
				ft_itoa.c\
				ft_striteri.c\
				ft_strmapi.c\
				ft_printf.c\
				ft_printchar.c\
				ft_printhexa.c\
				ft_printdec.c\
				ft_printptr.c\
				ft_printstr.c\
				ft_printunsigned.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c\
				get_next_line_bonus.c\
				get_next_line_utils_bonus.c\

OBJECTS = $(SRC:.c=.o)

.c.o:
		gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

all : $(NAME)

clean:
		rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME) $(bonus)

re: fclean all

.PHONY : all bonus re fclean clean
