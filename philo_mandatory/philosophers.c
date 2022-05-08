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
    ft_chk_deth(data.philo,&data);
    while (1)
    {
        if(data.philo_state == DIE)
            break;
    }
    free_data(args);
    return (0);     
}
