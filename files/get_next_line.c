/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 09:12:07 by acrespy           #+#    #+#             */
/*   Updated: 2022/11/15 09:12:10 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	int     nb_bytes;
//	char    *buffer;
	char    buffer[] = "Salut, c'est moi";

//	buffer = malloc(10 * sizeof(char));
	nb_bytes = read(fd, buffer, 10);
	printf("%d", nb_bytes);

	return ((char *)"bonjour");
}

int     main(void)
{
	printf("%s", get_next_line(10));

	return (0);
}