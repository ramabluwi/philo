/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:22:37 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/09 13:21:00 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*start_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	if (philo->data->num_of_philos == 1)
		return (NULL);
	while (1)
	{
		if (is_dead(philo->data))
			return (NULL);
		is_eating(philo);
		if (is_dead(philo->data) || (philo->data->must_eat != -1
				&& philo->meals_eaten >= philo->data->must_eat))
			return (NULL);
		is_sleeping(philo);
		if (is_dead(philo->data))
			return (NULL);
		is_thinking(philo);
		usleep(50);
	}
	return (NULL);
}

int	take_forks(t_philo *philo)
{
	if (is_dead(philo->data))
		return (1);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_action(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_action(philo, "has taken a fork");
	}
	return (0);
}

int	release_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
		pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
	}
	return (0);
}

int	is_eating(t_philo *philo)
{
	if (is_dead(philo->data))
		return (1);
	take_forks(philo);
	if (is_dead(philo->data))
	{
		release_forks(philo);
		return (1);
	}
	print_action(philo, "is eating");
	philo->last_meal = get_curr_time();
	philo->meals_eaten++;
	ft_usleep(philo->data->time_to_eat, philo);
	release_forks(philo);
	return (0);
}

long	time_stp(t_philo *philo)
{
	long	curr;

	curr = get_curr_time();
	return (curr - philo->data->start_time);
}
