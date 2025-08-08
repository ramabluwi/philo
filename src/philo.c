/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:56:31 by ramroma           #+#    #+#             */
/*   Updated: 2025/08/08 19:50:04 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_dead(t_data *data)
{
	int	result;

	pthread_mutex_lock(&data->death_mut);
	result = data->death_flag;
	pthread_mutex_unlock(&data->death_mut);
	return (result);
}

int	main(int argc, char **argv)
{
	t_philo	*philos;
	t_data	data;

	if (argc != 5 && argc != 6)
	{
		write(2, "wrong number of Args\n", 22);
		return (1);
	}
	if (init_data(&data, argv))
		return (1);
	philos = malloc(sizeof(t_philo) * data.num_of_philos);
	if (!philos)
	{
		free(data.forks);
		return (1);
	}
	init_philos(&data, philos);
	if (init_threads(philos))
	{
		destroy_all(&data, philos);
		return (1);
	}
	destroy_all(&data, philos);
	return (0);
}
