/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:57:59 by sebferna          #+#    #+#             */
/*   Updated: 2024/08/12 11:57:59 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long int	ft_atol(char *s)
{
	long long int	n;
	int				sign;
	int				i;

	n = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n * sign);
}

void	free_arg(char **arg)
{
	int	i;

	i = 0;
	if (arg != NULL)
	{
		while (arg[i] != NULL)
		{
			free(arg[i]);
			arg[i] = NULL;
			i++;
		}
		free(arg);
		arg = NULL;
	}
}

int	fill_a(t_push *p)
{
	long long	n;
	int			i;

	i = 0;
	while (p->arg[i] != NULL)
	{
		n = ft_atol(p->arg[i]);
		if (n < MIN_INT || n > MAX_INT)
			return (EXIT_FAILURE);
		ft_lstadd_back(&p->stack_a, ft_lstnew(n, 0, 0, 0));
		i++;
	}
	return (EXIT_SUCCESS);
}

void	get_index(t_push *p)
{
	t_list	*aux;
	t_list	*actual;
	int		i;
	int		c;

	i = 0;
	while (++i <= ft_lstsize(p->stack_a))
	{
		aux = p->stack_a;
		c = MAX_INT;
		while (aux != NULL)
		{
			if (aux->index == 0 && aux->value <= c)
			{
				actual = aux;
				c = actual->value;
			}
			aux = aux->next;
		}
		actual->index = i;
	}
}

int	check_index(t_push *p)
{
	t_list	*aux;
	int		i;

	i = 1;
	aux = p->stack_a;
	while (i <= ft_lstsize(p->stack_a))
	{
		if (aux->index == i)
		{
			aux = aux->next;
			i++;
		}
		else
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
