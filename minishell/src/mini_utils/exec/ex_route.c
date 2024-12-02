/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_route.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:25:11 by sebferna          #+#    #+#             */
/*   Updated: 2024/12/02 17:29:49 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_cargs(t_parser *node)
{
	int			i;
	int			j;
	struct stat	file_inf;

	i = 1;
	j = 0;
	while (node->all_cmd[i] && ft_strchr(node->all_cmd[i], '-'))
		i++;
	if (node->all_cmd[i - 1])
	{
		while (node->all_cmd[i - 1][j])
		{
			if (ft_isdigit(node->all_cmd[i - 1][j]))
				g_last_status = 1;
			j++;
		}
	}
	if (stat(node->all_cmd[i], &file_inf) == 0 || !node->all_cmd[i])
		return ;
	g_last_status = 1;
}
