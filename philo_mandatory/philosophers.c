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

void *routine(void *arg)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)arg;
    i = philo->id;
    while (philo->philo_state != DIE)
    {
        pthread_mutex_lock(&philo[philo->right_fork].fork_Mutex);
        pthread_mutex_lock(&philo[philo->left_fork].fork_Mutex);
        print_state(philo, philo->id + 1 ,"has taken a fork\n");
        print_state(philo, philo->id + 1,"has taken a fork\n");
        print_state(philo, philo->id + 1,"is eating\n");
        usleep(philo->shared_data->time_to_eat * 1000);
        pthread_mutex_unlock(&philo[philo->left_fork].fork_Mutex);
        pthread_mutex_unlock(&philo[philo->right_fork].fork_Mutex);
        print_state(philo, philo->id + 1,"is thinking\n");
    }
    return NULL;
}

int main(int ac, char **av)
{
    t_data  data;
    char    **args;

    if (ac == 2 && !ft_strncmp(av[1], "--help", 6))
        return (ft_putstr_fd("\"philosophers\" requires 4 argument and 1 [optional] passed as fllows:\n ./philo arg1 arg2 arg3 arg4 [arg 5]\n", 1), 0);
    else if (ac != 5 && ac != 6)
        return (ft_handle_error("INVALID ARGS TRY \"--help\" FOR MORE INFORMATIONS.\n"), -1);
    args = ft_join_args(av);
    if (ft_init_data(&data, args, ac, av) == -1)
        return (ft_handle_error("INVALID ARGS TRY \"--help\" FOR MORE INFORMATIONS.\n"), -1);
    if (ft_init_mutex(&data) == -1)
        return (ft_handle_error("MUTEX ERROR"), -1);
    if (ft_init_thread(&data) == -1)
        return (ft_handle_error("THREAD ERROR"), -1);
    free_data(args);
    while (1){}
    return (0);    
}
