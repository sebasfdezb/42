/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:41:59 by sebferna          #+#    #+#             */
/*   Updated: 2024/01/08 11:24:07 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long int nbr)
{
	int		result;
	char	c;

	result = 0;
	if (nbr < 0)
	{
		result += ft_putchar('-');
		if (result == -1)
			return (-1);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		result += ft_putnbr(nbr / 10);
		if (result == -1)
			return (-1);
	}
	c = nbr % 10 + '0';
	result += ft_putchar(c);
	if (result == -1)
		return (-1);
	return (result);
}

int	ft_printunsigned(unsigned long int nbr)
{
	int	cont;
	int	aux;

	cont = 0;
	aux = 0;
	if (nbr >= 0 && nbr <= 9)
	{
		aux += ft_putchar(nbr + '0');
		if (aux == -1)
			return (-1);
		cont += aux;
	}
	else
	{
		aux = ft_printunsigned(nbr / 10);
		if (aux == -1)
			return (-1);
		cont += aux;
		aux = ft_printunsigned(nbr % 10);
		if (aux == -1)
			return (-1);
		cont += aux;
	}
	return (cont);
}

int	ft_printhexa(unsigned long nbr, char c)
{
	int	cont;

	cont = 0;
	if (nbr >= 16)
	{
		cont += ft_printhexa(nbr / 16, c);
		if (cont == -1)
			return (-1);
	}
	if (c == 'x')
	{
		cont += ft_putchar("0123456789abcdef"[nbr % 16]);
		if (cont == -1)
			return (-1);
	}
	else if (c == 'X')
	{
		cont += ft_putchar("0123456789ABCDEF"[nbr % 16]);
		if (cont == -1)
			return (-1);
	}
	return (cont);
}

int	ft_printptr(unsigned long nbr)
{
	int	cont;

	cont = 0;
	cont += ft_putstr("0x");
	if (cont == -1)
		return (-1);
	cont += ft_printhexa(nbr, 'x');
	if (cont == -1)
		return (-1);
	return (cont);
}
