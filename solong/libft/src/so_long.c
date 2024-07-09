/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:11:32 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:24:26 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	resize_window(int width, int height, void *param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

void	free_all(t_game *game)
{
	int	i;

	i = 0;
	if (game->map == NULL && game->map_copy == NULL)
		return (free(game));
	while (game->map[i] != NULL && game->map_copy[i] != NULL)
	{
		free(game->map[i]);
		free(game->map_copy[i]);
		i++;
	}
	free(game->map);
	free(game->map_copy);
	free(game);
}

static void	initialize(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->lines = 0;
	game->columns = 0;
	game->coin = 0;
	game->coin_copy = 0;
	game->player = 0;
	game->exit = 0;
	game->exit_copy = 0;
	game->moves = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_printf("Error: Map does not exist\n"), EXIT_FAILURE);
	game = ft_calloc(1, sizeof(t_game));
	initialize(game);
	if ((check_format(argv[1])) == 1)
		return (free_all(game),
			ft_printf("Error: Incorrect Format\n"), EXIT_FAILURE);
	if (read_map(game, argv[1]) == 1)
		return (free_all(game), EXIT_FAILURE);
	if (check_map(game) == 1)
		return (free_all(game), EXIT_FAILURE);
	game->mlx = mlx_init(48 * game->columns, 48 * game->lines,
			"SO_LONG", true);
	if (!game->mlx)
		return (free_all(game), EXIT_FAILURE);
	if (texture_to_image(game) == 1 || image_to_window(game) == 1)
		return (free_all(game), ft_printf("Error: Images\n"), EXIT_FAILURE);
	mlx_key_hook(game->mlx, &player_move, game);
	mlx_resize_hook(game->mlx, &resize_window, NULL);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (free_all(game), EXIT_SUCCESS);
}
