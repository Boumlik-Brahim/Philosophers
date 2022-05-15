/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:21:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 20:46:34 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_unlink(t_datab *data)
{
	sem_unlink("fork_semaphore");
	sem_close(data->fork_semaphore);
	sem_unlink("print_semaphore");
	sem_close(data->print_semaphore);
	free(data->philo.pid);
	exit (0);
}

void	ft_init_data(t_datab *data, int ac, char **av)
{
	ft_empty_arg(ac, av);
	ft_check_integers(av, ac);
	data->start_time = ft_timestamp();
	data->nbr_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->philo_state = 1;
	data->all_philos_eat = 0;
	if (data->nbr_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
	if (ac == 6)
	{
		data->nmbroftm_each_philo_eat = ft_atoi(av[5]);
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
