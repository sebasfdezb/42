/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:19:55 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/12 17:31:30 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**splits_cmd(char const *str, char c)
{
	
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

