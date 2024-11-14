/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:00:46 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/14 18:03:51 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_tokens(t_data *data, int *i, int *j, t_parser **node)
{
	
}

int	parser(t_data *data, int i, int j)
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
