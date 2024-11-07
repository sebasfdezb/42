/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:38 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/07 18:47:06 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getprompt(t_data *data)
{
	char	direc[500];
	char	*direcf;

	if (getcwd(direc, sizeof(direc)) == NULL)
		return (EXIT_FAILURE);
	direcf = ft_strjoin(direc, " % ");
	if (direcf == NULL)
		return (EXIT_FAILURE);
	data->prompt = readline(direcf);
	free(direcf);
	direcf = NULL;
	if (!data->prompt)
	{
		printf("exit\n");
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	minishell(t_data *data, char **env)
{
	draw();
	while (1)
	{
		signal(SIGINT, signals);
		signal(SIGQUIT, SIG_IGN);
		if (getprompt(data) == EXIT_FAILURE)
			exit (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int main(int argc, char **argv, char **envp)
{
	t_data	*data;

	if (argc > 1)
		return (EXIT_FAILURE);
	(void)argc;
	(void)argv;
	data = ft_calloc(1, sizeof(t_data));
	if (data == NULL)
		return (EXIT_FAILURE);
	init_struct(data);
	if (minishell(data, envp) == EXIT_FAILURE)
		return (free_all(data), EXIT_FAILURE);
	return (free_all(data), EXIT_SUCCESS);
}