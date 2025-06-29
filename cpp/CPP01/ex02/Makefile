# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 20:27:52 by sebferna          #+#    #+#              #
#    Updated: 2025/06/29 20:03:08 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = main

cpps = 	main.cpp

CPP = g++

CPPF = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJ = $(cpps:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CPP) $(CPPF) $(OBJ) -o $(NAME)

%.o : %.c
		@$(CPP) $(CPPF) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME) $(OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re