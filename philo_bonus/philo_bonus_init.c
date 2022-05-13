/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:21:31 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 11:21:33 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_init_process(t_datab	*data)
{
	int	status;
	int	i;

	i = 0;
	while (i < data->nbr_philosophers)
	{
		data->philo->last_time_eat = ft_timestamp();
		data->philo[i].pid = fork();
		if (data->philo[i].pid == 0)
		{
			ft_routine(&data->philo[i]);
		}
		i++;
	}
	waitpid(-1, &status, 0);
	// if (status == 1)
	// {
	// }
	// else if (status == 2)
	// {
	// }
}

void	ft_init_data(t_datab	*data, char	**args, int	ac, char	**av)
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

	data->id = 0;
	data->last_time_eat = ft_timestamp();
	data->nmbroftm_philo_eat = 0;

	if (data->nbr_philosophers <= 0 || data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
		ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
	if (ac == 6)
	{
		data->nmbroftm_each_philo_eat = ft_atoi(args[4]);
		if (data->nmbroftm_each_philo_eat < 0)
			ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
	}

	ft_init_process(data);
	if(data->nbr_philosophers > SEM_VALUE_MAX)
		ft_handle_error("NUMBER OF SEMAPHORES IS MORE THAN SEM_VALUE_MAX\n");
	sem_unlink("fork_semaphore");
	sem_unlink("print_semaphore");
	data->fork_semaphore = sem_open("fork_semaphore", O_CREAT, 0600, data->nbr_philosophers);
	if (data->fork_semaphore == SEM_FAILED)
		ft_handle_error("SEMAPHORE FAILURE\n");
	data->print_semaphore = sem_open("print_semaphore", O_CREAT, 0600, 1);
	if (data->print_semaphore == SEM_FAILED)
		ft_handle_error("SEMAPHORE FAILURE\n");
}