/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:31:53 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/11 11:49:11 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(pthread_mutex_t *forks, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_thread(t_data *data, int n)
{
	pthread_t	monitor;
	int			i;

	i = -1;
	while (++i < n)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&routine, &(data->philos[i])) != 0)
			destroy_thread("Philosopher thread creation error", data);
	}
	write(1, "aqui1\n", 6);
	if (pthread_create(&monitor, NULL, &spectator, data->philos) != 0)
		destroy_thread("Monitor thread creation error", data);
	write(1, "aqui2\n", 6);
	if (pthread_join(monitor, NULL) != 0)
		destroy_thread("Monitor thread join error", data);
	write(1, "aqui3\n", 6);
	i = -1;
	while (++i < n)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_thread("Philosophers thread join error", data);
	}
}

void	init_arg(t_philo *philo, char **argv)
{
	philo->num_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philo->num_time_to_eat = ft_atoi(argv[5]);
	else
		philo->num_time_to_eat = -1;
}

void	init_struct(t_data *data, t_philo *philos, int i, char **argv)
{
	data->dead_flag = 0;
	data->philos = philos;
	pthread_mutex_init(&data->dead_lock, NULL);
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->meal_lock, NULL);
	while (++i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&data->forks[i], NULL);
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].start_time = get_time();
		philos[i].last_meal = get_time();
		init_arg(&philos[i], argv);
		philos[i].write_lock = &data->write_lock;
		philos[i].dead_lock = &data->dead_lock;
		philos[i].meal_lock = &data->meal_lock;
		philos[i].dead = &data->dead_flag;
		philos[i].l_fork = &data->forks[i];
		if (i == 0)
			philos[i].r_fork = &data->forks[ft_atoi(argv[1]) - 1];
		else
			philos[i].r_fork = &data->forks[i - 1];
	}
}

int	main(int argc, char **argv)
{
	t_data			*data;
	t_philo			philos[PHIL_MAX];
	pthread_mutex_t	forks[PHIL_MAX];
	if (check_args(argc, argv) == 1)
		return (EXIT_FAILURE);
	data = (t_data *)malloc(sizeof(t_data));
	init_struct(data, philos, 0, argv);
	init_forks(forks, ft_atoi(argv[1]));
	init_thread(data, ft_atoi(argv[1]));
	write(1, "Dest\n", 5);
	destroy_thread(NULL, data);
	return (EXIT_SUCCESS);
}
