/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebferna <sebferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:44 by sebferna          #+#    #+#             */
/*   Updated: 2024/10/14 13:01:04 by sebferna         ###   ########.fr       */
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
# define RC "\033[0m"
# define CYAN "\033[0;96m"
# define GREEN "\033[0;92m"
# define BROWN "\033[38;2;184;143;29m"
# define RED "\033[0;91m"
# define YLW "\033[0;93m"

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
	t_philo			*philos;
}	t_data;

// SPECTATOR
void		*spectator(void *spectator);
int			check_dead(t_philo *philo);
int			check_need_meal(t_philo *philo);
void		check_need_meal2(t_philo *philo);

// ROUTINE
void		*routine(void *philo);

//UTILS
void		philo_msg(char *str, t_philo *philo, int id);
void		destroy_thread(char *error, t_data *data, pthread_mutex_t *forks);
size_t		get_time(void);
int			dead_loop(t_philo *philo);

//CHECK ARGS
int			check_args(int argc, char **str);
int			ft_atoi(char *str);

//INIT
void		init_struct(t_data *d, t_philo *p, char **argv, pthread_mutex_t *f);
void		init_arg(t_philo *philo, char **argv);
void		init_thread(t_data *data, int n, pthread_mutex_t *forks);
void		init_forks(pthread_mutex_t *forks, int nbr);

#endif
