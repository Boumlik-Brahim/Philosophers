/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:25:55 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 12:20:20 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

long int	ft_timestamp(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_precis_usleep(long int sleep_time)
{
	long int	time;

	time = ft_timestamp();
	while (1)
	{
		if (ft_timestamp() - time >= sleep_time)
			break ;
		usleep(100);
	}
}
