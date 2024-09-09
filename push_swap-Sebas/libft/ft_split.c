/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:39:45 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/09 13:41:16 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_mallocsafe(char **s2, int pos, size_t buffer)
{
	int	i;

	i = 0;
	s2[pos] = malloc(buffer);
	if (s2[pos] == NULL)
	{
		while (i < pos)
		{
			free(s2[i++]);
		}
		free(s2);
		return (1);
	}
	return (0);
}

static int	ft_fill(char **s2, const char *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		if (len)
		{
			if (ft_mallocsafe(s2, j, len + 1))
				return (1);
			ft_strlcpy(s2[j], &s[i - len], len + 1);
			j++;
		}
	}
	return (0);
}

static size_t	ft_count(char const *s, char c)
{
	size_t	words;
	size_t	i;
	size_t	truef;

	words = 0;
	i = 0;
	while (s[i])
	{
		truef = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			if (truef == 0)
			{
				words++;
				truef = 1;
			}
			i++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**s2;
	size_t	words;

	if (!s)
		return (0);
	words = 0;
	words = ft_count(s, c);
	s2 = malloc(sizeof(char *) * (words + 1));
	if (!s2)
		return (0);
	s2[words] = NULL;
	if (ft_fill(s2, s, c))
		return (0);
	return (s2);
}

/* int	main(void)
{
	char	a[] = "  HOla que tal como estas";
	char	**c = ft_split(a, ' ');
	while (*a)
		printf("Hay %s palabras\n", *c++);
	return (0);
} */

/* #include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void	ft_free(char **str, int str_ind)
{
	while (str_ind-- > 0)
		free(str[str_ind]);
	free(str);
}

static int	ft_wordlen(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		str_ind;

	i = 0;
	str_ind = -1;
	str = malloc(sizeof(char *) * (ft_countwords (s, c) + 1));
	if (!str)
		return (0);
	while (++str_ind < ft_countwords (s, c))
	{
		while (s[i] == c)
			i++;
		str[str_ind] = ft_substr(s, i, ft_wordlen(s, c, i));
		if (!(str[str_ind]))
		{
			ft_free(str, str_ind);
			return (0);
		}
		i += ft_wordlen(s, c, i);
	}
	str[str_ind] = 0;
	return (str);
} */