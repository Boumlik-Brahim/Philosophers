/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:09:07 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 11:09:10 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

static char	**freealoc(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		st;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && j < ft_count(s, c))
	{
		while (s[i] == c)
			i++;
		st = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		str[j] = ft_substr(s, st, (i - st));
		if (str[j++] == NULL)
			return (freealoc(str, j));
	}
	str[ft_count(s, c)] = NULL;
	return (str);
}
