/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:21:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 13:42:47 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_init_philo(t_philo	*philo, t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		philo[i].id = i;
		philo[i].shared_data = data;
		philo[i].nmbroftm_philo_eat = 0;
		i++;
	}
}

int	ft_init_data(t_data	*data, char	**args, int ac, char **av)
{
	if (ft_empty_arg(ac, av) == -1 || ft_check_integers(args) == -1)
		return (-1);
	data->start_time = ft_timestamp();
	data->nbr_philosophers = ft_atoi(args[0]);
	data->time_to_die = ft_atoi(args[1]);
	data->time_to_eat = ft_atoi(args[2]);
	data->time_to_sleep = ft_atoi(args[3]);
	data->philo_state = 1;
	data->all_philos_eat = 0;
	if (data->nbr_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		return (-1);
	if (ac == 6)
	{
		data->nmbroftm_each_philo_eat = ft_atoi(args[4]);
		if (data->nmbroftm_each_philo_eat <= 0)
			return (-1);
	}
	data->philo = (t_philo *)malloc(sizeof(t_philo) * data->nbr_philosophers);
	ft_init_philo(data->philo, data);
	return (0);
}

int	ft_init_mutex(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		if (pthread_mutex_init(&data->philo[i].fork_mutex, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_init_thread(t_data	*data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		if (pthread_create(&data->philo[i].thread, NULL,
				&ft_routine, (void*) &data->philo[i]) != 0)
			return (-1);
		pthread_detach(data->philo[i].thread);
		i++;
	}
	data->philo->last_time_eat = ft_timestamp();
	return (0);
}
