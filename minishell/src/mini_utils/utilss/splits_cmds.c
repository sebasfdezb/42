/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:19:55 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/12 18:09:21 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	counts(char const **s1, char c, char *s2)
{
	
}

static int	count_cmd(char const *str, char c, int i)
{
	int		j;
	char	s;

	j = 0;
	while (str[j])
	{
		if (counts(str[j], c, &s) == -2)
			return (-2);
		if (str[j] == c && j++)
		{
			while (str[j] == ' ')
				j++;
			if (str[j] == c || str[j] == '\0')
				return (printf("Error: Pipes\n"));
		}
		i++;
	}
	return (i);
}

char	**splits_cmd(char const *str, char c)
{
	int		i;
	int		j;
	char	**s;

	i = -1;
	j = 0;
	s = malloc(sizeof(char *) * (count_cmd(str, c, 0) + 1));
	if (!s)
		return (0);
	while (++i < count_cmd(str, c, 0))
	{
		while (str[j] == c)
			j++;
		while (str[j] == ' ')
			j++;
		s[i] = ft_substr(str, j, size_cmd(str, c, j));
		if (!s[i])
		{
			free_split(s);
			return (0);
		}
		j = j + size_cmd(str, c, j);
	}
	s[i] = 0;
	return (s);
}

int	get_path(t_data *d)
{
	int	i;

	i = 0;
	while (d->prompt[i] == ' ' || d->prompt[i] == '	')
		i++;
	if (d->prompt[i] == '\0')
		return (EXIT_FAILURE);
	d->cmd = splits_cmd(d->prompt, '|');
	if (!d->cmd)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

