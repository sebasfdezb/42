/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:22:02 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/10 12:22:02 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

static void	ft_putcchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnmbr(int num)
{
	if (num > 9)
	{
		ft_putnmbr(num / 10);
		num = num % 10;
	}
	if (num <= 9)
		ft_putcchar(('0' + num));
}

void	conv_txt(char *str)
{
	int		i;
	int		base;
	char	bit;
	int		control;
	int		result;

	i = 7;
	while (str[i])
	{
		base = 1;
		control = i;
		result = 0;
		while (base <= 128)
		{
			bit = str[control];
			if (bit == '1')
				result = result + base;
			base = base * 2;
			control--;
		}
		write(1, &result, 1);
		i += 16;
	}
}

void	alm_bit(int sig)
{
	static int	i = 0;
	static char	c[9];

	if (sig == SIGUSR1)
		c[i] = '1';
	else if (sig == SIGUSR2)
		c[i] = '0';
	i++;
	if (i == 8)
	{
		c[i] = '\0';
		conv_txt(c);
		i = 0;
	}
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnmbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, alm_bit);
	signal(SIGUSR2, alm_bit);
	while (1)
		pause();
	return (0);
}
