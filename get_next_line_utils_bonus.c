/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:30:36 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/12 21:48:12 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	length;
	size_t	i;
	size_t	j;

	if (s1 && s2)
	{
		i = 0;
		j = 0;
		len = ft_strlen(s1);
		length = ft_strlen(s2);
		if (!(result = (char *)malloc(sizeof(char) * (len + length + 1))))
			return (NULL);
		while (s1[i])
			result[j++] = s1[i++];
		i = 0;
		while (s2[i])
			result[j++] = s2[i++];
		result[j] = '\0';
		return (result);
	}
	return (NULL);
}

char		*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(copy = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	if (!*s || start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (!(substring = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (start == i)
		{
			while (j < len && s[i])
				substring[j++] = s[i++];
			substring[j] = '\0';
			return (substring);
		}
		i++;
	}
	return (NULL);
}
