# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 19:08:48 by sebferna          #+#    #+#              #
#    Updated: 2025/06/26 19:41:39 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

cpps = 	main.cpp\
		ClapTrap.cpp\
		ScavTrap.cpp\
		FragTrap.cpp

CPP = g++

CPPF = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJ = $(cpps:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
		@$(CPP) $(CPPF) $(OBJ)

%.o : %.c
		@$(CPP) $(CPPF) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean:
	@$(RM) $(NAME) $(OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re