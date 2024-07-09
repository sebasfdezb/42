/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_to_image_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:44:07 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:44:07 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	clean_textures(t_game *game)
{
	mlx_delete_texture(game->text_closehouse);
	mlx_delete_texture(game->text_openhouse);
	mlx_delete_texture(game->text_floor);
	mlx_delete_texture(game->text_coin);
	mlx_delete_texture(game->text_wall);
	mlx_delete_texture(game->text_p_left);
	mlx_delete_texture(game->text_p_right);
	mlx_delete_texture(game->text_enemy);
}

static int	image_error(t_game *game)
{
	if (!game->img_closehouse || !game->img_openhouse || !game->img_floor
		|| !game->img_coin || !game->img_floor || !game->img_wall
		|| !game->img_p_left || !game->img_p_right
		|| !game->text_closehouse || !game->text_openhouse
		|| !game->text_floor || !game->text_coin || !game->text_wall
		|| !game->text_p_left || !game->text_p_right
		|| !game->text_enemy || !game->img_enemy)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	texture_to_image(t_game *game)
{
	game->text_closehouse = mlx_load_png("./images/closehouse.png");
	game->text_openhouse = mlx_load_png("./images/openhouse.png");
	game->text_floor = mlx_load_png("./images/floor.png");
	game->text_wall = mlx_load_png("./images/wall.png");
	game->text_coin = mlx_load_png("./images/coin.png");
	game->text_p_right = mlx_load_png("./images/mario_right.png");
	game->text_p_left = mlx_load_png("./images/mario_left.png");
	game->text_enemy = mlx_load_png("./images/enemy.png");
	game->img_closehouse = mlx_texture_to_image(game->mlx,
			game->text_closehouse);
	game->img_openhouse = mlx_texture_to_image(game->mlx, game->text_openhouse);
	game->img_floor = mlx_texture_to_image(game->mlx, game->text_floor);
	game->img_wall = mlx_texture_to_image(game->mlx, game->text_wall);
	game->img_coin = mlx_texture_to_image(game->mlx, game->text_coin);
	game->img_p_right = mlx_texture_to_image(game->mlx, game->text_p_right);
	game->img_p_left = mlx_texture_to_image(game->mlx, game->text_p_left);
	game->img_enemy = mlx_texture_to_image(game->mlx, game->text_enemy);
	clean_textures(game);
	if (image_error(game) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
