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

void *routine()
{
    printf("philo\n");
    return 0;
}

int main(int ac, char **av)
{
    int a;
    int i;

    i = -1;
    while(++i < ac)
    {
        a = ft_atoi(av[i]);
    }
    pthread_t t[a];
    i = -1;
    while(++i < a)
    {
        if (pthread_create(&t[i], NULL, &routine, NULL) != 0)
            ft_handle_error("THREAD ERROR");
    }
    i = -1;
    while(++i < a)
    {
        if (pthread_join(t[i], NULL) != 0)
            ft_handle_error("THREAD ERROR");
    }
    return (0);
}