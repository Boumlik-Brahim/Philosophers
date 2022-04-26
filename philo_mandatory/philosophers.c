/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:10:48 by bbrahim           #+#    #+#             */
/*   Updated: 2022/04/16 02:10:49 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	free_data(char **ptr)
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

int ft_init_data(t_data *data, char **args, int ac, char **av)
{
    if (ft_empty_arg(ac, av) == -1 || ft_check_integers(args) == -1)
        return (-1);
    data->nbr_philosophers = ft_atoi(args[0]);
    data->time_to_die = ft_atoi(args[1]);
    data->time_to_eat = ft_atoi(args[2]);
    data->time_to_sleep = ft_atoi(args[3]);
    if (data->nbr_philosophers < 0 || data->time_to_die < 0 || data->time_to_eat < 0 || data->time_to_sleep < 0)
        return (-1);
    if (ac == 6)
    {
        data->nmbroftm_each_philo_eat = ft_atoi(args[4]);
        if (data->nmbroftm_each_philo_eat < 0)
            return (-1);
    }
    return (0);
}

void *routine(void *arg)
{
    t_philo *philo;
    philo = (t_philo *)arg;
    int i;
    i = 0;
    
    while (1)
    {
        pthread_mutex_lock(&philo[i].fork_Mutex);
        pthread_mutex_lock(&philo[(i + 1) % philo->shared_data->nbr_philosophers].fork_Mutex);
        printf("philosopher %d is eating\n",philo[i].id + 1);     
        usleep(200 * 1000);
        pthread_mutex_unlock(&philo[(i + 1) % philo->shared_data->nbr_philosophers].fork_Mutex);
        pthread_mutex_unlock(&philo[i].fork_Mutex);
        i++;
    }
    return NULL;
}

int main(int ac, char **av)
{
    t_data  *data;
    t_philo  *philo;
    char    **args;
    int     i;

    data = (t_data *)malloc(sizeof(t_data));
    if (ac == 2 && !ft_strncmp(av[1], "--help", 6))
    {
        ft_putstr_fd("\"philosophers\" requires 4 argument and 1 [optional] passed as fllows:\n ./philo arg1 arg2 arg3 arg4 [arg 5]\n", 1);
        return (0);
    }
    else if (ac != 5 && ac != 6)
    {
        ft_handle_error("INVALID ARGS TRY \"--help\" FOR MORE INFORMATIONS.\n");
        return (0);
    }
    args = ft_join_args(av);
    if (ft_init_data(data, args, ac, av) == -1)
    {
        ft_handle_error("INVALID ARGS TRY \"--help\" FOR MORE INFORMATIONS.\n");
        return (0);
    }
    philo = (t_philo*)malloc(sizeof(t_philo) * data->nbr_philosophers);

    i = 0;
    while (i < data->nbr_philosophers)
    {
        philo[i].id = i;
        philo[i].shared_data = data;
        i++;
    }

    i = 0;
    while(i < data->nbr_philosophers)
    {
        if (pthread_mutex_init(&philo[i].fork_Mutex, NULL)!= 0)
            ft_handle_error("Mutex ERROR");
        i++;
    }
    i = 0;
    while (i < data->nbr_philosophers)
    {
        if (pthread_create(&philo[i].thread, NULL, &routine, (void*)philo) != 0)
            ft_handle_error("THREAD ERROR");
        pthread_detach(philo[i].thread);
        i++;
    }
    i = 0;
    while(i < data->nbr_philosophers)
    {
        pthread_mutex_destroy(&philo[i].fork_Mutex);
        i++;
    }
    free_data(args);
    while (1){}
    return (0);    
}