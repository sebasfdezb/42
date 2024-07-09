/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:32:44 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:41:02 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	read_columns(char *line, t_game *game, int fd, char *map_name)
{
	int	i;

	i = -1;
	fd = open(map_name, 0);
	line = get_next_line(fd);
	while (++i < game->lines)
	{
		game->columns = ft_strlen(line);
		if (line[game->columns - 1] != '\n')
			game->columns++;
		game->map[i] = ft_calloc(game->columns, sizeof(char *));
		game->map_copy[i] = ft_calloc(game->columns, sizeof(char *));
		ft_strlcpy(game->map[i], line, game->columns);
		ft_strlcpy(game->map_copy[i], line, game->columns);
		free(line);
		line = get_next_line(fd);
	}
	game->columns--;
	game->map[i] = NULL;
	game->map_copy[i] = NULL;
	return (close(fd), free(line), EXIT_SUCCESS);
}

static int	read_lines(char *line, t_game *game, int fd, char *map_name)
{
	fd = open(map_name, 0);
	line = get_next_line(fd);
	if (line == NULL)
		return (ft_printf("Error: Empty Map\n"), EXIT_FAILURE);
	free(line);
	while (line != NULL)
	{
		game->lines++;
		line = get_next_line(fd);
		free(line);
	}
	game->map = ft_calloc(game->lines + 1, sizeof(char *));
	game->map_copy = ft_calloc(game->lines + 1, sizeof(char *));
	if (!game->map || !game->map_copy)
		return (free(line), EXIT_FAILURE);
	close(fd);
	if ((read_columns(line, game, fd, map_name)) == 1)
		return (free(line), EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}

int	read_map(t_game *game, char *map_name)
{
	int		fd;
	char	*line;

	line = 0;
	fd = open (map_name, 0);
	if (fd < 0)
		return (ft_printf("Could not open the Map\n"), EXIT_FAILURE);
	if (read_lines(line, game, fd, map_name) == 1)
		return (EXIT_FAILURE);
	else
		return (EXIT_SUCCESS);
}
