/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:02:36 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/14 12:18:33 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	first;

	first = get_time();
	while ((get_time() - first) < milliseconds)
		usleep(500);
	return (EXIT_SUCCESS);
}

void	thinking(t_philo *philo)
{
	philo_msg(GREEN "is thinking" RC, philo, philo->id);
}

void	sleeping(t_philo *philo)
{
	philo_msg(CYAN "is sleeping" RC, philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	eating(t_philo *philo)
{
	if (philo->num_philos == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		philo_msg("has taken a fork", philo, philo->id);
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo_msg("has taken a fork", philo, philo->id);
	philo_msg("has taken a fork", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo_msg(BROWN "is eating" RC, philo, philo->id);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	*routine(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	if (philos->id % 2 == 0)
		ft_usleep(1);
	while (dead_loop(philo) != EXIT_FAILURE)
	{
		eating(philos);
		sleeping(philos);
		thinking(philos);
	}
	return (philos);
}
