# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/09 19:32:49 by sebferna          #+#    #+#              #
#    Updated: 2024/10/10 12:05:31 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Werror -Wextra

SRC = philosophers.c\
		check_args.c\
		philo_utils.c\
		spectator.c\
		routine.c\
	
OBJS = $(SRC:.c=.o)

$(NAME):	$(OBJS)
		@ gcc $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS):	%.o : %.c
		@ gcc $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:			
		@rm -f $(OBJS)

fclean:			
		@rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all re fclean clean
