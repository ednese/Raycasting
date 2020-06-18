/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 22:19:00 by esende            #+#    #+#             */
/*   Updated: 2020/06/16 22:19:05 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_ray(t_pos *p, t_mlx *d, int x)
{
	p->camera.x = 2 * x / (double)d->width - 1;
	p->raydir.x = p->dir.x + p->plane.x * p->camera.x;
	p->raydir.y = p->dir.y + p->plane.y * p->camera.x;
	p->map.x = (int)p->pos.x;
	p->map.y = (int)p->pos.y;
	p->deltadist.x = ft_abs(1 / p->raydir.x);
	p->deltadist.y = ft_abs(1 / p->raydir.y);
}