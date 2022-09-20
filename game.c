/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:19:46 by magonzal          #+#    #+#             */
/*   Updated: 2022/09/20 20:12:15 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	endgame(t_maps map)
{
	if(map.colectible == 0)
		display("YOU WIN");
	else
		map.player.movements++;
}

void	move(t_maps *map, char opt)
{
	if(opt == 'U')
	{
		map->map[map->player.x][map->player.y] = '0';
		map->map[(map->player.x) - 1][map->player.y] = 'P';
		map->player.x = map->player.x -1;
	}
	if(opt == 'D')
	{
		map->map[map->player.x][map->player.y] = '0';
		map->map[(map->player.x) + 1][map->player.y] = 'P';
		map->player.x = map->player.x +1;
	}
	if(opt == 'R')
	{
		map->map[map->player.x][map->player.y] = '0';
		map->map[map->player.x][(map->player.y) + 1] = 'P';
		map->player.y = map->player.y + 1;
	}
	if(opt == 'L')
	{
		map->map[map->player.x][map->player.y] = '0';
		map->map[map->player.x][(map->player.y) - 1] = 'P';
		map->player.y = map->player.y - 1;
	}
}