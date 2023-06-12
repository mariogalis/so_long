/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:25:02 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 20:53:00 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checksize(t_maps map, size_t lon)
{
	int		i;
	int		j;
	char	*opt;

	opt = "CPE01";
	i = 0;
	while (map.map[i])
	{
		j = 0;
		if (ft_strlen(map.map[i]) != lon)
			display("MATRIX ERROR");
		while (map.map[i][j])
		{
			if (ft_strchr(opt, map.map[i][j]) == NULL)
				display("ERROR CHARACTER NOT VALID");
			j++;
		}
	i++;
	}
	return (i);
}

t_maps	checkitems(t_maps map, size_t lon)
{
	int		i;
	int		j;

	i = 0;
	while (map.map[i])
	{
		j = 0;
		while ((size_t)j < lon - 1)
		{
			if (map.map[i][j] == 'C')
				map.colectible++;
			if (map.map[i][j] == 'E')
				map.exit++;
			if (map.map[i][j] == 'P')
			{
				map.numplayer++;
				map.player.x = i;
				map.player.y = j;
			}
			j++;
		}
		i++;
	}
	if (map.numplayer != 1 || map.colectible < 1 || map.exit != 1)
		display("BAD ITEMS");
	return (map);
}

void	checkexterior(t_maps map, size_t lon)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < lon - 1)
	{
		if (map.map[0][j] != '1')
			display("MAP NOT CLOSED");
		j++;
	}
	while (j < lon - 1)
	{
		if (map.map[lon - 1][j] != '1')
			display("MAP NOT CLOSED");
		j++;
	}
	while (map.map[i])
	{
		j = 0;
		if (map.map[i][0] != '1' || map.map[i][lon - 1] != '1')
			display("MAP NOT CLOSED");
		i++;
	}
}
