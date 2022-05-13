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
	t_philob	*philo;
	t_datab		*data;

	philo = (t_philob *)arg;
	data = philo->shared_data;
	while (philo->shared_data->philo_state != DIE)
	{
		if (ft_timestamp() - philo->last_time_eat > data->time_to_die)
		{
			ft_print_state(data, philo->id + 1 ,"died\n");
			data->philo_state = DIE;
            exit(1);
		}
		else if (data->all_philos_eat == data->nbr_philosophers)
        {
			data->philo_state = DIE;
            exit(2);
        }
		usleep(100);
	}
    return (NULL);
}

void	ft_print_state(t_datab	*data, int	philo_id, char	*str)
{
    sem_wait(data->print_semaphore);
	if (data->philo_state != DIE)
		printf("%ldms  %d  %s", (ft_timestamp() - data->start_time), philo_id, str);
    sem_post(data->print_semaphore);
}

void	ft_eat(t_philob	*philo, t_datab	*data)
{
    sem_wait(data->fork_semaphore);
	ft_print_state(data, philo->id + 1 , "has taken a fork\n");
    sem_wait(data->fork_semaphore);
	ft_print_state(data, philo->id + 1, "has taken a fork\n");
	ft_print_state(data, philo->id + 1, "is eating\n");
	philo->last_time_eat = ft_timestamp();
	// data->philo[philo->id].nmbroftm_philo_eat++;
	ft_precis_usleep(philo, data->time_to_eat);
    sem_post(data->fork_semaphore);
    sem_post(data->fork_semaphore);
}

void *ft_routine(t_philob *philo)
{
    t_datab     *data;

    data = philo->shared_data;
    if (pthread_create(&data->thread, NULL, &ft_chk_deth, (void*)&data->philo) != 0)
        ft_handle_error("THREAD ERROR");
    pthread_detach(data->thread);
    if (philo->id % 2)
        usleep(100);
    while (data->philo_state != DIE)
    {
        ft_eat(philo, data);
        if (philo->nmbroftm_philo_eat == data->nmbroftm_each_philo_eat)
            data->all_philos_eat++;
        ft_print_state(data, philo->id + 1, "is sleeping\n");
        ft_precis_usleep(philo, data->time_to_sleep);
        ft_print_state(data, philo->id + 1, "is thinking\n");
    }
    return (NULL);
}
