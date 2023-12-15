/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:43:57 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:26 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		lensrc;
	char	*memoria;
	int		i;

	i = 0;
	lensrc = ft_strlen(src);
	memoria = (char *)malloc(sizeof(char) * lensrc + 1);
	if (memoria == NULL)
		return (NULL);
	while (src[i])
	{
		memoria[i] = src[i];
		i++;
	}
	memoria[i] = '\0';
	return (memoria);
}

/* int	main(void)
{
	char	src[13] = "Hola que tal";
	char	src2[13] = "Hola que tal";
	char	*dest;
	char	*dest2;
	int		lensrc;
	int		lendest;

	dest = ft_strdup(src);
	dest2 = ft_strdup(src2);
	lensrc = ft_strlen(src);
	lendest = ft_strlen(dest);

	printf("Original: %s,  ->%d\n", src, lensrc);
	printf("Destino: %s,  ->%d\n", dest, lendest);
	write (1, "\n", 1);
	printf("ORIGINAL: %s, ->%d\n", src2, lensrc);
	printf("DESTINO: %s, ->%d\n", dest2, lendest);
	return (0);
}
 */