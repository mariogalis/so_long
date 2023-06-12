/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:42:48 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 21:18:03 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_maps	createmap(char *file, t_maps map)
{
	int		fd;
	char	*sline;
	char	*line;

	fd = open(file, O_RDONLY);
	line = NULL;
	sline = get_next_line(fd);
	while (sline)
	{
		line = ft_strjoin(line, sline);
		sline = get_next_line(fd);
	}
	map.map = ft_split(line, '\n');
	map = checkmap(map);
	return (map);
}

t_maps	checkmap(t_maps map)
{
	size_t	lon;

	if (!map.map)
		display("ERROR EMP");
	map.colectible = 0;
	map.exit = 0;
	map.numplayer = 0;
	map.player.x = 0;
	map.player.y = 0;
	lon = ft_strlen(map.map[0]);
	map.x = lon;
	map.y = checksize(map, lon);
	map = checkitems(map, lon);
	checkexterior(map, lon);
	return (map);
}
