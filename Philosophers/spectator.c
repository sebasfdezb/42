/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spectator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:45:15 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/09 13:07:43 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_dead(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].nbr_philos)
	{
		pthread_mutex_lock(philo->meal_lock);
		if (get_time() - philos->last_meal >= time_to_die)
			return (pthread_mutex_unlock(philo->meal_lock), EXIT_FAILURE);
	}
}

void	spectator(void *spectator)
{
	t_philo	*s;

	s = spectator;
	while (50)
		if (cheak_dead(s) == 1 || check_need_meal(spectator) == 1)
			break ;
	return (spectator);
}
