/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:05:52 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 11:12:25 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(int *argv1, int *argv2)
{
	int	temp;

	temp = *argv1;
	*argv1 = *argv2;
	*argv2 = temp;
}

void	rra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[d->sia - 1];
	i = d->sia - 1;
	while (--i >= 0)
		d->sa[i + 1] = d->sa[i];
	d->sa[0] = temp;
}

void	rrb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[d->sib - 1];
	i = d->sib - 1;
	while (--i >= 0)
		d->sb[i + 1] = d->sb[i];
	d->sb[0] = temp;
}

void	rrr(t_list *d)
{
	rra(d);
	rrb(d);
}
