# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 12:12:29 by sebferna          #+#    #+#              #
#    Updated: 2024/07/01 12:12:29 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

PRINTF_DIR = ft_printf
PRINTF_LIB = libftprintf.a
PRINTF_INC = ft_printf.h

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -L$(PRINTF_DIR) -lftprintf

all: $(SERVER) $(CLIENT)

$(SERVER): server.c
	@make -s -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) -I$(PRINTF_DIR) server.c -o $(SERVER) $(LIBS)
	@echo "Server is Ready!"

$(CLIENT): client.c
	@make -s -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) -I$(PRINTF_DIR) client.c -o $(CLIENT) $(LIBS)
	@echo "Client is Ready!"

clean:
	@make clean -s -C $(PRINTF_DIR)
	@rm -f $(SERVER) $(CLIENT)

fclean: clean
	@make fclean -s -C $(PRINTF_DIR)
	@rm -f $(SERVER) $(CLIENT)
	@echo "Server and Client Cleaned!"

re: fclean all