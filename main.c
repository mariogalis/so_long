/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:20:29 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 20:52:14 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define ON_DESTROY 17

int	ft_printmap(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

void	ft_free(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

int	endwindow(t_maps map)
{
	ft_free(map.map);
	mlx_destroy_window(map.vars.mlx, map.vars.win);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_maps	maps;
	int		i;
	int		j;

	maps.map = NULL;
	maps.player.movements = 0;
	if (argc != 2)
		display("wrong number of arguments");
	if (mapname(argv[1]) == 1)
		display("NOT A BER FILE");
	maps = createmap(argv[1], maps);
	maps.vars.mlx = mlx_init();
	loadsprites(&maps);
	i = (maps.x) * 64;
	j = (maps.y) * 64;
	maps.vars.win = mlx_new_window(maps.vars.mlx, i, j, "so_long");
	printmap(&maps);
	mlx_hook(maps.vars.win, ON_DESTROY, 0L, endwindow, &maps);
	mlx_key_hook(maps.vars.win, key_detect, &maps);
	mlx_loop_hook(maps.vars.mlx, printmap, &maps);
	mlx_loop(maps.vars.mlx);
}
