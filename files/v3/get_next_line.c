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

#include "get_next_line_v3.h"

char    *ft_join(char *buffer, char *temp)
{
	char	*result;

	result = ft_strjoin(buffer, temp);
	free(buffer);
	return (result);
}


char	*ft_read(int fd)
{
	int 	    nb_bytes;
	char	    temp[BUFFER_SIZE + 1];
	static char	buffer[BUFFER_SIZE + 1];

	nb_bytes = 1;
	while (nb_bytes > 0 && !ft_strchr(buffer, '\n'))
	{
		nb_bytes = read(fd, temp, BUFFER_SIZE);
		ft_join(buffer, temp);
	}
	if (nb_bytes == -1)
		return (NULL);
	buffer[nb_bytes] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	char        *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd);
//	printf(">%s", line);
	return (line);
}
