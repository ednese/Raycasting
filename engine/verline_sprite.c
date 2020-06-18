/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verline_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 20:31:39 by esende            #+#    #+#             */
/*   Updated: 2020/06/16 20:32:06 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_verline_sprite(t_mlx *d, t_int size, int x, int *color)
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
		d->img.data[y * d->width + x] = color[index];
		index++;
		y++;
	}
	return (index);
}
