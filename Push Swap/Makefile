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
NAME_BONUS = checker

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

SRCS_BONUS = srcb/checker_bonus.c\
			srcb/free_bonus.c\
			srcb/check_arg_bonus.c\
			srcb/fill_stack_bonus.c\
			srcb/movement_bonus.c\
			srcb/movement2_bonus.c\
			srcb/movement3_bonus.c\
			srcb/algo_utils_bonus.c\
			srcb/algo_utils2_bonus.c\
			srcb/algo_utils3_bonus.c\
			srcb/algo_bonus.c\

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
		@$(LIB) $(PUSH_SWAP) $(OBJS)
		@$(CC) $(CFLAGS) $(PUSH_SWAP) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)

$(OBJS): src/%.o : src/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): srcb/%.o : srcb/%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		@make -s -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
		@rm -f $(OBJS) $(OBJS_BONUS)
		@make clean -s -C $(LIBFT_DIR)

fclean:
		@rm -f $(NAME) $(NAME_BONUS) $(OBJS) $(OBJS_BONUS) $(LIBFT) $(PUSH_SWAP)
		@make fclean -s -C $(LIBFT_DIR)

re: fclean all

pipe: all clean

.PHONY: all re fclean clean bonus