/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:22:37 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/07 21:35:57 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *start_routine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    
    if (philo->id % 2 == 0)
        usleep(1000);
    while (1)
    {
        is_eating(philo);
        is_sleeping(philo);
		is_thinking(philo);
    }
    return (NULL);
}
int take_forks(t_philo *philo)
{
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
    return 0;
}

int release_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);

    return 0;
}

int is_eating(t_philo *philo)
{
    take_forks(philo);
	print_action(philo, "is eating");
	philo->last_meal = get_curr_time();
	ft_usleep(philo->data->time_to_eat);
	philo->meals_eaten++;
	release_forks(philo);
    return (0);
}
 
long time_stp(t_philo *philo)
{
    long curr;

    curr = get_curr_time();
    return (curr - philo->data->start_time);
}

void is_sleeping(t_philo *philo)
{
	print_action(philo, "is sleeping");
	ft_usleep(philo->data->time_to_sleep);
}

void is_thinking(t_philo *philo)
{
	print_action(philo, "is thinking");
}