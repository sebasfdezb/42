/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:41:23 by sebferna          #+#    #+#             */
/*   Updated: 2023/12/18 14:52:51 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_putchar(char s)
{
	if (write(1, &s, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putnbr(long int nbr)
{
	int	cont;

	cont = 0;
	if (nbr < 0)
	{
		cont++;
		nbr = -nbr;
		if (ft_putchar('-') == -1)
			return (-1);
		cont += ft_putnbr(nbr);
	}
	else if (nbr > 9)
	{
		cont += ft_putnbr(nbr / 10);
		cont += ft_putnbr(nbr % 10);
	}
	else
	{
		if (ft_putchar(nbr + 48) == -1)
			return (-1);
		cont++;
	}
	return (cont);
}

/* int	main(void)
{
	printf("%d\n", ft_putstr("hola"));
	printf("%d\n", ft_putchar('h'));
	printf("%d\n", ft_putnbr(-2147483648));
	return (0);
} */
