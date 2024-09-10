/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:37:40 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/10 11:22:13 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ga <ncruz-ga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:04:12 by ncruz-ga          #+#    #+#             */
/*   Updated: 2023/04/24 15:45:41 by ncruz-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	counter;

	counter = 0;
	while ((s1[counter] != '\0' || s2[counter] != '\0') && (counter < n))
	{
		if ((unsigned char)s1[counter] < (unsigned char)s2[counter])
			return (-1);
		if ((unsigned char)s1[counter] > (unsigned char)s2[counter])
			return (1);
		counter++;
	}
	return (0);
}

/* int	main(void)
{
	const char s1[4] = "Hola";
	const char s2[5] = "Holaa";
	size_t n = 5;
	printf("%d", ft_strncmp(s1, s2, n));
	return (0);
} */
