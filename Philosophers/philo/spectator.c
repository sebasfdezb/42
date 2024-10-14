/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:45:15 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/14 13:01:22 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_need_meal2(t_philo *philo)
{
	if (philo->num_time_to_eat > 1)
		printf(YLW "\n%d philosophers have eaten %d times\n\n" RC,
			philo->num_philos, philo->num_time_to_eat);
	else if (philo->num_time_to_eat == 1)
		printf(YLW "\n%d philosophers have eaten 1 time\n\n" RC,
			philo->num_philos);
}

int	check_need_meal(t_philo *philo)
{
	int	i;
	int	end_eating;

	i = -1;
	end_eating = 0;
	if (philo[0].num_time_to_eat == -1)
		return (EXIT_SUCCESS);
	while (++i < philo[0].num_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].num_time_to_eat)
			end_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
	}
	if (end_eating == philo[0].num_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		check_need_meal2(philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].num_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (get_time() - philo[i].last_meal >= philo[i].time_to_die)
		{
			pthread_mutex_unlock(philo[i].meal_lock);
			philo_msg(RED "died" RC, &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (EXIT_FAILURE);
		}
		pthread_mutex_unlock(philo[i].meal_lock);
	}
	return (EXIT_SUCCESS);
}

void	*spectator(void *spectator)
{
	t_philo	*s;

	s = spectator;
	while (12)
		if (check_dead(s) == EXIT_FAILURE || check_need_meal(s) == EXIT_FAILURE)
			break ;
	return (s);
}
