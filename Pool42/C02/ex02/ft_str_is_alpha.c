/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:11:56 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/03 12:42:52 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;
	int	numero;

	i = 0;
	numero = 1;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str [i] >= 'a' && str[i] <= 'z')))
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
	printf("%d", ft_str_is_alpha("3hola"));
	return (0);
}*/
