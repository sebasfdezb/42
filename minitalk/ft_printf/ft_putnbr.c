/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:37:47 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:37:47 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nmb, int *length)
{
	if (nmb == -2147483648)
	{
		write(1, "-2147483648", 11);
		(*length) += 11;
		return ;
	}
	if (nmb < 0)
	{
		ft_putchar('-', length);
		ft_putnbr(nmb * -1, length);
	}
	else
	{
		if (nmb > 9)
			ft_putnbr(nmb / 10, length);
		ft_putchar(nmb % 10 + '0', length);
	}
}
