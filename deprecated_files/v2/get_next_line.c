/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:07 by acrespy           #+#    #+#             */
/*   Updated: 2023/01/04 15:00:07 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str || str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_line(int fd, char **buffer)
{
	long	nb_bytes;
	char	*result;

	nb_bytes = 0;
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (!ft_untilchr(*buffer, '\n'))
	{
		nb_bytes = read(fd, result, BUFFER_SIZE);
		if (nb_bytes == 0)
			break ;
		else if (nb_bytes > 0)
		{
			result[nb_bytes] = '\0';
			*buffer = ft_strjoin(*buffer, result);
		}
		else if (nb_bytes < 0)
			return (NULL);
	}
	free(result);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_line(fd, &buffer);
	if (!line)
		return (NULL);
	result = ft_untilchr(line, '\n');
	buffer = ft_fromchr(line, '\n');
	free(line);
	return (result);
}
