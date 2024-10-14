/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:31:53 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/14 12:35:44 by sebferna         ###   ########.fr       */
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

void	init_thread(t_data *data, int n, pthread_mutex_t *forks)
{
	pthread_t	monitor;
	int			i;

	i = -1;
	while (++i < n)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&routine, &(data->philos[i])) != 0)
			destroy_thread("Philosopher thread creation error", data, forks);
	}
	if (pthread_create(&monitor, NULL, &spectator, data->philos) != 0)
		destroy_thread("Monitor thread creation error", data, forks);
	if (pthread_join(monitor, NULL) != 0)
		destroy_thread("Monitor thread join error", data, forks);
	i = -1;
	while (++i < n)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_thread("Philosophers thread join error", data, forks);
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

void	init_struct(t_data *d, t_philo *p, char **argv, pthread_mutex_t *f)
{
	int	i;

	d->dead_flag = 0;
	d->philos = p;
	pthread_mutex_init(&d->dead_lock, NULL);
	pthread_mutex_init(&d->write_lock, NULL);
	pthread_mutex_init(&d->meal_lock, NULL);
	i = -1;
	init_forks(f, ft_atoi(argv[1]));
	while (++i < ft_atoi(argv[1]))
	{
		p[i].id = i + 1;
		p[i].meals_eaten = 0;
		p[i].start_time = get_time();
		p[i].last_meal = get_time();
		init_arg(&p[i], argv);
		p[i].write_lock = &d->write_lock;
		p[i].dead_lock = &d->dead_lock;
		p[i].meal_lock = &d->meal_lock;
		p[i].dead = &d->dead_flag;
		p[i].l_fork = &f[i];
		p[i].r_fork = &f[(i + ft_atoi(argv[1]) - 1) % ft_atoi(argv[1])];
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
	init_struct(data, philos, argv, forks);
	init_thread(data, ft_atoi(argv[1]), forks);
	destroy_thread(NULL, data, forks);
	return (EXIT_SUCCESS);
}
