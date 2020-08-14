/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verline_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:55:50 by esende            #+#    #+#             */
/*   Updated: 2020/06/21 12:56:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_verline_tex(t_mlx *d, t_int size, int x, int *color)
{
	int		index;
	int		y;
	int		abs_y;
	int		incopy;

	abs_y = size.x - size.y;
	abs_y < 0 ? abs_y = abs_y * -1 : abs_y;
	index = 0;
	y = size.x;
	while (index < abs_y && y < d->height)
	{
		incopy = color[index];
		if ((incopy & 0x00FFFFFF) != 0)
			d->img.data[y * d->width + x] = incopy;
		index++;
		y++;
	}
	return (index);
}
