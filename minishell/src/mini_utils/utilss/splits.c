/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:07:11 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/12 17:19:42 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_path(t_data *d)
{
	t_envp	*tmp;

	tmp = d->envp;
	if (!d->path)
	{
		free_split(d->path);
		d->path = NULL;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "PATH", 4) == 0)
		{
			d->path = ft_split(tmp->content + 1, ':');
			break ;
		}
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
