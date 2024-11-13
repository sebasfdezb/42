/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:33:28 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/13 19:06:35 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	next_expand(t_data *d, int *i, int *flag, char **expand)
{
	
}

static void	prime_expand(t_data *d, int *i, int *flag, char **expand)
{
	char	*next;

	while ((d->cmd[d->i][d->j] != '$' || *flag) && d->cmd[d->i][d->j])
	{
		if ((!*flag && d->cmd[d->i][d->j] == '~')
			&& ((d->cmd[d->i][d->j - 1] == ' '
			&& d->cmd[d->i][d->j + 1] == ' ')
			|| (d->cmd[d->i][d->j + 1] == '\0')
			|| (d->cmd[d->i][d->j + 1] == '/')))
		{
			if (d->cmd[d->i][d->j] == '\'')
				*flag = !(*flag);
			next = envp_content(d, "HOME");
			*expand = ft_strjoin_gnl(*expand, next);
			free(next);
			d->j++;
		}
		else
			next_expand(d, i, flag, expand);
		if (d->aux != NULL)
		{
			free(d->aux);
			d->aux = NULL;
		}
	}
}

static void	dollar_expand(t_data *d, int *i, int *flag, char **expand)
{
	char	*aux;

	if (d->cmd[d->i][d->j] == '$' && !*flag)
	{
		if (d->cmd[d->i][d->j + 1] == '\0' || d->cmd[d->i][d->j + 1] == ' ')
		{
			*expand = ft_strjoin_gnl(*expand, ft_strdup("$"));
			d->j++;
		}
		else
		{
			d->j++;
			*i = d->j;
			while ((d->cmd[d->i][d->j] != ' ' && d->cmd[d->i][d->j] != '$' &&
				d->cmd[d->i][d->j]) && d->cmd[d->i][d->j] != '\''
				&& d->cmd[d->i][d->j] != '\"')
				d->j++;
			aux = ft_substr(d->cmd[d->i], *i, d->j - *i);
			*expand = ft_strjoin_gnl(*expand, envp_content(d, aux));
			free(aux);
			aux = NULL;
		}
	}
}

void	expand(t_data *d)
{
	int		i;
	int		flag;
	char	*expand;

	flag = 0;
	expand = NULL;
	while (d->cmd[d->i])
	{
		d->j = 0;
		i = 0;
		while (d->cmd[d->i][d->j])
		{
			dollar_expand(d, &i, &flag, &expand);
			prime_expand(d, &i, &flag, &expand);
		}
	}
}
