/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:56:31 by ramroma           #+#    #+#             */
/*   Updated: 2025/07/31 21:03:13 by ralbliwi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *task_of_thread (void *test)
{
    
}


int main (int argc , int **argv)
{
    if (argc != 5 && argc != 6)
    {
        write(2, "wrong number of Args\n", 22);
        return (1);
    }
}