/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:15:42 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:37:31 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
					&& game->map[k][i] != 'E' && game->map[k][i] != 'M')
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

int	check_enemies(t_game *game)
{
	int	i;
	int	line;

	line = game->lines - 1;
	while (--line != 0)
	{
		i = -1;
		while (++i <= game->columns - 1)
		{
			if (game->map[line][i] == 'M')
			{
				game->enemy++;
				game->e_position.x = i;
				game->e_position.y = line;
			}
		}
	}
	if (game->enemy != 1)
		return (ft_printf ("Error: Enemy\n"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
		return (ft_printf("Error: Incorrect number of Elements\n"),
			EXIT_FAILURE);
	if (check_elements(game) == 1)
		return (ft_printf("Error: Incorrect Element\n"), EXIT_FAILURE);
	if (check_wall(game) == 1)
		return (ft_printf("Error: Not surrounded by Walls\n"), EXIT_FAILURE);
	valid_way_bonus(game, game->p_position);
	if (game->coin != game->coin_copy || game->exit != game->exit_copy)
		return (ft_printf("Error: Way is not valid\n"), EXIT_FAILURE);
	if (check_enemies(game) == 1)
		return (EXIT_FAILURE);
	game->coin = 0;
	return (EXIT_SUCCESS);
}
