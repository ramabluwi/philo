/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:22:37 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/06 18:41:29 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *start_routine(void *arg)
{
    t_philo *philos;

    philos = (t_philo *)arg;
    
    printf("thread id : %d\n", philos->id);
    return (NULL);
}