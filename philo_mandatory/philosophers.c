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

void ft_take_right_forks(t_data *data,int i)
{
    pthread_mutex_lock(&data->fork_Mutex[i]);
}

void ft_put_right_forks(t_data *data,int i)
{
    pthread_mutex_unlock(&data->fork_Mutex[i]);
}

void ft_take_left_forks(t_data *data,int i)
{
    pthread_mutex_lock(&data->fork_Mutex[i]);
}

void ft_put_left__forks(t_data *data,int i)
{
    pthread_mutex_unlock(&data->fork_Mutex[i]);
}

// void ft_eat(t_data *data)
// {
    
// }

void *routine(void *arg)
{
    t_data *data;
    data = (t_data *)arg;
    int i;
    i = 0;
    while(i++ < data->nbr_philosophers)
    {
        pthread_mutex_lock(&data->fork_Mutex[i]);
        printf("philo nbr %d wants to eat\n",i);     
        usleep(500000);
        pthread_mutex_unlock(&data->fork_Mutex[i]);       
    }
    return 0;
}

int main(int ac, char **av)
{
    t_data  *data;
    int     i;

    data = (t_data*)malloc(sizeof(t_data));
    i = ac;

    data->nbr_philosophers = ft_atoi(av[1]);
    data->time_to_die = ft_atoi(av[2]);
    data->time_to_eat = ft_atoi(av[3]);
    data->time_to_sleep = ft_atoi(av[4]);
    data->nmbroftm_each_philo_eat = ft_atoi(av[5]);

    data->threads =  malloc(sizeof(pthread_t) * data->nbr_philosophers);
    data->fork_Mutex =  malloc(sizeof(pthread_mutex_t) * data->nbr_philosophers);

    i = 0;
    while(i < data->nbr_philosophers)
    {
        pthread_mutex_init(&data->fork_Mutex[i], NULL);
        i++;
    }
    i = 0;
    while(i < data->nbr_philosophers)
    {
        if (pthread_create(&data->threads[i], NULL, &routine, (void*)data) != 0)
            ft_handle_error("THREAD ERROR");
        i++;
    }
    i = 0;
    while(i < data->nbr_philosophers)
    {
        if (pthread_join(data->threads[i], NULL) != 0)
            ft_handle_error("THREAD ERROR");
        i++;
    }
    i = 0;
    while(i < data->nbr_philosophers)
    {
        pthread_mutex_destroy(&data->fork_Mutex[i]);
        i++;
    }
    return (0);
}