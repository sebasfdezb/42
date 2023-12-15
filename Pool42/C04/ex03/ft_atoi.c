/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:58:06 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/08 17:42:33 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_spaces(char *str, int *pi)
{
	int	cont;
	int	i;

	i = 0;
	cont = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
		{
			cont = cont * -1;
		}
		i++;
	}
	*pi = i;
	return (cont);
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = ft_spaces(str, &i);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 +(str[i] - '0');
		i++;
	}
	num = num * sign;
	return (num);
}

/*int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
    char	*cadena = argv[1];
    int	resultado = ft_atoi(cadena);
	int	resul = atoi(cadena);
    printf("ft_atoi: %d\n", resultado);
	printf("atoi: %d\n", resul);
    return (0);
}*/
