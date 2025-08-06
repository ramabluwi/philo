/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 19:54:09 by ramroma           #+#    #+#             */
/*   Updated: 2025/08/06 18:31:37 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <stddef.h>

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	long				start_time;
	int				must_eat;
	pthread_mutex_t	*forks;
    pthread_mutex_t	print_mut;
	pthread_mutex_t	death_mut;
}					t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		philo;
	int				meals_eaten;
	int				last_meal;
	int				id;
}					t_philo;

void	*start_routine(void *arg);
void 	*task_of_thread (void *test);
int		init_philos(t_data *data, t_philo *philos);
long	get_curr_time(void);
int		ft_atoi(char *n);
int 	init_data(t_data *data , char **av);
int 	init_threads(t_philo *philos);

#endif