/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:35:31 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/10 12:51:42 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"
# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_push
{
	char	**arg;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*a;
	t_list	*b;
	t_list	*aux;
	t_list	*aux2;
}				t_push;

int				check_argv(char **arg);
int				check_rep(char **arg);
int				fill_a(t_push *p);
long long int	ft_atol(char *s);
void			get_index(t_push *p);
void			check_stack(t_push *p, t_list *list);
int				check_index(t_push *p);
void			pa(t_push *p, int flag);
void			pb(t_push *p, int flag);
void			sa(t_push *p, int flag);
void			sb(t_push *p, int flag);
void			ss(t_push *p, int flag);
void			ra(t_push *p, int flag);
void			rb(t_push *p, int flag);
void			rr(t_push *p, int flag);
void			rra(t_push *p, int flag);
void			rrb(t_push *p, int flag);
void			rrr(t_push *p, int flag);
void			sort_3(t_push *p);
void			push_b(t_push *p);
void			put_pos(t_push *p);
void			put_t_pos(t_push *p);
void			put_costa(t_push *p);
void			put_costb(t_push *p);
int				check_order(t_push *p);
int				total_cost(t_list *node);
t_list			*cheaper_cost(t_push *p);
void			final_moves(t_push *p);
int				ft_abs(int cost);
void			free_arg(char **arg);
void			del_content(int content);
void			free_all(t_push *p);

#endif