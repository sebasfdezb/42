/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:38:14 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:38:14 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	move_previous_images(t_game *g)
{
	if (g->map[g->e_position.y][g->e_position.x] == 'E')
	{
		mlx_image_to_window(g->mlx, g->img_closehouse, g->e_position.x * 48,
			g->e_position.y * 48);
		if (g->coin == g->coin_copy)
			mlx_image_to_window(g->mlx, g->img_openhouse, g->e_position.x * 48,
				g->e_position.y * 48);
	}
	if (g->map[g->e_position.y][g->e_position.x] != 'E')
	{
		mlx_image_to_window(g->mlx, g->img_floor, g->e_position.x * 48,
			g->e_position.y * 48);
		if (g->map[g->e_position.y][g->e_position.x] == 'C'
			&& g->coin != g->coin_copy)
			mlx_image_to_window(g->mlx, g->img_coin, g->e_position.x * 48,
				g->e_position.y * 48);
	}
}

static void	move_images(t_game *g, int x, int y, void *img)
{
	if (g->map[y][x] != '1')
	{
		move_previous_images(g);
		g->e_position.x = x;
		g->e_position.y = y;
		if (g->map[g->e_position.y][g->e_position.x] == 'E')
		{
			mlx_image_to_window(g->mlx, g->img_closehouse, g->e_position.x * 48,
				g->e_position.y * 48);
			if (g->coin == g->coin_copy)
				mlx_image_to_window(g->mlx, g->img_openhouse,
					g->e_position.x * 48, g->e_position.y * 48);
		}
		if (g->map[g->e_position.y][g->e_position.x] != 'E')
		{
			mlx_image_to_window(g->mlx, g->img_floor, g->e_position.x * 48,
				g->e_position.y * 48);
			if (g->map[g->e_position.y][g->e_position.x] == 'C'
				&& g->coin != g->coin_copy)
				mlx_image_to_window(g->mlx, g->img_coin, g->e_position.x * 48,
					g->e_position.y * 48);
		}
		mlx_image_to_window(g->mlx, img, g->e_position.x * 48,
			g->e_position.y * 48);
	}
}

static void	calculate_direction(t_game *g, int *dx, int *dy)
{
	*dx = (g->p_position.x) - (g->e_position.x);
	*dy = (g->p_position.y) - (g->e_position.y);
}

static void	direction_enemy(t_game *g, int dx, int dy)
{
	if (dx > 0)
		move_images(g, g->e_position.x + 1, g->e_position.y, g->img_enemy);
	if (dx < 0)
		move_images(g, g->e_position.x - 1, g->e_position.y, g->img_enemy);
	if (dy > 0)
		move_images(g, g->e_position.x, g->e_position.y + 1, g->img_enemy);
	if (dy < 0)
		move_images(g, g->e_position.x, g->e_position.y - 1, g->img_enemy);
}

void	enemy_move(t_game *g)
{
	int	dx;
	int	dy;

	calculate_direction(g, &dx, &dy);
	g->enemy_move_timer += g->mlx->delta_time;
	if (g->enemy_move_timer >= 0.5)
	{
		direction_enemy(g, dx, dy);
		g->enemy_move_timer = 0;
	}
	if (g->e_position.x == g->p_position.x
		&& g->e_position.y == g->p_position.y)
	{
		ft_printf("\n");
		ft_printf("YOU DIE!\n");
		ft_printf("\n");
		mlx_close_window(g->mlx);
	}
}
