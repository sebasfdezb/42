/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:05:23 by sebferna          #+#    #+#             */
/*   Updated: 2024/07/22 13:05:23 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	conv_bin(char *str, int pid)
{
	int		i;
	int		base;
	char	lettr;

	i = 0;
	while (str[i])
	{
		base = 128;
		lettr = str[i];
		while (base > 0)
		{
			if (lettr >= base)
			{
				kill(pid, SIGUSR1);
				lettr = lettr - base;
			}
			else
				kill(pid, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (-1);
	pid = ft_atoi(argv[1]);
	conv_bin(argv[2], pid);
	return (0);
}
