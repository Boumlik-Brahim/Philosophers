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

void ft_take_right_forks(t_data *data)
{
    pthread_mutex_lock(&data->philo->fork_Mutex);
}

void ft_put_right_forks(t_data *data)
{
    pthread_mutex_unlock(&data->philo->fork_Mutex);
}

void ft_take_left_forks(t_data *data)
{
    pthread_mutex_lock(&data->philo->fork_Mutex);
}

void ft_put_left__forks(t_data *data)
{
    pthread_mutex_unlock(&data->philo->fork_Mutex);
}

// void ft_eat(t_data *data)
// {
    
// }

// void ft_think(t_data *data)
// {
    
// }

// void ft_sleep(t_data *data)
// {
//     data->philo_state = SLEEP; 
//     usleep(data->time_to_sleep);
// }

void *routine(void *arg)
{
    t_data *data;
    data = (t_data *)arg;

    pthread_mutex_lock(&data->philo->fork_Mutex);
    printf("philo nbr wants to eat\n");     
    sleep(1);
    pthread_mutex_unlock(&data->philo->fork_Mutex);
    return NULL;
}

int main(int ac, char **av)
{
    t_data data;
    int     i;

    i = ac;

    data.nbr_philosophers = ft_atoi(av[1]);
    data.time_to_die = ft_atoi(av[2]);
    data.time_to_eat = ft_atoi(av[3]);
    data.time_to_sleep = ft_atoi(av[4]);
    data.nmbroftm_each_philo_eat = ft_atoi(av[5]);
    
    data.philo = (t_philo*)malloc(sizeof(t_philo) * data.nbr_philosophers);

    i = 0;
    while(i++ < data.nbr_philosophers)
    {
        data.philo[i].id = i;
        if (pthread_mutex_init(&data.philo[i].fork_Mutex, NULL)!= 0)
            ft_handle_error("Mutex ERROR");
    }
    i = 0;
    while (i++ < data.nbr_philosophers)
    {
        if (pthread_create(&data.philo[i].thread, NULL, &routine, (void*)&data) != 0)
            ft_handle_error("THREAD ERROR");
        pthread_detach(data.philo[i].thread);
    }
    i = 0;
    while(i++ < data.nbr_philosophers)
        pthread_mutex_destroy(&data.philo[i].fork_Mutex);
    pthread_exit(0);    
}