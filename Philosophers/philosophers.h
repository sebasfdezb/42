/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:44 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/10 12:50:40 by sebferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define PHIL_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_philos;
	int				num_time_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_data
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	forks[PHIL_MAX];
	t_philo			*philos;
}	t_data;

// SPECTATOR
void		*spectator(void *spectator);
int			check_dead(t_philo *philo);
int			check_need_meal(t_philo *philo);

// ROUTINE
void		*routine(void *philo);

//UTILS
void		philo_msg(char *str, t_philo *philo, int id);
int			destroy_thread(char *error, t_data *data);
size_t		get_time(void);

//CHECK ARGS
int			check_args(int argc, char **str);
int			ft_atoi(char *str);

//INIT
void	init_struct(t_data *data, t_philo *philos, int i, char **argv);
void	init_arg(t_philo *philo, char **argv);
void	init_thread(t_data *data, int n);
void	init_forks(pthread_mutex_t *forks, int nbr);

#endif
