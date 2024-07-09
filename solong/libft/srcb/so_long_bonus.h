/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:44:12 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:42:33 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_game
{
	char			**map;
	char			**map_copy;
	int				lines;
	int				columns;
	int				coin;
	int				coin_copy;
	int				player;
	int				enemy;
	int				exit;
	int				exit_copy;
	int				moves;
	t_point			local_exit;
	t_point			p_position;
	t_point			e_position;
	mlx_t			*mlx;
	mlx_texture_t	*text_closehouse;
	mlx_image_t		*img_closehouse;
	mlx_texture_t	*text_openhouse;
	mlx_image_t		*img_openhouse;
	mlx_texture_t	*text_enemy;
	mlx_image_t		*img_enemy;
	mlx_texture_t	*text_floor;
	mlx_image_t		*img_floor;
	mlx_texture_t	*text_wall;
	mlx_image_t		*img_wall;
	mlx_texture_t	*text_coin;
	mlx_image_t		*img_coin;
	mlx_texture_t	*text_p_right;
	mlx_image_t		*img_p_right;
	mlx_texture_t	*text_p_left;
	mlx_image_t		*img_p_left;
	double			enemy_move_timer;
}	t_game;

int			check_format(char *map_name);
int			read_map(t_game *game, char *map_name);
int			check_map(t_game *game);
int			texture_to_image(t_game *game);
int			image_to_window(t_game *game);
void		player_move(mlx_key_data_t keydata, void *param);
void		enemy_move(t_game *game);
void		valid_way_bonus(t_game *game, t_point current);

#endif
