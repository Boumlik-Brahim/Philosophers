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

void ft_take_fork(t_data *data)
{
    pthread_mutex_lock(&data->fork_Mutex);
}

void ft_put_fork(t_data *data)
{
    pthread_mutex_unlock(&data->fork_Mutex);
}

void ft_eat(t_data *data)
{
    ft_take_fork(data);
    printf("philosopher is eaten\n");
    usleep(data->time_to_eat);
    ft_put_fork(data);
}

void *routine(void *arg)
{       
	t_data *data;

	data = (t_data *)arg;
    ft_eat(data);
    return 0;
}

int main(int ac, char **av)
{
    t_data  data;
    int     i;

    i = ac;
    data.nbr_philosophers = ft_atoi(av[1]);
    data.time_to_die = ft_atoi(av[2]);
    data.time_to_eat = ft_atoi(av[3]);
    data.time_to_sleep = ft_atoi(av[4]);

    pthread_t t[data.nbr_philosophers];
    // pthread_mutex_t fork_Mutex[data.nbr_philosophers];
    // i = 0;
    // while(i < data.nbr_philosophers)
    // {
    //     pthread_mutex_init(&fork_Mutex[i], NULL);
    //     i++;
    // }
    pthread_mutex_init(&data.fork_Mutex, NULL);
    i = 0;
    while(i < data.nbr_philosophers)
    {
        if (pthread_create(&t[i], NULL, &routine, (void *)&data) != 0)
            ft_handle_error("THREAD ERROR");
        i++;
    }
    i = 0;
    while(i < data.nbr_philosophers)
    {
        if (pthread_join(t[i], NULL) != 0)
            ft_handle_error("THREAD ERROR");
        i++;
    }
    pthread_mutex_destroy(&data.fork_Mutex);
    // i = 0;
    // while(i < data.nbr_philosophers)
    // {
    //     pthread_mutex_destroy(&fork_Mutex[i]);
    //     i++;
    // }
    return (0);
}