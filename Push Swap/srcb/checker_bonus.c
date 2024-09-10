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

#include "push_swap_bonus.h"

void	del_content(int content)
{
	(void)content;
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
	if (ft_strncmp(*line, "rb\n", 3) == 0)
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
	p->arg = NULL;
	p->stack_a = NULL;
	p->stack_b = NULL;
	p->a = NULL;
	p->b = NULL;
	p->aux = NULL;
	p->aux2 = NULL;
}

static int	main2(t_push *p)
{
	char	*line;

	if (check_argv(p->arg) == 1)
		return (write(1, "Error: Wrong Arguments\n", 22), EXIT_FAILURE);
	if (check_rep(p->arg) == 1)
		return (write(1, "Error: Repeated Number\n", 23), EXIT_FAILURE);
	if (fill_a(p) == 1)
		return (EXIT_FAILURE);
	line = get_next_line(0);
	while (line)
	{
		if (check(&line, p) == EXIT_FAILURE)
			return (free(line), ft_putendl_fd("Error", 2), EXIT_FAILURE);
		else
		{
			free(line);
			line = get_next_line(0);
		}
	}
	if (check_order(p) && p->stack_b == NULL)
		return (write(1, "OK\n", 3), EXIT_SUCCESS);
	return (write(1, "KO\n", 3), EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_push	*p;

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
