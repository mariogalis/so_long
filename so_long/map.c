/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:26:10 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 21:16:05 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	loadsprites(t_maps *map)
{
	int	w;
	int	h;

	map->sprites.land = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->sprites.land = mlx_xpm_file_to_image(map->vars.mlx, \
		"./sprites/land.xpm", &w, &h);
	map->sprites.player = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->sprites.player = mlx_xpm_file_to_image(map->vars.mlx, \
		"./sprites/player.xpm", &w, &h);
	map->sprites.wall = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->sprites.wall = mlx_xpm_file_to_image(map->vars.mlx, \
		"./sprites/wall.xpm", &w, &h);
	map->sprites.worm = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->sprites.worm = mlx_xpm_file_to_image(map->vars.mlx, \
		"./sprites/worm.xpm", &w, &h);
	map->sprites.home = mlx_new_image(map->vars.mlx, SZEIMG, SZEIMG);
	map->sprites.home = mlx_xpm_file_to_image(map->vars.mlx, \
		"./sprites/home.xpm", &w, &h);
}

int	printmap(t_maps *map)
{
	char	*mov;

	printmap2(map);
	mov = ft_itoa(map->player.movements);
	mlx_string_put(map->vars.mlx, map->vars.win, 32, 32, 0x00FF0000, "Pasos:");
	mlx_string_put(map->vars.mlx, map->vars.win, 86, 32, 0x00FF0000, mov);
	free(mov);
	return (0);
}

void	printmap2(t_maps *map)
{
	static int	x;
	static int	y;

	while (y < map->y)
	{
		while (x < map->x)
		{
			if (map->map[y][x] == '0')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
					map->sprites.land, SZEIMG * x, SZEIMG * y);
			else if (map->map[y][x] == '1')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
					map->sprites.wall, SZEIMG * x, SZEIMG * y);
			else if (map->map[y][x] == 'C')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
					map->sprites.worm, SZEIMG * x, SZEIMG * y);
			else if (map->map[y][x] == 'E')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
					map->sprites.home, SZEIMG * x, SZEIMG * y);
			else if (map->map[y][x] == 'P')
				mlx_put_image_to_window(map->vars.mlx, map->vars.win, \
					map->sprites.player, SZEIMG * x, SZEIMG * y);
			x++;
		}
		x = 0;
		y++;
	}
	y = 0;
}
