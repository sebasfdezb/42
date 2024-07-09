/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:35:36 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:23:36 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines - 1;
	while (game->map[0][i] != '\0')
	{
		if (game->map[0][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (game->map[k][i] != '\0')
	{
		if (game->map[k][i] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	i--;
	while (k-- > 0)
	{
		if (game->map[k][0] != '1' || game->map[k][i] != '1')
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	check_elements(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines;
	while (--k >= 0)
	{
		while (game->map[k][i] != '\0')
		{
			if (game->map[k][i] != '1' && game->map[k][i] != '0'
				&& game->map[k][i] != 'C' && game->map[k][i] != 'P'
					&& game->map[k][i] != 'E')
				return (EXIT_FAILURE);
			i++;
		}
		i = 0;
	}
	return (EXIT_SUCCESS);
}

static int	count_objects(t_game *game)
{
	int	i;
	int	k;

	k = game->lines;
	while (--k > 0)
	{
		i = -1;
		while (game->map[k][++i] != '\0')
		{
			if (game->map[k][i] == 'C')
				game->coin++;
			else if (game->map[k][i] == 'P')
			{
				game->player++;
				game->p_position.x = i;
				game->p_position.y = k;
			}
			else if (game->map[k][i] == 'E')
				game->exit++;
		}
	}
	if (game->coin == 0 || game->player != 1 || game->exit != 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	valid_way(t_game *game, t_point size, t_point current)
{
	if (current.x >= size.x || current.y >= size.y || current.x < 0
		|| current.y < 0 || game->map_copy[current.y][current.x] == '1'
		|| game->map_copy[current.y][current.x] == '*')
		return ;
	if (game->map_copy[current.y][current.x] == 'C')
		game->coin_copy++;
	if (game->map_copy[current.y][current.x] == 'E')
	{
		game->exit_copy++;
		game->local_exit.x = current.x;
		game->local_exit.y = current.y;
	}
	game->map_copy[current.y][current.x] = '*';
	valid_way(game, size, (t_point){current.x - 1, current.y});
	valid_way(game, size, (t_point){current.x + 1, current.y});
	valid_way(game, size, (t_point){current.x, current.y - 1});
	valid_way(game, size, (t_point){current.x, current.y + 1});
}

int	check_map(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	k = game->lines;
	i = ft_strlen(game->map[0]);
	while (--k >= 0)
		if (i != ft_strlen(game->map[k]))
			return (ft_printf("Error: Non-Rectangular Map\n"), EXIT_FAILURE);
	if (count_objects(game) == 1)
		return (ft_printf("Error: Incorrect number of elements\n"),
			EXIT_FAILURE);
	if (check_elements(game) == 1)
		return (ft_printf("Error: Incorrect element\n"), EXIT_FAILURE);
	if (check_wall(game) == 1)
		return (ft_printf("Error: Not surrounded by walls\n"), EXIT_FAILURE);
	valid_way(game, (t_point){game->columns, game->lines}, game->p_position);
	if (game->coin != game->coin_copy || game->exit != game->exit_copy)
		return (ft_printf("Error: The way is not valid\n"), EXIT_FAILURE);
	game->coin = 0;
	return (EXIT_SUCCESS);
}
