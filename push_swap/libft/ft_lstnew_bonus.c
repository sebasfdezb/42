/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:05:37 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/09 14:24:01 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int value, int index, int pos, int target_pos)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->value = value;
	new_list->index = index;
	new_list->pos = pos;
	new_list->target_pos = target_pos;
	new_list->cost_a = 0;
	new_list->cost_b = 0;
	new_list->next = NULL;
	return (new_list);
}
