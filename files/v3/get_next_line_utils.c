/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:02 by acrespy           #+#    #+#             */
/*   Updated: 2023/01/04 14:58:58 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v3.h"

char	*ft_strchr(const char *str, int c)
{
	char	*result;

	result = (char *)str;
	while (*result != c && *result != '\0')
		result++;
	if (*result == c)
		return (result);
	else
		return (NULL);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	size_t		i;
	char		*result;

	i = 0;
	if ((size != 0 && nmemb != 0) && ((nmemb * size) / size != nmemb))
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	while (i < nmemb * size)
	{
		result[i] = '\0';
		i++;
	}
	return (result);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i_s1;
	int		i_s2;
	char	*result;

	i_s1 = 0;
	i_s2 = 0;
	result = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && i_s1 < (int)ft_strlen(s1))
	{
		result[i_s1] = s1[i_s1];
		i_s1++;
	}
	while (i_s2 < (int)ft_strlen(s2))
	{
		result[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	result[i_s1 + i_s2] = '\0';
	return (result);
}
