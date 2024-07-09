/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:33:12 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:41:44 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*void	ft_leaks(void)
{
	system("leaks -q so_long");

	copiar esta: atexit(ft_leaks);
}*/

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
	game->exit = 0;
	game->exit_copy = 0;
	game->player = 0;
	game->moves = 0;
	game->enemy = 0;
}

static void	game_loop(void *param)
{
	t_game	*game;

	game = param;
	enemy_move(game);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (ft_printf ("Error: There is no Map\n"), EXIT_FAILURE);
	g = ft_calloc(1, sizeof(t_game));
	initialize(g);
	if (check_format(argv[1]) == 1)
		return (free_all(g), ft_printf ("Error: Incorrect Format\n"), 1);
	if (read_map(g, argv[1]) == 1)
		return (free_all(g), EXIT_FAILURE);
	if (check_map(g) == 1)
		return (free_all(g), EXIT_FAILURE);
	g->mlx = mlx_init(48 * g->columns, 48 * g->lines, "SO_LONG", true);
	if (!g->mlx)
		return (free_all(g), EXIT_FAILURE);
	if (texture_to_image(g) == 1 || image_to_window(g) == 1)
		return (free_all(g), ft_printf ("Error: Images\n"), EXIT_FAILURE);
	mlx_key_hook (g->mlx, &player_move, g);
	mlx_loop_hook (g->mlx, game_loop, g);
	mlx_resize_hook(g->mlx, &resize_window, NULL);
	mlx_loop(g->mlx);
	mlx_terminate(g->mlx);
	return (free_all(g), EXIT_SUCCESS);
}
