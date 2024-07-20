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
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

LIBFT_DIR = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBS = -L$(LIBFT_DIR) -lft

all: $(SERVER) $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER): server.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) server.c -o $(SERVER) $(LIBS)
	@echo "Server is Ready!"

$(CLIENT): client.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) client.c -o $(CLIENT) $(LIBS)
	@echo "Client is Ready!"

$(SERVER_BONUS): server_bonus.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) server_bonus.c -o $(SERVER_BONUS) $(LIBS)
	@echo "Server Bonus is Ready!"

$(CLIENT_BONUS): client_bonus.c
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -I$(LIBFT_DIR) client_bonus.c -o $(CLIENT_BONUS) $(LIBS)
	@echo "Client Bonus is Ready!"

clean:
	@make clean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	@echo "Server and Client Cleaned!"

re: fclean all
