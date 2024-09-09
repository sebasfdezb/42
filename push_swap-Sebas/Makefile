# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 11:34:50 by sebferna          #+#    #+#              #
#    Updated: 2024/08/28 11:34:50 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

PUSH_SWAP = push_swap.a

LIB = ar rcs

SRCS = src/push_swap.c\
		src/check_arg.c\
		src/fill_stack.c\
		src/movement.c\
		src/movement2.c\
		src/movement3.c\
		src/algo_utils.c\
		src/algo_utils2.c\
		src/algo_utils3.c\
		src/algo.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
		@$(LIB) $(PUSH_SWAP) $(OBJS)
		@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(OBJS): src/%.o : src/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -s -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
		@rm -f $(OBJS)
		@make clean -s -C $(LIBFT_DIR)

fclean:
		@rm -f $(NAME) $(OBJS) $(LIBFT) $(PUSH_SWAP)
		@make fclean -s -C $(LIBFT_DIR)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean bonus