/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:42:40 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 19:58:26 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pressup(t_maps *map)
{
	if (map->map[(map->player.x) - 1][map->player.y] == '1')
		return ;
	else if (map->map[(map->player.x) - 1][map->player.y] == 'C')
	{
		map->colectible--;
		map->player.movements++;
		move(map, 'U');
	}
	else if (map->map[(map->player.x) - 1][map->player.y] == 'E')
		endgame(*map);
	else if (map->map[(map->player.x) - 1][map->player.y] == '0')
	{
		move(map, 'U');
		map->player.movements++;
	}
}

void	pressdown(t_maps *map)
{
	if (map->map[(map->player.x) + 1][map->player.y] == '1')
		return ;
	else if (map->map[(map->player.x) + 1][map->player.y] == 'C')
	{
		map->colectible--;
		map->player.movements++;
		move(map, 'D');
	}
	else if (map->map[(map->player.x) + 1][map->player.y] == 'E')
		endgame(*map);
	else if (map->map[(map->player.x) + 1][map->player.y] == '0')
	{
		map->player.movements++;
		move(map, 'D');
	}
}

void	pressright(t_maps *map)
{
	if (map->map[map->player.x][(map->player.y) + 1] == '1')
		return ;
	else if (map->map[map->player.x][(map->player.y) + 1] == 'C')
	{
		map->colectible--;
		map->player.movements++;
		move(map, 'R');
	}
	else if (map->map[map->player.x][(map->player.y) + 1] == 'E')
		endgame(*map);
	else if (map->map[map->player.x][(map->player.y) + 1] == '0')
	{
		move(map, 'R');
		map->player.movements++;
	}
}

void	pressleft(t_maps *map)
{
	if (map->map[map->player.x][(map->player.y) - 1] == '1')
		return ;
	else if (map->map[map->player.x][(map->player.y) - 1] == 'C')
	{
		map->colectible--;
		map->player.movements++;
		move(map, 'L');
	}
	else if (map->map[map->player.x][(map->player.y) - 1] == 'E')
		endgame(*map);
	else if (map->map[map->player.x][(map->player.y) - 1] == '0')
	{
		move(map, 'L');
		map->player.movements++;
	}
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
	return (0);
}
