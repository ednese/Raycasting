/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:55:50 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:19:29 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_verline(t_mlx *d, t_int size, int x, int color)
{
	int		index;
	int		y;
	int		abs_y;

	abs_y = size.x - size.y;
	abs_y < 0 ? abs_y = abs_y * -1 : abs_y;
	index = 0;
	y = size.x;
	while (index < abs_y && y < d->height)
	{
		if (!d->img.data[y * d->width + x])
			d->img.data[y * d->width + x] = color;
		index++;
		y++;
	}
	return (index);
}
