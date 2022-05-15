/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:10:48 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 12:42:28 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int ac, char **av)
{
	t_datab	data;
	char	**args;

	if (ac == 2 && (!ft_strncmp(av[1], "-h", 2)))
		return (ft_putstr_fd("./philo ar1 ar2 ar3 ar4 [ar5[opt]]\n", 1), 0);
	else if (ac != 5 && ac != 6)
		ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
	args = ft_join_args(av);
	ft_init_data(&data, args, ac, av);
	free_data(args);
	return (0);
}
