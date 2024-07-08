/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:36:20 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:36:20 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunsigned(unsigned int n, int *length)
{
	if (n >= 10)
		ft_printunsigned(n / 10, length);
	if (*length == -1)
		return ;
	ft_putchar(n % 10 + '0', length);
}
