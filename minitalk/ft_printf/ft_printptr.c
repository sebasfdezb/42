/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:36:36 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:22:15 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(int ptr, int *length)
{
	char	string[25];
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = 0;
	write(1, "0x", 2);
	(*length) += 2;
	if (ptr == 0)
	{
		ft_putchar('0', length);
		return ;
	}
	while (ptr != 0)
	{
		string[i] = base[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i--)
		ft_putchar(string[i], length);
}
