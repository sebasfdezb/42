/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 12:28:56 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/21 12:28:56 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_push *p, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(p->stack_a) < 2)
		return ;
	aux = p->stack_a;
	last = ft_lstlast(p->stack_a);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	ft_lstadd_front(&p->stack_a, last);
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_push *p, int flag)
{
	t_list	*aux;
	t_list	*last;

	if (ft_lstsize(p->stack_b) < 2)
		return ;
	aux = p->stack_b;
	last = ft_lstlast(p->stack_b);
	while (aux)
	{
		if (aux->next->next == NULL)
		{
			aux->next = NULL;
			break ;
		}
		aux = aux->next;
	}
	ft_lstadd_front(&p->stack_b, last);
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_push *p, int flag)
{
	rra(p, 0);
	rrb(p, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}
