/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 19:21:01 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/09 19:21:01 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy_thread(char *error, t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	if (error)
	{
		while (error[++i])
			write(1, &error[i], 1);
		write(1, "\n", 1);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	i = -1;
	while (++i < data->philos[0].num_philos)
		pthread_mutex_destroy(&forks[i]);
	free(data);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), EXIT_FAILURE);
	pthread_mutex_unlock(philo->dead_lock);
	return (EXIT_SUCCESS);
}

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == 1)
		printf("gettimeofay() failure\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	philo_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
