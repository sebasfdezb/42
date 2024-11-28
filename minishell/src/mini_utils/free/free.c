/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:39:10 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/28 18:12:17 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_cd(t_data *data)
{
	free(data->aux);
	free(data->error_cd);
	g_last_status = 1;
}

void	free_split(char **tmp)
{
	int	i;

	i = 0;
	while (tmp && tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	if (!tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	tmp = NULL;
}
