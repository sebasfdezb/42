/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:55:33 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/07 11:14:35 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;
	int	cont;

	cont = 0;
	i = 0;
	while (str[i] != '\0')
	{
		cont++;
		i++;
	}
	return (cont);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	longdest;
	unsigned int	longsrc;
	unsigned int	i;

	i = 0;
	longdest = ft_strlen(dest);
	longsrc = ft_strlen(src);
	if (longdest >= size)
		return (size + longsrc);
	while (src[i] != '\0' && i < size - longdest - 1)
	{
		dest[longdest + i] = src[i];
		i++;
	}
	dest[longdest + i] = '\0';
	return (longdest + longsrc);
}

/*int	main(void)
{
	char a[] = "hola";
	char b[] = "mundo";
	int	size = 3;
	printf("%u\n", ft_strlcat(b, a, size));
	printf("%lu", strlcat(b, a, size));
	return (0);
}*/
