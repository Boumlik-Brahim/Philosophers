/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:35:41 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 11:35:42 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*ft_chk_deth(void *arg)
{
	t_datab		*data;

	data = (t_datab *)arg;
	while (1)
	{
		if (ft_timestamp() - data->philo.last_time_eat > data->time_to_die)
		{
            data->philo_state = DIE;
            sem_wait(data->print_semaphore);
			printf("%ldms  %d  has died\n", (ft_timestamp() - data->start_time), data->philo.id + 1);
            exit(1);
		}
        usleep(100);
	}
    return (NULL);
}

void	ft_print_state(t_datab	*data, int	philo_id, char	*str)
{
    sem_wait(data->print_semaphore);
	printf("%ldms  %d  %s", (ft_timestamp() - data->start_time), philo_id, str);
    sem_post(data->print_semaphore);
}

void	ft_eat(t_datab	*data)
{
    sem_wait(data->fork_semaphore);
	ft_print_state(data, data->philo.id + 1 , "has taken a fork\n");
    sem_wait(data->fork_semaphore);
	ft_print_state(data, data->philo.id + 1, "has taken a fork\n");
	ft_print_state(data, data->philo.id + 1, "is eating\n");
	data->philo.last_time_eat = ft_timestamp();
	data->philo.nmbroftm_philo_eat++;
	ft_precis_usleep(data->time_to_eat);
    sem_post(data->fork_semaphore);
    sem_post(data->fork_semaphore);
    if (data->philo.nmbroftm_philo_eat == data->nmbroftm_each_philo_eat)
    {
        data->philo_state = DIE;
        exit(2);
    }
}

void *ft_routine(t_datab *data)
{
    if (pthread_create(&data->thread, NULL, &ft_chk_deth, (void*)data) != 0)
        ft_handle_error("THREAD ERROR");
    pthread_detach(data->thread);
    while (1)
    {
        ft_eat(data);
        ft_print_state(data, data->philo.id + 1, "is sleeping\n");
        ft_precis_usleep(data->time_to_sleep);
        ft_print_state(data, data->philo.id + 1, "is thinking\n");
    }
    return (NULL);
}