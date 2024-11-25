/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:24:14 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/25 17:35:09 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/* static int	size_words(t_data *data, char const *str, char c, int *d)
{
	while (str[*d] != '\0' && str[*d] != c)
	{
		while ()
	}
} */

void	split_words(t_data *data, char const *str, char c)
{
	if (str[data->d] != c)
	{
		if (str[data->d] == data->quote && data->f == 1)
			data->d++;
		while (s[data->d] == c)
			data->d++;
	}
	while (str[data->d] == c)
		data->d++;
}
