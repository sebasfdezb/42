/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:50:47 by sebferna          #+#    #+#             */
/*   Updated: 2024/06/25 11:34:20 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	gnl_ft_strchr(const char *str, int len)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (char)len)
			return (1);
		i++;
	}
	return (0);
}

void	*gnl_ft_calloc(int count, int size)
{
	char	*ptr;
	int		i;

	ptr = (char *)malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*gnl_ft_strjoin(char *str1, char *str2)
{
	int		i;
	char	*str3;
	int		size;

	if (!str1)
	{
		str1 = ft_calloc(1, sizeof(char));
		if (!str1)
			return (free(str1), str1 = NULL, NULL);
	}
	if (!str2)
		return (free(str1), str1 = NULL, NULL);
	size = ft_strlen(str1) + ft_strlen(str2);
	str3 = (char *)ft_calloc((size + 1), sizeof(char));
	if (!str3)
		return (free(str1), str1 = NULL, NULL);
	i = -1;
	while (str1[++i])
		str3[i] = str1[i];
	i = -1;
	while (str2[++i])
		str3[ft_strlen(str1) + i] = str2[i];
	str3[ft_strlen(str1) + i] = '\0';
	return (free(str1), str1 = NULL, str3);
}
