/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:53:12 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:22:54 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_format(char *map_name)
{
	int	i;

	i = ft_strlen(map_name);
	if (map_name[i - 1] == 'r' && map_name[i - 2] == 'e'
		&& map_name[i - 3] == 'b' && map_name[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
