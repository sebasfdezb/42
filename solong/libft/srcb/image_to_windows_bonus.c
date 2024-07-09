/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_windows_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:23:02 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:38:37 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	image_to_window(t_game *g)
{
	int	i;
	int	j;

	j = 0;
	while (g->map[j] != NULL)
	{
		i = 0;
		while (g->map[j][i] != '\n' && g->map[j][i] != '\0')
		{
			mlx_image_to_window(g->mlx, g->img_floor, i * 48, j * 48);
			if (g->map[j][i] == '1')
				mlx_image_to_window(g->mlx, g->img_wall, i * 48, j * 48);
			if (g->map[j][i] == 'C')
				mlx_image_to_window(g->mlx, g->img_coin, i * 48, j * 48);
			if (g->map[j][i] == 'P')
				mlx_image_to_window(g->mlx, g->img_p_left, i * 48, j * 48);
			if (g->map[j][i] == 'E')
				mlx_image_to_window(g->mlx, g->img_closehouse, i * 48, j * 48);
			if (g->map[j][i] == 'M')
				mlx_image_to_window(g->mlx, g->img_enemy, i * 48, j * 48);
			i++;
		}
		j++;
	}
	return (EXIT_SUCCESS);
}
