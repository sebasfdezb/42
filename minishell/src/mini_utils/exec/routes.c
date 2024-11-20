/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:08:20 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/20 18:23:49 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_route(t_data *data, t_parser **node, int i)
{
	
}

int	process_route(t_data *data, int i)
{
	t_list	*tmp;

	tmp = data->nodes;
	data->flag_pipe = 0;
	while (data->cmd[i] != NULL && ((t_parser *)(tmp->content))->all_cmd)
	{
		if (get_route(data, ((t_parser *)(tmp->content)), -1) == 1)
			return (g_last_status = 127, EXIT_FAILURE);
		if (i == 1)
			data->flag_pipe = 1;
		if (tmp->next != NULL)
			tmp = tmp->next;
		i++;
	}
	if (((t_parser *)(tmp->content))->all_cmd == NULL)
		((t_parser *)(tmp->content))->route = NULL;
	return (EXIT_SUCCESS);
}
