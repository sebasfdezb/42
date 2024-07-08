/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:06:49 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/01 11:06:49 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"

void	send_bit(int pid, char *str, size_t len)
{
	int		move;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		move = 0;
		while (move < 7)
		{
			if ((str[i] >> move) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			move++;
			usleep(30);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nEsta Vacio o Hay mas de 1 Palabra");
	return (0);
}