/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:46 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/12 16:50:47 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	lexer(char	*str)
{
	int	i;
	int	qsimple;
	int	qdoubles;

	i = 0;
	qsimple = 0;
	qdoubles = 0;
	while (str && str[i])
	{
		if (str[i] == '\'' && !qdoubles)
			qsimple = 1;
		else if (str[i] == '\"' && !qsimple)
			qdoubles = 1;
		i++;
	}
	if (qsimple || qdoubles)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
