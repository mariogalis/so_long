/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magonzal <magonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:27:02 by magonzal          #+#    #+#             */
/*   Updated: 2022/09/20 15:52:21 by magonzal         ###   ########.fr       */
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