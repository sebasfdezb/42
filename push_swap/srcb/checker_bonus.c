/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:32:09 by sebferna          #+#    #+#             */
/*   Updated: 2024/09/11 11:32:11 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_num(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((s[j] == '-' && (s[j + 1] >= '0' && s[j + 1] <= '9'))
		|| (s[j] >= '0' && s[j] <= '9'))
	{
		i++;
		j++;
		while (s[j])
		{
			if (s[j] >= '0' && s[j] <= '9')
				i++;
			j++;
		}
	}
	if (i == ft_strlen(s))
		return (0);
	return (-1);
}

static int	arg_to_int(t_list *d, int argc, char **argv)
{
	int	i;

	i = 0;
	d->atoierror = 0;
	while (i != argc - 1 && d->atoierror == 0)
	{
		if (check_num(argv[i + 1]) == -1)
			return (-1);
		d->sa[i] = ft_atoi(argv[i + 1], d);
		if (d->atoierror == 1)
			return (-1);
		i++;
	}
	d->atoierror = 0;
	return (0);
}

static int	init_data(t_list *d, int argc)
{
	d->argc = argc - 1;
	d->error = 0;
	d->sa = malloc(sizeof(int) * d->argc);
	if (!d->sa)
	{
		free(d);
		return (-1);
	}
	d->sb = malloc(sizeof(int) * d->argc);
	if (!d->sb)
	{
		free(d->sa);
		free(d);
		return (-1);
	}
	d->sia = d->argc;
	d->sib = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*d;

	if (argc == 1)
		return (0);
	d = malloc(sizeof(t_list));
	if (!d)
		return (0);
	if (check_args(argv, argc - 1) == -1)
		ft_free(d, 0);
	if (init_data(d, argc) == -1)
		return (0);
	if (arg_to_int(d, argc, argv) == -1)
	{
		ft_free(d, 0);
		return (0);
	}
	if (check_same_nums(d) == -1)
		ft_free(d, 0);
	ft_checker_lines(d);
	ft_free(d, 1);
	return (0);
}
