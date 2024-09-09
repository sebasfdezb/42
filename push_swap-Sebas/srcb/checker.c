/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:14:10 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/28 11:14:10 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/push_swap.h"

void	del_content(int content)
{
	content = 0;
}

int	check(char **line, t_push *p)
{
	if (ft_strncmp(*line, "pa\n", 3) == 0)
		return (pa(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "pb\n", 3) == 0)
		return (pb(p, 0), EXIT_SUCCESS);
		if (ft_strncmp(*line, "sa\n", 3) == 0)
		return (sa(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "sb\n", 3) == 0)
		return (sb(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "ss\n", 3) == 0)
		return (ss(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "ra\n", 3) == 0)
		return (ra(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "ra\n", 3) == 0)
		return (rb(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "rr\n", 3) == 0)
		return (rr(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "rra\n", 4) == 0)
		return (rra(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "rrb\n", 4) == 0)
		return (rrb(p, 0), EXIT_SUCCESS);
	if (ft_strncmp(*line, "rrr\n", 4) == 0)
		return (rrr(p, 0), EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static void	initialize_struct(t_push *p)
{
	p->a = NULL;
	p->arg = NULL;
	p->aux2 = NULL;
	p->aux = NULL;
	p->b = NULL;
	p->stack_a = NULL;
	p->stack_b = NULL;
}

int	main(int argc, char **argv)
{
	t_push	*p;
	char	**split;

	p = ft_calloc(1, sizeof(t_push));
	if (!p)
		return (EXIT_FAILURE);
	initialize_struct(p);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		p->arg = split;
	}
	else if (argc > 2)
		p->arg = argv + 1;
	else
		return (free(p), write(1, "Error\n", 5), EXIT_FAILURE);
	if (check_argv(p->arg) == 1)
		return (free_arg(split), free(p), write(1, "Error\n", 5), EXIT_FAILURE);
	if (check_argv(p->arg) == 1)
		return (free_arg(split), free(p), write(1, "Error\n", 5), EXIT_FAILURE);
	if (check_rep(p->arg) == 1)
		return (free_arg(split), free(p), write(1, "Error\n", 5), EXIT_FAILURE);
	if (main2(p) == 1)
		return (free(p), EXIT_FAILURE);
	return (ft_lstclear(&p->stack_a, &del_content),
			ft_lstclear(&p->stack_b, &del_content),
			free(p), free_arg(split), EXIT_SUCCESS);
}
