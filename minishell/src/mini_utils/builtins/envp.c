/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:44:28 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/13 19:56:57 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	size_envp(t_envp *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	lst_addenv_back(t_envp **lst, t_envp *new)
{
	t_envp	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	get_envp(t_data *data, char **envp, int i)
{
	char	**curr;
	t_envp	*tmp;

	while (envp[i++] != NULL)
	{
		tmp = ft_calloc(1, sizeof(t_envp));
		if (!tmp)
			return (EXIT_FAILURE);
		curr = ft_split(envp[i], "=");
		tmp->name = ft_strdup(curr[0]);
		if (curr[1] == NULL)
			tmp->content = ft_strdup("=");
		else
			tmp->content = ft_strjoin("=", curr[1]);
		tmp->ind = 0;
		tmp->next = NULL;
		lst_addenv_back(&data->envp, tmp);
		free_split(curr);
		curr = NULL;
	}
	set_envp_index(data);
}
