/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:48:07 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/02 16:07:09 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;
	int	numero;

	i = 0;
	numero = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			numero = 0;
			break ;
		}
		i++;
	}
	return (numero);
}

/*int	main(void)
{
	char	*a;
	char	*b;
	char	*c;

	a = "á";
	b = "!";
	c = "a";
	printf("%d", ft_str_is_printable(a));
	printf("%d", ft_str_is_printable(b));
	printf("%d", ft_str_is_printable(c));
	return (0);
}*/