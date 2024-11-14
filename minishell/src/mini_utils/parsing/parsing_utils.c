/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:19:55 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/14 20:04:15 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_token_filein(t_data *data, int *i, int *j, t_parser **node)
{
	data->flag_hered = 0;
	data->flag_token = 1;

	if (data->cmd[*i][*j] == '<' && ++(*j))
	{
		if (data->cmd[*i][*j] == '\0')
			return (printf("Error: Syntax token newline\n"), EXIT_FAILURE);
		if (data->cmd[*i][*j] == '>')
			return (printf("Error: Syntax token `>'\n"), EXIT_FAILURE);
		if (data->cmd[*i][*j] == '<' && ++(*j))
			data->flag_hered = 1;
		if (data->flag_hered == 1 && data->cmd[*i][*j] == '\0')
			return (printf("Error: Syntax token newline\n"), EXIT_FAILURE);
		if (data->flag_hered == 1 && data->cmd[*i][*j] == '<')
			return (printf("Error: Syntax token <<\n"), EXIT_FAILURE);
		if (data->flag_hered == 1 && data->cmd[*i][*j] == '>')
			return (printf("Error: Syntax token >>\n"), EXIT_FAILURE);
		while (data->cmd[*i][*j] == ' ' && ++(*j))
			if (get_token_next(data, i, j) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		if (get_token_next(data, i, j, node) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
