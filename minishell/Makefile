# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:47:50 by sebferna          #+#    #+#              #
#    Updated: 2024/11/07 19:21:31 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = 

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS): src/%.o : src/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -s -C $(LIBFT_DIR)

all: $(NAME)

clean:
		@rm -f $(OBJS)
		@make clean -s -C $(LIBFT_DIR)

fclean:
		@rm -f $(NAME) $(OBJS)
		@make fclean -s -C $(LIBFT_DIR)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean

