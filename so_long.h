/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:22:20 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 21:07:45 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H
# define BUFFER_SIZE 100
# define PIXEL 64
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdlib.h>
# include "42_libft/libft.h"

//GNL//
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strline(char *str);
//SOLONG//
typedef struct s_player
{
	int	x;
	int	y;
	int	movements;
}t_player;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}t_vars;

typedef struct s_sprites{
	int		px;
	void	*player;
	void	*wall;
	void	*worm;
	void	*land;
	void	*home;
}t_sprites;

typedef struct s_maps
{
	char		**map;
	int			x;
	int			y;
	int			colectible;
	int			exit;
	int			numplayer;
	t_player	player;
	t_vars		vars;
	t_sprites	sprites;
}t_maps;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	SZEIMG = 64,
	MAXWIDTH = 5120,
	MAXHEIGHT = 2880
};

void	display(char *err);
t_maps	createmap(char *file,t_maps map);
t_maps	checkmap(t_maps map);
int		checksize(t_maps map, size_t lon);
t_maps	checkitems(t_maps map, size_t lon);
void	checkexterior(t_maps map, size_t lon);
void	pressup(t_maps *map);
void	pressdown(t_maps *map);
void	pressright(t_maps *map);
void	pressleft(t_maps *map);
void	move(t_maps *map, char opt);
int		key_detect(int keycode, t_maps *map);
void	endgame(t_maps map);
int		endwindow(t_maps map);
void	loadsprites(t_maps *map);
int		printmap(t_maps *map);
int		mapname(char *mapname);
void	printmap2(t_maps *map);
#endif