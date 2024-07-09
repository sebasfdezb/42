/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:53:10 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:25:01 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_columns(char *line, t_game *game, int fd, char *map_name)
{
	int	i;

	i = 0;
	fd = open(map_name, 0);
	line = get_next_line(fd);
	while (i < game->lines)
	{
		game->columns = ft_strlen(line);
		if (line[game->columns - 1] != '\n')
			game->columns++;
		game->map[i] = ft_calloc(game->columns, sizeof(char *));
		game->map_copy[i] = ft_calloc(game->columns, sizeof(char *));
		if (!game->map || !game->map_copy)
			return (free(line), EXIT_FAILURE);
		ft_strlcpy(game->map[i], line, game->columns);
		ft_strlcpy(game->map_copy[i], line, game->columns);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	game->columns--;
	game->map[i] = NULL;
	game->map_copy[i] = NULL;
	return (close(fd), free(line), EXIT_SUCCESS);
}

static int	read_lines(char *line, t_game *game, int fd, char *map_name)
{
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Error: Empty Map\n"), EXIT_FAILURE);
	while (line != NULL)
	{
		game->lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	game->map = ft_calloc(game->lines + 1, sizeof(char *));
	game->map_copy = ft_calloc(game->lines + 1, sizeof(char *));
	if (game->map == NULL || game->map_copy == NULL)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	close(fd);
	if (read_columns(line, game, fd, map_name) == 1)
		return (free(line), EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(map_name, 0);
	if (fd < 0)
		return (ft_printf("Error: Could not Open the Map\n"), EXIT_FAILURE);
	if (read_lines(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
