/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 02:38:30 by bbrahim           #+#    #+#             */
/*   Updated: 2022/04/16 02:38:32 by bbrahim          ###   ########.fr       */
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
			ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
		free(str);
		i++;
	}
}

void	ft_check_integers(char **str)
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
			ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				ft_handle_error("INVALID ARGS TRY \"--help or -h\" FOR MORE INFORMATIONS.\n");
			j++;
		}
		i++;
	}
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