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

#include "get_next_line_v2.h"

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

char	*ft_strdup(const char *s)
{
	int		i;
	char	*result;

	i = 0;
	if (!s)
		return (ft_calloc(1, 1));
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (i <= (int)ft_strlen(s))
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_line(int fd, char **buffer)
{
	long		nb_bytes;
	char	*result;

	nb_bytes = 1;
	result = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (!ft_fromchr(result, '\n'))
	{
		nb_bytes = read(fd, result, BUFFER_SIZE);
		if (nb_bytes > 0)
		{
			result[nb_bytes] = '\0';
			*buffer = ft_strjoin(*buffer, result);
		}
		else if (nb_bytes < 0)
		{
			free(result);
			return (NULL);
		}
		else
			break;
	}
	free(result);
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*result;
	char        *line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_line(fd, &buffer);
	result = ft_untilchr(line, '\n');
	buffer = ft_fromchr(line, '\n');
	free(line);
	return (result);
}
