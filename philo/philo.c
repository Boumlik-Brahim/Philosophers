/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:10:48 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 14:35:53 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 2 && (!ft_strncmp(av[1], "-h", 2)))
		return (ft_putstr_fd("./philo ar1 ar2 ar3 ar4 [ar5[opt]]\n", 1), 0);
	else if (ac != 5 && ac != 6)
		return (ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n"), -1);
	if (ft_init_data(&data, ac, av) == -1)
		return (ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n"), -1);
	if (ft_init_mutex(&data) == -1)
		return (ft_handle_error("MUTEX ERROR"), -1);
	if (ft_init_thread(&data) == -1)
		return (ft_handle_error("THREAD ERROR"), -1);
	ft_chk_deth(data.philo, &data);
	ft_destroy(&data);
	return (0);
}
