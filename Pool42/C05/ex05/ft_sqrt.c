/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:17:22 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/09 10:28:38 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	num;
	long	index;

	num = nb;
	index = 2;
	if (num < 0)
		return (0);
	if (num == 1)
		return (1);
	if (num >= 2)
	{
		while (index * index <= num)
		{
			if (index * index == num)
			{
				return (index);
			}
			index++;
		}
	}
	return (0);
}

/*int	main(void)
{
	int	sqrt;

	sqrt = 48;
	printf("La raiz de %d es %d", sqrt, ft_sqrt(sqrt));
	return (0);
}*/
