/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:37:57 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/08 20:11:01 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	num;

	num = 1;
	if (power < 0)
		return (0);
	else if (nb == 0 && power == 0)
		return (1);
	else
	{
		while (power > 0)
		{
			num = num * nb;
			power--;
		}
	}
	return (num);
}

/*int	main(void)
{
	int	num;
	int	power;

	num = 0;
	power = 0;
	printf("El numero %d elevado a %d = %d", num, power,
	ft_iterative_power(num,power));
	return (0);
}*/
