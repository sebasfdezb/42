/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:11:42 by sebferna          #+#    #+#             */
/*   Updated: 2023/10/31 11:43:24 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	temp2;

	temp = 0;
	while (temp < size / 2)
	{
		temp2 = tab[temp];
		tab[temp] = tab[size - 1 - temp];
		tab[size - 1 - temp] = temp2;
		temp++;
	}
}
