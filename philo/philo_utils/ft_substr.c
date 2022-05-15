/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:14:08 by bbrahim           #+#    #+#             */
/*   Updated: 2022/05/09 11:14:11 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static char	*ft_strdup(const char *s1)
{
	char	*str;
	int		l;
	int		i;

	l = 0;
	while (s1[l] != '\0')
		l++;
	str = malloc(sizeof(char) * l + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len + start > slen)
		len = slen - start;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[len] = '\0';
	return (str);
}
