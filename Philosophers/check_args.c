/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:34:29 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/08 11:27:45 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (EXIT_SUCCES);
	return (EXIT_FAILURE);
}

int	check_args(int argc, char **str)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (printf("Error: Invalid number of Arguments"));
	i = 0;
	j = 0;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
			if (is_digit(str[i][j]) == 1)
				return (EXIT_FAILURE);
	}
	if (ft_atoi(str[1]) < 1 || ft_atoi(str[1]) > 200 || ft_atoi(str[2]) == 0
		|| ft_atoi(str[3]) == 0 || ft_atoi(str[4]) == 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCES);
}
