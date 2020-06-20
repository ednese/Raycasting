/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:47:04 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:10:28 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dist_side(t_pos *p)
{
	if (p->raydir.x < 0)
	{
		p->sidedist.x = (p->pos.x - p->map.x) * p->deltadist.x;
		p->step.x = -1;
	}
	else
	{
		p->sidedist.x = (p->map.x + 1.0 - p->pos.x) * p->deltadist.x;
		p->step.x = 1;
	}
	if (p->raydir.y < 0)
	{
		p->sidedist.y = (p->pos.y - p->map.y) * p->deltadist.y;
		p->step.y = -1;
	}
	else
	{
		p->sidedist.y = (p->map.y + 1.0 - p->pos.y) * p->deltadist.y;
		p->step.y = 1;
	}
}

int		ft_hit(t_pos *p, char **map)
{
	int		side;
	int		hit;

	hit = 0;
	side = 0;
	while (!hit)
	{
		if (p->sidedist.x < p->sidedist.y)
		{
			p->sidedist.x += p->deltadist.x;
			p->map.x += p->step.x;
			side = 0;
		}
		else
		{
			p->sidedist.y += p->deltadist.y;
			p->map.y += p->step.y;
			side = 1;
		}
		if (map[p->map.y][p->map.x] == '1')
			hit = 1;
	}
	return (side);
}

t_int	size_ray(t_pos *p, t_mlx *d, int side)
{
	t_int	draw;

	if (side == 0)
		p->walldist = (p->map.x - p->pos.x + (1 - p->step.x) / 2) / p->raydir.x;
	else
		p->walldist = (p->map.y - p->pos.y + (1 - p->step.y) / 2) / p->raydir.y;
	p->lineheight = (int)(d->height / p->walldist);
	draw.x = -p->lineheight / 2 + d->height / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = p->lineheight / 2 + d->height / 2;
	if (draw.y >= d->height)
		draw.y = d->height - 1;
	return (draw);
}

void	put_walls(char **map, t_mlx *d, t_int draw)
{
	int		w;
	int		*buffer;

	w = -1;
	while (++w < d->width)
	{
		init_ray(&d->p, d, w);
		dist_side(&d->p);
		d->p.side = ft_hit(&d->p, map);
		draw = size_ray(&d->p, d, d->p.side);
		if (d->t[3].ptr[1] && d->t[2].ptr[1] && d->t[1].ptr[1] && d->t[0].ptr[1])
		{
			buffer = textures_walls(d, &d->p, draw);
			ft_verline_tex(d, draw, w, buffer);
		}
		free(buffer);
	}
}

void	ft_fill_walls(char **map, t_mlx *d)
{
	int		w;
	t_int	draw;

	w = -1;
	d->zbuffer = malloc(sizeof(double) * d->width);
	while (++w < d->width)
	{
		init_ray(&d->p, d, w);
		dist_side(&d->p);
		d->p.side = ft_hit(&d->p, map);
		draw = size_ray(&d->p, d, d->p.side);
		d->zbuffer[w] =  d->p.walldist;
	}
	if (d->numsprites)
		fill_sprites(map, d);
	put_walls(map, d, draw);
	free(d->zbuffer);
}
