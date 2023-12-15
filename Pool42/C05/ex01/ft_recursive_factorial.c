/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:26:00 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/09 11:31:28 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	else if (nb == 0)
		return (1);
	else
	{
		nb = nb * ft_recursive_factorial(nb - 1);
	}
	return (nb);
}

/*int	main(void)
{
	int	num;
	int	fact;

	num = 0;
	fact = num;
	printf("El factorial de %d es %d", num, ft_recursive_factorial(fact));
	return (0);
}*/