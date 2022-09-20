/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:42:40 by magonzal          #+#    #+#             */
/*   Updated: 2022/09/20 20:12:34 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pressup(t_maps *map)
{
	if (map->map[(map->player.x) - 1][map->player.y] == '1')
		return ;
	if (map->map[(map->player.x) - 1][map->player.y] == 'C')
	{
		map->colectible--;
		move(map, 'U');
	}
	if (map->map[(map->player.x) - 1][map->player.y] == 'E')
		endgame(*map);
	if (map->map[(map->player.x) - 1][map->player.y] == '0')
		move(map, 'U');
}

void	pressdown(t_maps *map)
{
	if (map->map[(map->player.x) + 1][map->player.y] == '1')
		return ;
	if (map->map[(map->player.x) + 1][map->player.y] == 'C')
	{
		map->colectible--;
		move(map, 'D');
	}
	if (map->map[(map->player.x) + 1][map->player.y] == 'E')
		endgame(*map);
	if (map->map[(map->player.x) + 1][map->player.y] == '0')
		move(map, 'D');
}

void	pressright(t_maps *map)
{
	if (map->map[map->player.x][(map->player.y) + 1] == '1')
		return ;
	if (map->map[map->player.x][(map->player.y) + 1] == 'C')
	{
		map->colectible--;
		move(map, 'R');
	}
	if (map->map[map->player.x][(map->player.y) + 1] == 'E')
		endgame(*map);
	if (map->map[map->player.x][(map->player.y) + 1] == '0')
		move(map, 'R');
}

void	pressleft(t_maps *map)
{
	printf("X == %d, Y == %d", map->player.x, map->player.y);
	if (map->map[map->player.x][(map->player.y) - 1] == '1')
		return ;
	if (map->map[map->player.x][(map->player.y) - 1] == 'C')
	{
		map->colectible--;
		move(map, 'L');
	}
	if (map->map[map->player.x][(map->player.y) - 1] == 'E')
		endgame(*map);
	if (map->map[map->player.x][(map->player.y) - 1] == '0')
		move(map, 'L');
}

int	key_detect(int keycode, t_maps *map)
{
	if (keycode == 13)
		pressup(map);
	if (keycode == 1)
		pressdown(map);
	if (keycode == 2)
		pressright(map);
	if (keycode == 0)
		pressleft(map);
	if (keycode == 53)
		endwindow(*map);
	ft_printmap(map->map);
	return (0);
}
