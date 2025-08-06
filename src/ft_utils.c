/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralbliwi <ralbliwi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 20:17:17 by ralbliwi          #+#    #+#             */
/*   Updated: 2025/08/06 16:50:31 by ralbliwi         ###   ########.fr       */
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