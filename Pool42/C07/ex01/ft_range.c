/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:38:48 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:21 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	size;
	int	min2;
	int	i;

	if (min >= max)
		return (0);
	i = 0;
	min2 = min;
	size = max - min;
	tab = (int *)malloc(sizeof(int) * size - 1);
	if (tab == NULL)
		return (0);
	while (min2 < max)
	{
		tab[i] = min2;
		min2++;
		i++;
	}
	return (tab);
}

/* int	main(void)
{
	int	max;
	int	min;
	int	*tab;
	int	size;
	int	i;

	i = 0;
	max = 0;
	min = -1;
	size = max - min;
	tab = ft_range(min, max);
	while (size != 0)
	{
		printf("%d", tab[i]);
		i++;
		size--;
	}
	return (0);
} */
