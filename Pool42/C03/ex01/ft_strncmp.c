/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:57:25 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/06 13:20:06 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		i++;
	}
	if (i < n)
	{
		if (s1[i] == '\0' && s2[i] != '\0')
			return (-1);
		else if (s1[i] != '\0' && s2[i] == '\0')
			return (1);
	}
	return (0);
}

/*int	main(void)
{
	char	a[20] = "Pepee";
	char	b[20] = "Josee";
	int	size = 3;

	printf("%d", strncmp(a, b, size));
	printf("%d\n", ft_strncmp(a, b, size));
	return (0);
}*/
