/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:14:19 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/08 17:42:23 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i] != '\0')
	{
		cont++;
		i++;
	}
	return (cont);
}

/*int	main(void)
{
	char	a[] = "hola";

	printf("%d\n", ft_strlen(a));
	printf("%lu\n", strlen(a));
	return (0);
}*/
