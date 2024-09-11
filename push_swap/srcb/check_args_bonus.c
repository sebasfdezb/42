/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:31:41 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 11:31:47 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_args(char **argv, int argc)
{
	int	i;

	i = -1;
	while (++i < argc)
	{
		if (check_num(argv[i + 1]) == -1 || *argv[i + 1] == '\0')
			return (-1);
	}
	return (0);
}
