/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:49:25 by sebferna          #+#    #+#             */
/*   Updated: 2024/01/24 13:08:49 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_cleaner(char *str)
{
	int		i;
	int		j;
	char	*strtmp;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		return (free(str), NULL);
	strtmp = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!strtmp)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i] != '\0')
		strtmp[j++] = str[i++];
	strtmp[j] = '\0';
	return (free(str), strtmp);
}

static char	*ft_line(char *str)
{
	int		i;
	char	*store;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	store = ft_calloc((i + 1 + (str[i] == '\n')), sizeof(char));
	if (!store)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		store[i] = str[i];
		i++;
	}
	if (str[i] == '\n' && str[i] != '\0')
		store[i++] = '\n';
	store[i] = '\0';
	return (store);
}

static char	*join(char *str, char *buffer)
{
	char	*r;

	r = ft_strjoin(str, buffer);
	if (!r)
		return (NULL);
	return (r);
}

static char	*ft_read(int fd, char *str)
{
	char	*store;
	int		read_char;

	read_char = 1;
	store = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!store)
		return (free(str), NULL);
	while (read_char > 0 && !ft_strchr(store, '\n'))
	{
		read_char = read(fd, store, BUFFER_SIZE);
		if (read_char < 0)
			return (free(store), NULL);
		store[read_char] = '\0';
		str = join(str, store);
		if (!str)
			return (free(str), free(store), NULL);
	}
	return (free(store), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		if (str != NULL)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	str = ft_read(fd, str);
	if (!str)
		return (free(str), str = NULL, NULL);
	line = ft_line(str);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_cleaner(str);
	if (!str)
		return (free(str), str = NULL, line);
	return (line);
}
