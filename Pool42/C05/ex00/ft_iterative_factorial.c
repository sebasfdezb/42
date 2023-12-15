/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:35 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:30 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	unsigned int	fact;

	fact = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 1)
	{
		fact = fact * nb;
		nb--;
	}
	return (fact);
}

/*int	main(void)
{
	int	num;
	int	fact;

	num = 5;
	fact = num;
	printf("El factorial de %d es %d", num, ft_iterative_factorial(fact));
	return (0);
}*/
