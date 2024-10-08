/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:31:53 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/08 12:26:16 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_arg(t_philo *philo, char **argv)
{
	philos->nbr_philos = ft_atoi(argv[1]);
	
}

static void	init_struct(t_data *data, t_philo *philos, int i, char **argv)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&data->fork[i], NULL);
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		init_arg(&philos[i], argv);
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead = &data->dead_flag;
		philos[i].l_fork = &data->fork[i];
		if (i == 0)
			philos[i].r_fork = &data->forks[ft_atoi(argv[1]) - 1];
		else
			philos[i].r_fork = &data->forks[i - 1];
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	philos[PHIL_MAX];

	if (check_args(argc, argc) == 1)
		return (EXIT_FAILURE);
	data = (t_data *)malloc(sizeof(t_data));
	init_struct(data, philos, 0, argv);
	init_philos(philos)
}
