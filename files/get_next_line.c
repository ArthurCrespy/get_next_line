/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:07 by acrespy           #+#    #+#             */
/*   Updated: 2022/12/16 19:54:15 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(int fd, char *buffer)
{
	int		nb_bytes;
	char	*result;

	if (!buffer)
		result = (ft_calloc(1, 1));
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (!ft_fromchr(result, '\n') && nb_bytes > 0)
	{
		nb_bytes = read(fd, result, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(result);
			return (NULL);
		}
		result[nb_bytes] = '\0';
		buffer = ft_strjoin(buffer, result);
	}
	free(result);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_line(fd, buffer);
	line = ft_untilchr(buffer, '\n');
	buffer = ft_fromchr(buffer, '\n');
	return (line);
}
