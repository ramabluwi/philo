/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramroma <ramroma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:17:17 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/08 01:50:08 by ramroma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// atoi
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
// get_current_time

long	get_curr_time(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void print_action(t_philo *philo, const char *msg)
{
    pthread_mutex_lock(&philo->data->print_mut);
    printf("%ld %d %s\n", time_stp(philo), philo->id, msg);
    pthread_mutex_unlock(&philo->data->print_mut);
}

void	ft_usleep(int ms)
{
	long	start = get_curr_time();
	while (get_curr_time() - start < ms)
		usleep(500);
}

void destroy_all(t_data *data, t_philo *philos)
{
    int i = 0;

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
