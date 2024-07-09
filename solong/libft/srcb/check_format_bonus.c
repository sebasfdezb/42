/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:33:12 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/26 11:37:03 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_format(char *map_name)
{
	int	i;

	i = ft_strlen (map_name);
	if (map_name[i - 1] == 'r' && map_name[i - 2] == 'e'
		&& map_name[i - 3] == 'b' && map_name[i - 4] == '.')
		return (EXIT_SUCCESS);
	else
		return (EXIT_FAILURE);
}
