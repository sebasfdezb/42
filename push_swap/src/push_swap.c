/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:28:55 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/12 11:28:55 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_push *p)
{
	ft_lstclear(&p->stack_a, &del_content);
	ft_lstclear(&p->stack_b, &del_content);
	free(p);
}

void	del_content(int content)
{
	(void)content;
}

static void	initialize_struct(t_push *p)
{
	p->arg = NULL;
	p->stack_a = NULL;
	p->stack_b = NULL;
	p->a = NULL;
	p->b = NULL;
	p->aux = NULL;
	p->aux2 = NULL;
}

int	main2(t_push *p)
{
	if (check_argv(p->arg) == 1)
		return (write(1, "Error\n", 6), EXIT_FAILURE);
	if (check_rep(p->arg) == 1)
		return (write(1, "Error\n", 6), EXIT_FAILURE);
	if (fill_a(p) == 1)
		return (EXIT_FAILURE);
	get_index(p);
	if (check_index(p) == 0)
		return (EXIT_SUCCESS);
	if (ft_lstsize(p->stack_a) == 2)
		return (sa(p, 1), EXIT_SUCCESS);
	if (ft_lstsize(p->stack_a) == 3)
		return (sort_3(p), EXIT_SUCCESS);
	push_b(p);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_push	*p;

	if (argc == 1)
		return (0);
	p = ft_calloc(1, sizeof(t_push));
	if (!p)
		return (EXIT_FAILURE);
	initialize_struct(p);
	if (argc == 2)
	{
		p->arg = ft_split(argv[1], ' ');
	}
	else if (argc > 2)
		p->arg = argv + 1;
	else
		return (free(p), write(1, "Error\n", 6), EXIT_FAILURE);
	if (main2(p) == 1)
	{
		if (argc == 2 && p->arg)
			free_arg(p->arg);
		return (free(p), EXIT_FAILURE);
	}
	if (argc == 2 && p->arg)
		free_arg(p->arg);
	return (free_all(p), EXIT_SUCCESS);
}
