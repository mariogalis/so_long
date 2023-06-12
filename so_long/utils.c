/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:27:02 by magonzal          #+#    #+#             */
/*   Updated: 2022/10/03 19:42:54 by magonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display(char *err)
{
	int	len;

	len = ft_strlen(err);
	write(1, err, len);
	exit(1);
}

int	mapname(char *m)
{
	int	l;
	int	p;

	l = ft_strlen(m);
	p = l - 4;
	if (m[l - 1] == 'r' && m[l - 2] == 'e' && m[l - 3] == 'b' && m[p] == '.' )
		return (0);
	return (1);
}
