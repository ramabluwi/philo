/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 19:50:55 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/08 20:00:57 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	is_sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void	is_thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}

static int	check_death_condition(t_philo *philo)
{
	t_data	*data;
	long	time_since_last_meal;

	data = philo->data;
	pthread_mutex_lock(&data->death_mut);
	time_since_last_meal = get_curr_time() - philo->last_meal;
	if (time_since_last_meal > data->time_to_die)
	{
		if (data->must_eat == -1 || philo->meals_eaten < data->must_eat)
		{
			print_action(philo, "died");
			data->death_flag = 1;
			pthread_mutex_unlock(&data->death_mut);
			return (1);
		}
	}
	pthread_mutex_unlock(&data->death_mut);
	return (0);
}

static int	check_all_full(t_philo *philos, t_data *data)
{
	int	i;
	int	full_count;

	full_count = 0;
	if (data->must_eat == -1)
		return (0);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_lock(&data->death_mut);
		if (philos[i].meals_eaten >= data->must_eat)
			full_count++;
		pthread_mutex_unlock(&data->death_mut);
		i++;
	}
	return (full_count == data->num_of_philos);
}

void	*monitor_routine(void *arg)
{
	t_philo	*philos;
	t_data	*data;
	int		i;

	philos = (t_philo *)arg;
	data = philos[0].data;
	while (1)
	{
		i = 0;
		while (i < data->num_of_philos)
		{
			if (check_death_condition(&philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_full(philos, data))
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
