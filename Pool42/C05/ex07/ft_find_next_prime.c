/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:49:25 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/14 17:06:22 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / i))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (nb >= 2)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
}

/* int	main(void)
{
	int	primo;
	int	primo2;
	int	primo3;

	primo = 245678906;
	printf("El siguiente primo de %d es %d\n", primo,
		ft_find_next_prime(primo));
	primo2 = 7;
	printf("El siguiente primo de %d es %d\n", primo2,
		ft_find_next_prime(primo2));
	primo3 = 32;
	printf("El siguiente primo de %d es %d\n", primo3,
		ft_find_next_prime(primo3));
	return (0);
} */
