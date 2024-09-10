/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:29:20 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/31 11:50:46 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	num;
	int	sign;

	a = 0;
	num = 0;
	sign = 0;
	while (str[a] == 32 || (str[a] >= 9 && str[a] <= 13))
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			sign++;
		a++;
	}
	while (str[a] && (str[a] >= '0' && str[a] <= '9'))
	{
		num = num * 10 + (str[a] - '0');
		a++;
	}
	if (sign % 2 == 1)
		return (num * -1);
	return (num);
}

/* int	main(void)
{
	char a[] = "-2147483648";
	printf("%d", ft_atoi(a));
	return (0);
} */
