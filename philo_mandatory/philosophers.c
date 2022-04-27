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

void	print_state(t_philo *philo, int philo_id, char *str)
{
    pthread_mutex_lock(&philo->shared_data->print_Mutex);
    printf("    %d  %s", philo_id, str);
    pthread_mutex_unlock(&philo->shared_data->print_Mutex);
}

void *routine(void *arg)
{
    t_philo *philo;
    int i;

    philo = (t_philo *)arg;
    i = philo->id;
    while (1)
    {
        pthread_mutex_lock(&philo[philo->right_fork].fork_Mutex);
        pthread_mutex_lock(&philo[philo->left_fork].fork_Mutex);
        print_state(philo, philo[i].id + 1,"has taken a fork\n");
        print_state(philo, philo[i].id + 1,"has taken a fork\n");
        print_state(philo, philo[i].id + 1,"is eating\n");
        usleep(philo->shared_data->time_to_eat);
        pthread_mutex_unlock(&philo[philo->right_fork].fork_Mutex);
        pthread_mutex_unlock(&philo[philo->left_fork].fork_Mutex);
    }
    return NULL;
}

int main(int ac, char **av)
{
    t_data  data;
    char    **args;
    int     i;

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
    if (ft_init_data(&data, args, ac, av) == -1)
    {
        ft_handle_error("INVALID ARGS TRY \"--help\" FOR MORE INFORMATIONS.\n");
        return (0);
    }


    ft_init_philo(data.philo,&data);
    i = 0;
    while(i < data.nbr_philosophers)
    {
        if (pthread_mutex_init(&data.philo[i].fork_Mutex, NULL) != 0)
            return (ft_handle_error("Mutex ERROR"), -1);
        i++;
    }
    i = 0;
    while (i < data.nbr_philosophers)
    {
        if (pthread_create(&data.philo[i].thread, NULL, &routine, (void*)&data.philo[i]) != 0)
            ft_handle_error("THREAD ERROR");
        pthread_detach(data.philo[i].thread);
        i++;
    }
    // i = 0;
    // while(i < data.nbr_philosophers)
    // {
    //     pthread_mutex_destroy(&data.philo[i].fork_Mutex);
    //     i++;
    // }
    //free_data(args);
    while (1){}
    return (0);    
}
