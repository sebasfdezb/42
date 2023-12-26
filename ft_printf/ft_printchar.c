/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:41:23 by sebferna          #+#    #+#             */
/*   Updated: 2023/12/26 12:50:19 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *s)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	if (!s)
	{
		cont += ft_putstr("(null)");
		return (cont);
	}
	while (s[i])
	{
		cont += ft_putchar(s[i]);
		if (cont == -1)
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
