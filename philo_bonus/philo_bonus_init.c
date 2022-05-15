/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:21:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 12:46:52 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

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

void	ft_init_data(t_datab *data, char **args, int ac, char **av)
{
	ft_empty_arg(ac, av);
	ft_check_integers(args);
	data->start_time = ft_timestamp();
	data->nbr_philosophers = ft_atoi(args[0]);
	data->time_to_die = ft_atoi(args[1]);
	data->time_to_eat = ft_atoi(args[2]);
	data->time_to_sleep = ft_atoi(args[3]);
	data->philo_state = 1;
	data->all_philos_eat = 0;
	if (data->nbr_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
	if (ac == 6)
	{
		data->nmbroftm_each_philo_eat = ft_atoi(args[4]);
		if (data->nmbroftm_each_philo_eat < 0)
			ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
	}
	data->philo.id = 0;
	data->philo.nmbroftm_philo_eat = 0;
	data->philo.pid = (pid_t *)malloc(sizeof(pid_t) * data->nbr_philosophers);
	ft_semaphore_open(data);
	ft_init_process(data);
	ft_exit(data);
}
