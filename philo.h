/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:54:09 by ramroma           #+#    #+#             */
/*   Updated: 2025/08/08 20:07:07 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	long			start_time;
	_Atomic int		must_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mut;
	pthread_mutex_t	death_mut;
	_Atomic int		death_flag;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	int				left_fork;
	int				right_fork;
	pthread_t		philo;
	_Atomic int		meals_eaten;
	_Atomic long	last_meal;
	int				id;
}					t_philo;

void				*start_routine(void *arg);
int					init_mutexes(t_data *data);
int					init_philos(t_data *data, t_philo *philos);
long				get_curr_time(void);
int					ft_atoi(char *n);
int					init_data(t_data *data, char **av);
int					init_threads(t_philo *philos);
int					take_forks(t_philo *philo);
int					is_eating(t_philo *philo);
long				time_stp(t_philo *philo);
void				print_action(t_philo *philo, const char *msg);
void				is_sleeping(t_philo *philo);
void				is_thinking(t_philo *philo);
void				ft_usleep(int ms);
void				*monitor_routine(void *arg);
void				destroy_all(t_data *data, t_philo *philos);
int					release_forks(t_philo *philo);
int					is_dead(t_data *data);

#endif
