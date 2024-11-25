/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:39:29 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/25 18:41:03 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	error_msg(char *str)
{
	unlink("here_doc.tmp");
	g_last_status = 1;
	perror(str);
	exit(EXIT_FAILURE);
}
