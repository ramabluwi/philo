/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:56:31 by ramroma           #+#    #+#             */
/*   Updated: 2025/08/07 21:19:36 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int main (int argc , char **argv)
{
    t_philo *philos;
    t_data data;
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
        free(philos);
        return (1);
    }
    return (0);
}