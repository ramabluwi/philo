/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:17:17 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/09 12:53:34 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(char *n)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	while (n[i] >= '0' && n[i] <= '9')
	{
		res = (res * 10) + (n[i] - '0');
		i++;
	}
	return (res * sign);
}

long	get_curr_time(void)
{
	struct timeval	tv;

	gettimeofday (&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void	print_action(t_philo *philo, const char *msg)
{
	if (is_dead(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print_mut);
	if (is_dead(philo->data))
	{
		pthread_mutex_unlock(&philo->data->print_mut);
		return ;
	}
	if (!philo->data->death_flag)
		printf("%ld %d %s\n", get_curr_time() - philo->data->start_time,
			philo->id, msg);
	pthread_mutex_unlock(&philo->data->print_mut);
}

void	ft_usleep(int ms, t_philo *philo)
{
	long	start;

	start = get_curr_time();
	while (get_curr_time() - start < ms)
	{
		if (is_dead(philo->data))
			return ;
		usleep(500);
	}
}

void	destroy_all(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mut);
	pthread_mutex_destroy(&data->death_mut);
	free(data->forks);
	free(philos);
}
