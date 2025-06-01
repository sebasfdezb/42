# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:31:24 by sebferna          #+#    #+#              #
#    Updated: 2024/12/16 14:32:41 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 14:08:12 by sebferna          #+#    #+#              #
#    Updated: 2024/12/16 14:30:43 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

SRC = phonebook.cpp

OBJ = $(SRC:.cpp=.o)

CPP = g++

CPPF = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
		@$(CPP) $(CPPF) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME) $(OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re