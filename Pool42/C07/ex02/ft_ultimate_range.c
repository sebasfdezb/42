/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:43:30 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:14 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*rango;
	int	size;
	int	i;
	int	min2;

	*range = NULL;
	if (min >= max)
		return (0);
	i = 0;
	size = max - min;
	min2 = min;
	rango = malloc(sizeof(int) * size - 1);
	if (rango == NULL)
		return (-1);
	*range = rango;
	while (min2 < max)
	{
		rango[i] = min2;
		min2++;
		i++;
	}
	return (size);
}

/* int	main(void)
{
	int	*rango = NULL;
	int	min;
	int	max;
	int	size;
	int i;

	min = 11;
	max = 12;
	i = 0;
	size = ft_ultimate_range(&rango, min, max);
	printf("El arrays tiene: %d digitos\n", size);
	while (i < size)
	{
		printf("%d", rango[i]);
		i++;
	}
	return (0);
} */
