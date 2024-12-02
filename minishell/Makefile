# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/07 12:47:50 by sebferna          #+#    #+#              #
#    Updated: 2024/12/02 18:27:31 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = src/minishell.c\
		src/mini_utils/builtins/cd.c\
		src/mini_utils/builtins/echo.c\
		src/mini_utils/builtins/envp.c\
		src/mini_utils/builtins/exit.c\
		src/mini_utils/builtins/pwd.c\
		src/mini_utils/builtins/unset.c\
		src/mini_utils/exec/error_msg.c\
		src/mini_utils/exec/ex_route.c\
		src/mini_utils/exec/executor.c\
		src/mini_utils/exec/pipe.c\
		src/mini_utils/exec/routes.c\
		src/mini_utils/free/free.c\
		src/mini_utils/free/free_all.c\
		src/mini_utils/parsing/expander.c\
		src/mini_utils/parsing/here_doc.c\
		src/mini_utils/parsing/lexer.c\
		src/mini_utils/parsing/parsing_utils.c\
		src/mini_utils/parsing/parsing.c\
		src/mini_utils/utilss/export.c\
		src/mini_utils/utilss/split_words.c\
		src/mini_utils/utilss/split_cmds.c\
		src/mini_utils/utilss/splits.c\
		src/mini_utils/utilss/utils.c\

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

