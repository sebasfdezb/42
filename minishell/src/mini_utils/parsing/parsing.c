/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:00:46 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/21 18:52:35 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_commd(t_data *data, t_parser **node, int *i, int *j)
{
	
}

int	get_tokens(t_data *data, t_parser **node, int *i, int *j)
{
	while (data->cmd[*i][*j] == '<' || data->cmd[*i][*j] == '>')
	{
		if ((*node)->filein != 0 && data->cmd[*i][*j] == '<')
			close((*node)->filein);
		if ((*node)->fileout != 1 && data->cmd[*i][*j] == '>')
			close((*node)->fileout);
		if (get_token_filein(data, i, j, node) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (get_token_fileout(data, i, j, node) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	data->size = 0;
	data->a = -1;
	return (EXIT_SUCCESS);
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
			if (get_tokens(data, &data->node, &i, &j) == EXIT_FAILURE)
				return (free_parser(data->node), EXIT_FAILURE);
			if (get_commd(data, &data->node, &i, &j) == EXIT_FAILURE)
				return (free_t_parser(data->node), EXIT_FAILURE);
			if (get_tokens(data, &data->node, &i, &j) == EXIT_FAILURE)
				return (free_t_parser(data->node), EXIT_FAILURE);
		}
	}
}
