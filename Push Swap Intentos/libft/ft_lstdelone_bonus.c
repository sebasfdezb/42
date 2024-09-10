/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:20:20 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/09 14:23:42 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->value);
	del(lst->index);
	del(lst->pos);
	del(lst->target_pos);
	del(lst->cost_a);
	del(lst->cost_b);
	free(lst);
	lst = NULL;
}
