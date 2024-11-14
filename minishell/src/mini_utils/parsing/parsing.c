/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:00:46 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/14 20:05:57 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_tokens(t_data *data, int *i, int *j, t_parser **node)
{
	while (data->cmd[*i][*j] == '<' || data->cmd[*i][*j] == '>')
	{
		if ((*node)->filein != 0 && data->cmd[*i][*j] == '<')
			close((*node)->filein);
		if ((*node)->fileout != 1 && data->cmd[*i][*j] == '>')
			close((*node)->fileout);
		if (get_token_filein(data, i, j, node) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
}

int	parsing(t_data *data, int i, int j)
{
	while (data->cmd[i][j] != NULL)
	{
		j = 0;
		if (data->cmd[i][j] == '\0')
			return (EXIT_FAILURE);
		while (data->cmd[i][j])
		{
			data->node = ft_calloc(1, sizeof(t_parser));
			data->node->fileout = 1;
			data->node->filein = 0;
			while (data->cmd[i][j] == ' ')
				j++;
			if (get_tokens(data, &i, &j, &data->node) == EXIT_FAILURE)
				return (free_parser(data->node), EXIT_FAILURE);
		}
	}
}
