/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 13:13:43 by frcugy            #+#    #+#             */
/*   Updated: 2015/05/03 20:13:13 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_arkanoid.h"

char		**get_map(void)
{
	char	*line;
	char	**tab;
	int		fd;
	int		i;

	i = 0;
	fd = open("map/map1.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		i++;
	}
	close(fd);
	tab = (char**)malloc(sizeof(char*) * i + 2);
	i = 0;
	fd = open("map/map1.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		tab[i] = ft_strdup(line);
		printf("line === %s\n i= %d \n", line, i);
		i++;
	}
	tab[i] = ft_strdup("\0");
	close(fd);
	return (tab);
}
