/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:11:12 by bbrahim           #+#    #+#             */
/*   Updated: 2022/04/16 02:11:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
#include <time.h>

typedef struct s_data
{
    int nbr_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int nmbroftm_each_philo_eat;

    pthread_t *threads;
    pthread_mutex_t *fork_Mutex;
}   t_data;

void    ft_putstr_fd(char *s, int fd);
int     ft_atoi(const char *str);
void	ft_handle_error(char *str);


#endif