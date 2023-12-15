/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:25:30 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/15 10:36:12 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	str = (char *)malloc(sizeof(strs));
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k] = strs[i][j];
			k++;
			j++;
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
			str[k++] = sep[j++];
		i++;
	}
	str[k] = '\0';
	return (str);
}

/* int	main(void)
{
	char	*str[4];
	char	*sep;
	int		size;
	char	*resultado;

	sep = "|";
	size = 0;
	str[0] = "Hola";
	str[1] = "que";
	str[2] = "tal";
	str[3] = "jajaja";
	resultado = ft_strjoin(size, str, sep);
	printf("Original : %s %s %s %s\n", str[0], str[1], str[2], str[3]);
	printf("Cambiado : %s", resultado);
	free(resultado);
	return (0);
} */
