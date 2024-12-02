/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:39:10 by sebferna          #+#    #+#             */
/*   Updated: 2024/12/02 17:07:18 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	free_command(t_list **lst)
{
	free(((t_parser *)((*lst)->content))->all_cmd);
	((t_parser *)((*lst)->content))->all_cmd = NULL;
	free(((t_parser *)((*lst)->content))->route);
	((t_parser *)((*lst)->content))->route = NULL;
	if (((t_parser *)((*lst)->content))->filein != 0)
		close(((t_parser *)((*lst)->content))->filein);
	if (((t_parser *)((*lst)->content))->fileout != 0)
		close(((t_parser *)((*lst)->content))->fileout);
	free(((t_parser *)((*lst)->content)));
	(*lst)->content = NULL;
}

void	free_node(t_list **lst)
{
	int		i;
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		i = -1;
		if (((t_parser *)((*lst)->content))->all_cmd)
		{
			while (((t_parser *)((*lst)->content))->all_cmd[++i])
			{
				free(((t_parser *)((*lst)->content))->all_cmd[i]);
				((t_parser *)((*lst)->content))->all_cmd[i] = NULL;
			}
		}
		free_command(lst);
		free((*lst));
		*lst = tmp;
	}
	*lst = NULL;
}

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
