/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:58:00 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 10:59:30 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sb[0];
	i = -1;
	while (++i < (d->sib - 1))
		d->sb[i] = d->sb[i + 1];
	d->sib = d->sib - 1;
	i = d->sia;
	d->sia = d->sia + 1;
	while (--i >= 0)
		d->sa[i + 1] = d->sa[i];
	d->sa[0] = temp;
}

void	pb(t_list *d)
{
	int	temp;
	int	i;

	temp = d->sa[0];
	i = -1;
	while (++i < (d->sia - 1))
		d->sa[i] = d->sa[i + 1];
	d->sia = d->sia - 1;
	i = d->sib;
	d->sib = d->sib + 1;
	while (--i >= 0)
		d->sb[i + 1] = d->sb[i];
	d->sb[0] = temp;
}

void	sa(int *sa)
{
	int	temp;

	temp = sa[0];
	sa[0] = sa[1];
	sa[1] = temp;
}

void	sb(int *sb)
{
	int	temp;

	temp = sb[0];
	sb[0] = sb[1];
	sb[1] = temp;
}

void	ss(t_list *d)
{
	sa(d->sa);
	sb(d->sb);
}
