/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:30:52 by esende            #+#    #+#             */
/*   Updated: 2020/02/19 10:29:26 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rotate(t_mlx *d, double v, int n)
{
	double	tmp;
	double	temp;

	tmp = d->p.dir.x;
	temp = d->p.plane.x;
	if (v == 2)
		v = 1.57079;
	if (v == 3)
		v = 3.14158;
	if (v == 4)
		v = 4.71237;
	if (n)
	{
		d->p.dir.x = d->p.dir.x * cos(v) - d->p.dir.y * sin(v);
		d->p.dir.y = tmp * sin(v) + d->p.dir.y * cos(v);
		d->p.plane.x = d->p.plane.x * cos(v) - d->p.plane.y * sin(v);
		d->p.plane.y = temp * sin(v) + d->p.plane.y * cos(v);
	}
	else
	{
		d->p.dir.x = d->p.dir.x * cos(-v) - d->p.dir.y * sin(-v);
		d->p.dir.y = tmp * sin(-v) + d->p.dir.y * cos(-v);
		d->p.plane.x = d->p.plane.x * cos(-v) - d->p.plane.y * sin(-v);
		d->p.plane.y = temp * sin(-v) + d->p.plane.y * cos(-v);
	}
}
