/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:43:24 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/13 19:56:49 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	draw(void)
{
	printf(" __  __ _____ _   _  _____ _____ _    _  _____ _    _ _      _\n");
	printf("|  \\/ |_   _| \\ | |_   _|_   _| |  | |/ ____| |  | | |    | |\n");
	printf("| \\  /| | | |  \\| | | |   | | | |  | | (___ | |  | | |    | |\n");
	printf("| |\\/|| | | | . `  | | |   | | | |  | |\\___ \\| |  | | |    |\n");
	printf("| |  | |_| |_| |\\  |_| |_ _| |_| |__| |____) | |__| ||____| |_\n");
	printf("|_|  |_|_____|_| \\_|_____|_____(_)____/|_____/ \\____|______|_\n");
	printf("\n");
}

void	sig_ctrlslash(int sig)
{
	if (sig == SIGQUIT)
	{
		printf("Quit: 3\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	sig_ctrlc(int sig)
{
	if (sig == SIGINT)
	{
		printf("\033[K\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

void	signals(int sig)
{
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
		printf("\033[K\n");
		rl_on_new_line();
		rl_redisplay();
		rl_replace_line("", 0);
	}
}
