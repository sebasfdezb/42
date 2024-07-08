/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:37:07 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:37:07 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int n, int *length, char x)
{
	char	string[25];
	char	*base;
	int		i;

	if (x == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', length);
		return ;
	}
	while (n != 0)
	{
		string[i] = base[n % 16];
		n = n / 16;
		i++;
	}
	while (i--)
		ft_putchar(string[i], length);
}
