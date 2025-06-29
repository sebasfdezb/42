# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/02 19:49:36 by sebferna          #+#    #+#              #
#    Updated: 2025/06/29 20:00:16 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombieHorde

cpps = 	main.cpp\
		zombieHorde.cpp\
		Zombie.cpp

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