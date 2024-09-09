/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:26:13 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/21 11:26:13 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_order(t_push *p)
{
	t_list	*aux;

	aux = p->stack_a;
	while (aux->next != NULL)
	{
		if (aux->index < aux->next->index)
			aux = aux->next;
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

t_list	*cheaper_cost(t_push *p)
{
	t_list	*aux;
	t_list	*result;

	result = NULL;
	aux = p->stack_b;
	while (aux != NULL)
	{
		if (result == NULL || total_cost(aux) < total_cost(result))
			result = aux;
		aux = aux->next;
	}
	return (result);
}

int	total_cost(t_list *node)
{
	int	total_cost;

	total_cost = 0;
	if (node->cost_a >= 0 && node->cost_b >= 0)
	{
		if (node->cost_a > node->cost_b)
			total_cost = node->cost_a;
		else if (node->cost_b > node->cost_a)
			total_cost = node->cost_b;
		else
			total_cost = node->cost_a;
	}
	else if (node->cost_a <= 0 && node->cost_b <= 0)
	{
		if (node->cost_a > node->cost_b)
			total_cost = node->cost_b * -1;
		else if (node->cost_a < node->cost_b)
			total_cost = node->cost_a * -1;
		else
			total_cost = node->cost_a * -1;
	}
	else if ((node->cost_a > 0 && node->cost_b < 0)
			|| (node->cost_a < 0 && node->cost_b> 0))
			total_cost = ft_abs(node->cost_a) + ft_abs(node->cost_b);
	return (total_cost);
}

static void	final_moves2(t_push *p)
{
	while (p->aux->cost_b > 0)
	{
		rb(p, 1);
		p->aux->cost_b--;
	}
	while (p->aux->cost_a > 0)
	{
		ra(p, 1);
		p->aux->cost_a--;
	}
	while (p->aux->cost_b < 0)
	{
		rrb(p, 1);
		p->aux->cost_b++;
	}
	while (p->aux->cost_a < 0)
	{
		rra(p, 1);
		p->aux->cost_a++;
	}
}

void	final_moves(t_push *p)
{
	while (p->aux->cost_a > 0 && p->aux->cost_b > 0)
	{
		rr(p, 1);
		p->aux->cost_a--;
		p->aux->cost_b--;
	}
	while (p->aux->cost_a < 0 && p->aux->cost_b < 0)
	{
		rrr(p, 1);
		p->aux->cost_a++;
		p->aux->cost_b++;
	}
	final_moves2(p);
	pa(p, 1);
}