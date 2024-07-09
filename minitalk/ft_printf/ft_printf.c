/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:29:21 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/09 13:39:35 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_filter(char str, va_list *args, int *leng)
{
	if (str == 'c')
		ft_putchar(va_arg(*args, int), leng);
	if (str == 's')
		ft_putstr(va_arg(*args, char *), leng);
	if (str == 'x')
		ft_puthexa(va_arg(*args, unsigned int), leng, 'x');
	if (str == 'X')
		ft_puthexa(va_arg(*args, unsigned int), leng, 'X');
	if (str == 'p')
		ft_printptr(va_arg(*args, unsigned int), leng);
	if (str == 'd')
		ft_putnbr(va_arg(*args, int), leng);
	if (str == 'i')
		ft_putnbr(va_arg(*args, int), leng);
	if (str == '%')
		ft_putchar('%', leng);
	if (str == 'u')
		ft_printunsigned(va_arg(*args, unsigned int), leng);
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start (args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_filter(str[i], &args, &length);
		}
		else
		{
			if (write(1, &str[i], 1) < 0)
				return (-1);
			length++;
		}
		i++;
	}
	va_end (args);
	return (length);
}

/* int	main(void)
{
	printf(" %d\n %s\n %d\n %lx\n %%\n 
		Mi printf:\n", 15, "UWU ONICHAN", 2000000, 1092939798378);
	ft_printf(" %d\n %s\n %p\n %x\n %%\n", 
		15, "UWU ONICHAN", 2000000, 1092939798378);
	return (0);
} */
