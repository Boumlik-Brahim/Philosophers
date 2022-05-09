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

#include "philosophers.h"

void *ft_routine(void *arg)
{
    t_philo *philo;
    t_data *data;

    philo = (t_philo *)arg;
    data = philo->shared_data;
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
