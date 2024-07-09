/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 10:09:15 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:40:05 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	images(t_game *g, int x, int y, void *img)
{
	if (g->map[g->p_position.y][g->p_position.x] == 'E')
		mlx_image_to_window(g->mlx, g->img_closehouse, g->p_position.x * 48,
			g->p_position.y * 48);
	if (g->map[g->p_position.y][g->p_position.x] != 'E'
		&& g->map[g->p_position.y][g->p_position.x] != '1')
		mlx_image_to_window(g->mlx, g->img_floor, g->p_position.x * 48,
			g->p_position.y * 48);
	g->p_position.x = x;
	g->p_position.y = y;
	if (g->map[g->p_position.y][g->p_position.x] == 'C')
	{
		mlx_image_to_window(g->mlx, g->img_floor, g->p_position.x * 48,
			g->p_position.y * 48);
		g->map[g->p_position.y][g->p_position.x] = '0';
		g->coin++;
		if (g->coin == g->coin_copy)
			mlx_image_to_window(g->mlx, g->img_openhouse, g->local_exit.x * 48,
				g->local_exit.y * 48);
	}
	mlx_image_to_window(g->mlx, img, g->p_position.x * 48,
		g->p_position.y * 48);
}

static void	cont(t_game *game)
{
	char	*cont;

	cont = ft_itoa(game->moves);
	mlx_image_to_window(game->mlx, game->img_floor, 0, 0);
	mlx_put_string(game->mlx, cont, 16, 10);
	free(cont);
}

static void	keypress(t_game *g, int x, int y, void *img)
{
	if (g->map[y][x] == 'E' && g->coin == g->coin_copy)
	{
		mlx_close_window(g->mlx);
		ft_printf("\n");
		ft_printf("WINNER!\n");
		ft_printf("\n");
	}
	else if (g->map[y][x] == 'E' || g->map[y][x] == 'C' || g->map[y][x] != '1')
	{
		images(g, x, y, img);
		g->moves++;
		cont(g);
	}
}

void	player_move(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x - 1, game->p_position.y,
			game->img_p_left);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y + 1,
			game->img_p_left);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x + 1, game->p_position.y,
			game->img_p_right);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		keypress(game, game->p_position.x, game->p_position.y - 1,
			game->img_p_right);
}
