/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 21:43:48 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/08 18:19:01 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i++], NULL))
			return (1);
	}
	if (pthread_mutex_init(&data->print_mut, NULL))
		return (1);
	if (pthread_mutex_init(&data->death_mut, NULL))
		return (1);
	return (0);
}

int	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = data->start_time;
		philos[i].data = data;
		philos[i].right_fork = i;
		philos[i].left_fork = (i + 1) % data->num_of_philos;
		i++;
	}
	return (0);
}

int	init_data(t_data *data, char **av)
{
	data->num_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->must_eat = ft_atoi(av[5]);
	else
		data->must_eat = -1;
	data->start_time = get_curr_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_of_philos);
	if (!data->forks)
		return (1);
	data->death_flag = 0;
	init_mutexes(data);
	return (0);
}

int	init_threads(t_philo *philos)
{
	int			i;
	int			num;
	pthread_t	monitor;

	num = philos[0].data->num_of_philos;
	i = 0;
	while (i < num)
	{
		if (pthread_create(&philos[i].philo, NULL, start_routine, &philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, philos))
		return (1);
	i = 0;
	while (i < num)
	{
		if (pthread_join(philos[i].philo, NULL))
			return (1);
		i++;
	}
	if (pthread_join(monitor, NULL))
		return (1);
	return (0);
}
