/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:48:16 by sebferna          #+#    #+#             */
/*   Updated: 2024/11/11 18:11:06 by sebferna         ###   ########.fr       */
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

typedef struct s_data
{
	char	*prompt;
	t_envp	*envp;
}t_data;

typedef	struct s_envp
{
	char			*name;
	char			*content;
	int				ind;
	struct s_env	*next;
}t_envp;


//UTILS
void	draw(void);
void    signals(int sig);
void    sig_ctrlc(int sig);
void    signals(int sig);


#endif