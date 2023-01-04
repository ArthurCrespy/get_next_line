/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acrespy <acrespy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 14:55:05 by acrespy           #+#    #+#             */
/*   Updated: 2022/12/13 17:25:15 by acrespy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		i;
	int		fd;
	char	*result;

	i = 1;
	fd = open("/mnt/nfs/homes/acrespy/42/42Cursus/42Projets/get_next_line/tests/test3", O_RDONLY);
	while (i <= 10)
	{
		result = get_next_line(3);
		printf("%d: %s\n", i, result);
		i++;
	//	free(result);
	}
	close(fd);
	return (0);
}
