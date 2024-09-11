/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:04:24 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 11:13:22 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[0];
	i = -1;
	while (++i < (d->sia - 1))
		d->sa[i] = d->sa[i + 1];
	d->sa[d->sia - 1] = temp;
}

void	rb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[0];
	i = -1;
	while (++i < (d->sib - 1))
		d->sb[i] = d->sb[i + 1];
	d->sb[d->sib - 1] = temp;
}

void	rr(t_list *d)
{
	ra(d);
	rb(d);
}
