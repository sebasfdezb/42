/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:19:44 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/21 12:19:44 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_push *p, int flag)
{
	t_list	*aux;

	if (ft_lstsize(p->stack_a) < 2)
		return ;
	aux = p->stack_a;
	p->stack_a = p->stack_a->next;
	aux->next = NULL;
	ft_lstadd_back(&p->stack_a, aux);
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_push *p, int flag)
{
	t_list	*aux;

	if (ft_lstsize(p->stack_b) < 2)
		return ;
	aux = p->stack_b;
	p->stack_b = p->stack_b->next;
	aux->next = NULL;
	ft_lstadd_back(&p->stack_b, aux);
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_push *p, int flag)
{
	ra(p, 0);
	rb(p, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
