/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:14:58 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/08 21:49:37 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_print_state(t_data	*data, int	philo_id, char	*str)
{
	pthread_mutex_lock(&data->print_Mutex);
	if (data->philo_state != DIE)
		printf("%ldms  %d  %s", (ft_timestamp() - data->start_time), philo_id, str);
	pthread_mutex_unlock(&data->print_Mutex);
}

void	ft_chk_deth(t_philo	*philo, t_data	*data)
{
	while (philo->shared_data->philo_state != DIE)
	{
		if (ft_timestamp() - philo->last_time_eat > data->time_to_die)
		{
			ft_print_state(data, philo->id + 1 ,"died\n");
			data->philo_state = DIE;
		}
		else if (data->all_philos_eat == data->nbr_philosophers)
			data->philo_state = DIE;
		usleep(100);
	}
}

void	ft_eat(t_philo	*philo, t_data	*data)
{
	pthread_mutex_lock(&data->philo[philo->id].fork_Mutex);
	ft_print_state(data, philo->id + 1 , "has taken a fork\n");
	pthread_mutex_lock(&data->philo[(philo->id + 1) % data->nbr_philosophers].fork_Mutex);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	ft_print_state(data, philo->id + 1, "is eating\n");
	philo->last_time_eat = ft_timestamp();
	data->philo[philo->id].nmbroftm_philo_eat++;
	ft_precis_usleep(philo, data->time_to_eat);
	pthread_mutex_unlock(&data->philo[(philo->id + 1) % data->nbr_philosophers].fork_Mutex);
	pthread_mutex_unlock(&data->philo[philo->id].fork_Mutex);
}

void	free_data(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}