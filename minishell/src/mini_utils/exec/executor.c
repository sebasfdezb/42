/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:06:21 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/26 17:22:50 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	execute(t_data *data, t_parser *node, char **envp, t_list *aux)
{
	signal(SIGINT, sig_ctrlc);
	singal(SIGQUIT, sig_ctrlslash);
	if (node && node->all_cmd && node->all_cmd[0])
	{
		if (data->flag_pipe == 1)
		{
			if ((!ft_strncmp(node->all_cmd[0], "cat\0", 4)
					&& node->all_cmd[1] == NULL && node->filein == 0)
				&& catnls(data, envp) == 0)
				return (EXIT_SUCCESS);
			while (aux)
			{
				if (aux->next == NULL
					&& !ft_strncmp(((t_parser *)(aux->content))->route,
					"b\0", 2))
					exec_builts(data, ((t_parser *)aux->content));
				else
					exec_rtepipes(data, ((t_parser *)aux->content), envp, aux);
				aux = aux->next;
			}
		}
		else if (data->flag_pipe == 0)
			exec_route(data, node, envp);
	}
	return (EXIT_SUCCESS);
}
