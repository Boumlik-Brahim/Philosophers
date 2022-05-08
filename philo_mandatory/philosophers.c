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

int ft_chk_deth(t_philo *philo,t_data *data)
{
    while (philo->shared_data->philo_state != DIE)
    {
        if (ft_timestamp() - philo->last_time_eat > data->time_to_die)
        {
            print_state(data, philo->id + 1 ,"died\n");
            data->philo_state = DIE;
            return (-1);
        }
        else if (data->all_philos_eat == data->nbr_philosophers)
        {
            data->philo_state = DIE;
            return (-1);
        }
        printf("nmbroftm_philo_eat  %d\n",philo->nmbroftm_philo_eat);
        printf("all_philos_eat  %d\n",data->all_philos_eat);
    }
    return (0);
}

void ft_eat(t_philo *philo, t_data *data)
{
    pthread_mutex_lock(&philo[philo->id].fork_Mutex);
    print_state(data, philo->id + 1 , "has taken a fork\n");
    pthread_mutex_lock(&data->philo[(philo->id + 1) % data->nbr_philosophers].fork_Mutex);
    print_state(data, philo->id + 1, "has taken a fork\n");
    print_state(data, philo->id + 1, "is eating\n");
    philo->last_time_eat = ft_timestamp();
    philo->nmbroftm_philo_eat++;
    ft_precis_usleep(philo, data->time_to_eat);
    pthread_mutex_unlock(&data->philo[(philo->id + 1) % data->nbr_philosophers].fork_Mutex);
    print_state(data, philo->id + 1, "put left fork\n");  
    pthread_mutex_unlock(&philo[philo->id].fork_Mutex);
    print_state(data, philo->id + 1, "put right fork\n");
}

void *routine(void *arg)
{
    t_philo *philo;
    t_data *data;

    philo = (t_philo *)arg;
    data = philo->shared_data;
    if (philo->id % 2)
        usleep(100);
    while (data->philo_state != DIE)
    {
        ft_eat(philo, data);
        if (philo->nmbroftm_philo_eat == data->nmbroftm_each_philo_eat)
            data->all_philos_eat++;
        print_state(data, philo->id + 1, "is sleeping\n");
        ft_precis_usleep(philo, data->time_to_sleep);
        print_state(data, philo->id + 1, "is thinking\n");
    }
    return (NULL);
}

int main(int ac, char **av)
{
    t_data  data;
    char    **args;

    if (ac == 2 && (!ft_strncmp(av[1], "--help", 6) || !ft_strncmp(av[1], "-h", 2)))
        return (ft_putstr_fd("\"philosophers\" requires 4 argument and 1 [optional] passed as fllows:\n ./philo arg1 arg2 arg3 arg4 [arg 5]\n", 1), 0);
    else if (ac != 5 && ac != 6)
        return (ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n"), -1);
    args = ft_join_args(av);
    if (ft_init_data(&data, args, ac, av) == -1)
        return (ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n"), -1);
    if (ft_init_mutex(&data) == -1)
        return (ft_handle_error("MUTEX ERROR"), -1);
    if (ft_init_thread(&data) == -1)
        return (ft_handle_error("THREAD ERROR"), -1);
    if(ft_chk_deth(data.philo,&data) == -1)
        return(0);
    free_data(args);
    while (1){}
    return (0);    
}
