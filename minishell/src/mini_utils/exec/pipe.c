/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:10:18 by sebferna          #+#    #+#             */
/*   Updated: 2024/12/02 17:24:58 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ex_routepipes(t_data *data, t_parser *node, char **envp, t_list *tmp)
{
	pid_t	pid;

	if (pipe(data->fd) == -1)
		error_msg("Pipe error\n");
	pid = fork();
	if (pid == -1)
	{
		close(data->fd[0]);
		close(data->fd[1]);
		error_msg("Fork error\n");
	}
	if (pid == 0)
	{
		if (tmp->next != NULL)
			handle_child_pipe(data, node, envp, tmp);
		else
			process_final_pipe(data, node, envp);
	}
	if (tmp->next && ((t_parser *)(tmp->next->content))->filein == 0)
		((t_parser *)(tmp->next->content))->filein = data->fd[0];
	else
		close(data->fd[0]);
	close(data->fd[1]);
	waitpid(pid, NULL, 0);
	check_cargs(node);
}
