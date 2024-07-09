# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 12:25:20 by sebferna          #+#    #+#              #
#    Updated: 2024/06/25 12:25:20 by sebferna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_BONUS = so_long_bonus

FLAGS = -Wall -Werror -Wextra

FILES = src/check_format.c\
		src/check_map.c\
		src/read_map.c\
		src/so_long.c\
		src/texture_to_image.c\
		src/image_to_window.c\
		src/player.c\

BONUS = srcb/check_format_bonus.c\
		srcb/check_map_bonus.c\
		srcb/enemy_move_bonus.c\
		srcb/image_to_windows_bonus.c\
		srcb/player_move_bonus.c\
		srcb/read_map_bonus.c\
		srcb/so_long_bonus.c\
		srcb/texture_to_image_bonus.c\
		srcb/valid_way_bonus.c\

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

LIBFT_PATH = ./libft

MLX_PATH = ./MLX42

LIBFT = $(LIBFT_PATH)/libft.a

MLX = $(MLX_PATH)/libmlx42.a

SO_LONG = so_long.a

LIB_SYS = -Iinclude -lglfw -L "/Users/sebferna/.brew/opt/glfw/lib/"


$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	gcc $(FLAGS) $(OBJS) -lglfw $(MLX) $(LIBFT) $(LIB_SYS) -o $(NAME)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT) $(MLX)
	gcc $(FLAGS) $(BONUS) $(LIBFT) $(MLX) $(LIB_SYS) -o $(NAME_BONUS)

$(LIBFT) :
	@make -s -C $(LIBFT_PATH)

$(MLX) :
	@make -s -C $(MLX_PATH)

$(OBJS) : src/%.o : src/%.c
	@gcc $(FLAGS) -c $< -o $@

$(OBJS_BONUS) : srcb/%.o : srcb/%.c
	@gcc $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	@rm -fr $(OBJS) $(OBJS_BONUS)
	@make clean -s -C $(LIBFT_PATH)
	@make clean -s -C $(MLX_PATH)

fclean: clean
	@rm -fr $(NAME) $(NAME_BONUS)
	@make fclean -s -C $(LIBFT_PATH)
	@make fclean -s -C $(MLX_PATH)

re: fclean all

.PHONY : all clean fclean re bonus
