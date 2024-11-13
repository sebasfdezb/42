/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:16 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/13 19:56:52 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/history.h>
# include <readline/readline.h>

int	g_last_status;

typedef struct s_data
{
	char	*prompt;
	t_envp	*envp;
	char	**path;
	char	**cmd;
	int		i;
	int		j;
	char	**aux;
}	t_data;

typedef struct s_envp
{
	char			*name;
	char			*content;
	int				ind;
	struct s_env	*next;
}	t_envp;

//UTILS
void	draw(void);

//EXPORT
void	set_envp_index(t_data *data);
int		exp_cmp(const char *s1, const char *s2);
int		size_envp(t_envp *lst);
//SIGNALS
void	signals(int sig);
void	sig_ctrlc(int sig);
void	signals(int sig);
//free
void	free_split(char **tmp);
//splits
int		get_path(t_data *d);
int		get_cmds(t_data *d);

int		lexer(char	*str);

#endif