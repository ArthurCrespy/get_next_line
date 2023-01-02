/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:02 by acrespy           #+#    #+#             */
/*   Updated: 2022/12/16 23:09:59 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_v2.h"

char	*ft_untilchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	result = ft_calloc(ft_strlen(s) - (ft_strlen(ft_fromchr(s, c))) + 2, 1);
	while (s[i] != c && s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\n';
	result[++i] = '\0';
	if (s[--i] == c)
		return (result);
	else
		return (NULL);
}

char	*ft_fromchr(const char *s, int c)
{
	char	*str;

	if (!s || *s == 0)
		return (NULL);
	str = (char *)s;
	while (*str != c && *str != '\0')
		str++;
	if (*str == c)
	{
		str++;
		return (str);
	}
	else
		return (NULL);
}

char    *ft_calloc(size_t nmemb, size_t size)
{
	size_t  i;
	char    *result;

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
	if (s1)
	{
		while (s1[i_s1])
		{
			result[i_s1] = s1[i_s1];
			i_s1++;
		}
	}
	while (s2[i_s2])
	{
		result[i_s1 + i_s2] = s2[i_s2];
		i_s2++;
	}
	result[i_s1 + i_s2] = '\0';
	return (result);
}
