/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:48:18 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/12 11:48:18 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argv(char **arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i] != NULL)
	{
		while (arg[i][j] != '\0')
		{
			if (arg[i][j + 1] == '-' || arg[i][j + 1] == '+')
				return (EXIT_FAILURE);
			else if (arg[i][j] == '-' || arg[i][j] == '+')
				j++;
			else if (ft_isdigit(arg[i][j]))
				return (EXIT_FAILURE);
			j++;
		}
		if (ft_atoi(arg[i]) <= MIN_INT || ft_atoi(arg[i]) >= MAX_INT)
			return (EXIT_FAILURE);
		j = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	check_rep(char **arg)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	f = 0;
	while (arg[i] != NULL)
	{
		while (arg[j] != NULL)
		{
			if (ft_atol(arg[i]) == ft_atol(arg[j]))
				f++;
			if (f > 1)
				return (EXIT_FAILURE);
			j++;
		}
		j = 0;
		f = 0;
		i++;
	}
	return (EXIT_SUCCESS);
}
