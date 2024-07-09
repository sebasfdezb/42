/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_way_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 12:22:53 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:44:43 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	valid_way_bonus(t_game *game, t_point current)
{
	if (current.x >= game->columns || current.y >= game->lines || current.x < 0
		|| current.y < 0 || game->map_copy[current.y][current.x] == '1'
		|| game->map_copy[current.y][current.x] == '*')
		return ;
	if (game->map_copy[current.y][current.x] == 'C')
		game->coin_copy++;
	if (game->map_copy[current.y][current.x] == 'E')
	{
		game->exit_copy++;
		game->local_exit.y = current.y;
		game->local_exit.x = current.x;
	}
	game->map_copy[current.y][current.x] = '*';
	valid_way_bonus(game, (t_point){current.x - 1, current.y});
	valid_way_bonus(game, (t_point){current.x + 1, current.y});
	valid_way_bonus(game, (t_point){current.x, current.y - 1});
	valid_way_bonus(game, (t_point){current.x, current.y + 1});
}
