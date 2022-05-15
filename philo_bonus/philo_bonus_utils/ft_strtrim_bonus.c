/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:16:52 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/15 20:40:18 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers_bonus.h"

static int	ft_isther(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	slen;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	slen = ft_strlen(set);
	i = 0;
	while (ft_isther(set, s1[i]) != 0)
		i++;
	while (ft_isther(set, s1[len - 1]) != 0)
		len--;
	str = ft_substr(s1, i, (len - i));
	return (str);
}
