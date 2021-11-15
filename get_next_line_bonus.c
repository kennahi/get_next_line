/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kennahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 22:31:11 by kennahi           #+#    #+#             */
/*   Updated: 2020/01/12 21:47:58 by kennahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int			froo(char **s, int fd, char **line)
{
	*line = ft_strdup("");
	free(s[fd]);
	s[fd] = NULL;
	return (0);
}

int			goot_nooxt_loone(char **s, int fd, char **line)
{
	char	*cup;
	int		i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		*line = ft_substr(s[fd], 0, i);
		cup = ft_strdup(s[fd] + i + 1);
		free(s[fd]);
		s[fd] = cup;
	}
	else
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buffer;
	static char *s[4864];
	int			rder;
	char		*cup;

	if (line == NULL || fd > 4864 || fd < 0 || read(fd, s, 0) < 0)
		return (-1);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (!s[fd])
		s[fd] = ft_strdup("");
	while ((rder = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[rder] = '\0';
		cup = ft_strjoin(s[fd], buffer);
		free(s[fd]);
		s[fd] = cup;
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buffer);
	if (rder == 0 && *s[fd] == '\0')
		return (froo(s, fd, line));
	return (goot_nooxt_loone(s, fd, line));
}
