/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:47:45 by sebferna          #+#    #+#             */
/*   Updated: 2023/11/01 13:36:58 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	a;
	int	temp2;

	temp2 = 1;
	while (temp2)
	{
		temp2 = 0;
		temp = 0;
		while (temp < size - 1)
		{
			if (tab[temp] > tab[temp + 1])
			{
				a = tab[temp];
				tab[temp] = tab[temp + 1];
				tab[temp + 1] = a;
				temp2 = 1;
			}
			temp++;
		}
	}
}
