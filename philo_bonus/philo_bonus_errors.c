/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:38:30 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 20:36:04 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
	exit (0);
}

void	ft_empty_arg(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = ft_strtrim(av[i], " ");
		if (ft_strlen(str) == 0)
			ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
		free(str);
		i++;
	}
}

void	ft_check_integers(char **argv, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				ft_handle_error("INVALID ARGS TRY \"-h\" FOR MORE INF.\n");
			j++;
		}
	}
}
