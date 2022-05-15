/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 20:33:47 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_print_state(t_data	*data, int philo_id, char	*str)
{
	pthread_mutex_lock(&data->print_mutex);
	if (data->philo_state != DIE)
		printf("%ldms  %d  %s",
			(ft_timestamp() - data->start_time), philo_id, str);
	pthread_mutex_unlock(&data->print_mutex);
}

void	ft_chk_deth(t_philo	*philo, t_data	*data)
{
	while (philo->shared_data->philo_state != DIE)
	{
		if (ft_timestamp() - philo->last_time_eat > data->time_to_die)
		{
			ft_print_state(data, philo->id + 1, "died\n");
			data->philo_state = DIE;
		}
		else if (data->all_philos_eat == data->nbr_philosophers)
			data->philo_state = DIE;
		usleep(100);
	}
}

void	ft_eat(t_philo	*philo, t_data	*data)
{
	pthread_mutex_lock(&data->philo[philo->id].fork_mutex);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	pthread_mutex_lock(&data->philo[(philo->id + 1)
		% data->nbr_philosophers].fork_mutex);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	ft_print_state(data, philo->id + 1, "is eating\n");
	philo->last_time_eat = ft_timestamp();
	data->philo[philo->id].nmbroftm_philo_eat++;
	ft_precis_usleep(philo, data->time_to_eat);
	pthread_mutex_unlock(&data->philo[(philo->id + 1)
		% data->nbr_philosophers].fork_mutex);
	pthread_mutex_unlock(&data->philo[philo->id].fork_mutex);
}

void	ft_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		pthread_mutex_destroy(&data->philo[i].fork_mutex);
		i++;
	}
	free(data->philo);
}
