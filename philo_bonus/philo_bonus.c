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

#include "philosophers_bonus.h"

int main(int ac, char **av)
{
    t_datab  data;
    char    **args;

    if (ac == 2 && (!ft_strncmp(av[1], "--help", 6) || !ft_strncmp(av[1], "-h", 2)))
        return (ft_putstr_fd("\"philosophers\" requires 4 argument and 1 [optional] passed as fllows:\n ./philo arg1 arg2 arg3 arg4 [arg 5]\n", 1), 0);
    else if (ac != 5 && ac != 6)
        ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
    args = ft_join_args(av);
    ft_init_data(&data, args, ac, av);
    // ft_chk_deth(data.philo,&data);
    // while (1)
    // {
    //     if(data.philo_state == DIE)
    //         break;
    // }
    free_data(args);
    return (0);     
}
