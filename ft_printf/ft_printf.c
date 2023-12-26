/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:29:21 by sebferna          #+#    #+#             */
/*   Updated: 2023/12/26 13:21:53 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_format(char const *s, int pos, va_list *ptr)
{
	int	cont;

	cont = 0;
	if (s[pos] == 'c')
		cont = ft_putchar(va_arg(*ptr, int));
	if (s[pos] == 's')
		cont = ft_putstr(va_arg(*ptr, char *));
	if (s[pos] == 'd' || s[pos] == 'i')
		cont = ft_putnbr(va_arg(*ptr, int));
	if (s[pos] == 'u')
		cont = ft_printunsigned(va_arg(*ptr, unsigned int));
	if (s[pos] == '%')
		cont = ft_putchar('%');
	if (s[pos] == 'p')
		cont = ft_printptr(va_arg(*ptr, unsigned long long));
	if (s[pos] == 'x' || s[pos] == 'X')
		cont = ft_printhexa(va_arg(*ptr, unsigned int), s[pos]);
	return (cont);
}

int	ft_printf(char const *s, ...)
{
	va_list	ptr;
	int		i;
	int		cont;

	va_start(ptr, s);
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			cont += ft_putchar(s[i]);
			if (cont == -1)
				return (-1);
		}
		else
		{
			i++;
			cont += ft_format(s, i, &ptr);
			if (cont == -1)
				return (-1);
		}
		i++;
	}
	return (va_end(ptr), cont);
}
