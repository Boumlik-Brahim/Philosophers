/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:38:30 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 13:49:33 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_handle_error(char *str)
{
	ft_putstr_fd("\033[0;31m\e[1mError\033[0m\n", 1);
	ft_putstr_fd(str, 1);
}

int	ft_empty_arg(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (i < ac)
	{
		str = ft_strtrim(av[i], " ");
		if (ft_strlen(str) == 0)
			return (-1);
		free(str);
		i++;
	}
	return (0);
}

int	ft_check_integers(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '+' || str[i][j] == '-')
			j++;
		if (str[i][j] == '\0')
			return (-1);
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**ft_join_args(char **av)
{
	char	*res;
	char	**str;
	char	*ptr;
	char	*s;
	int		i;

	i = 0;
	res = ft_strdup("");
	while (av[++i])
	{
		if (av[i][0] == '\0')
			ft_handle_error("SOME ARGS AREN'T INTEGERS\n");
		s = ft_strjoin(av[i], " ");
		ptr = res;
		res = ft_strjoin(res, s);
		free(ptr);
		free(s);
	}
	str = ft_split(res, ' ');
	free(res);
	return (str);
}
