# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/03 19:24:55 by sebferna          #+#    #+#              #
#    Updated: 2025/06/29 20:16:33 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Weapon

cpps = 	main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp\

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