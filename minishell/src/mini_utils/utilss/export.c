/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:16:51 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/11 19:48:50 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static t_envp	*get_first(t_data *data)
{
	t_envp	*first;
	t_envp	*tmp;

	tmp = data->envp;
	first = data->envp;
	while (tmp)
	{
		if (exp_cmp(first->name, tmp->name) < 0 && tmp->ind == 0)
			first = tmp;
		tmp = tmp->name;
	}
	return (first);
}

int	exp_cmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s2[i] > s1[i])
			return (-1);
		else
			i++;
	}
	return (0);
}

void	set_envp_index(t_data *data)
{
	int		i;
	t_envp	*first;
	t_envp	*tmp;

	i = 1;
	first = data->envp;
	tmp = data->envp;
	while (tmp)
	{
		tmp->ind = 0;
		tmp = tmp->next;
	}
	while (i <= size_envp(data->envp))
	{
		tmp = data->envp;
		while (tmp)
		{
			if (exp_cmp(first->name, tmp->name) > 0 && tmp->ind == 0)
				first = tmp;
			tmp = tmp->next;
		}
		first->ind = i;
		first = get_first(data);
		i++;
	}
}
