/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:34:59 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/10 12:39:03 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(t_push *p)
{
	ft_lstclear(&p->stack_a, &del_content);
	ft_lstclear(&p->stack_b, &del_content);
	free(p);
}
