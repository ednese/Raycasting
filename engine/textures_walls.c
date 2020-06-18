/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_walls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:02:43 by esende            #+#    #+#             */
/*   Updated: 2020/06/16 17:57:22 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		side_text(t_mlx *d)
{
	if (d->p.side && d->p.step.y == 1)
		return (1);
	else if (d->p.side)
		return (0);
	else if (!d->p.side && d->p.step.x == 1)
		return (3);
	else if (!d->p.side)
		return (2);
	return (0);
}

int		*textures_buff(t_int coord_tex, double t_draw_s, t_int dr, t_mlx *d)
{
	int		*buffer;
	int		i;
	int		side;
	unsigned int	color;
	int		buffer_size;
	double		step;

	i = 0;
	side = side_text(d);
	buffer_size = ft_abs((double)(dr.x - dr.y));
	buffer = malloc(sizeof(int) * buffer_size);
	step = 1.0 * d->t[side].height / d->p.lineheight;
	t_draw_s *= step;
	while (dr.x < dr.y)
	{
		coord_tex.y = (int)t_draw_s & (d->t[side].height - 1);
		t_draw_s += step;
		color = d->t[side].ptr[d->t[side].width * coord_tex.y + coord_tex.x];
		if (d->p.side == 1) 
			color = (color >> 1) & 8355711;
		buffer[i++] = color;
		dr.x++;
	}
	return (buffer);
}

int		*textures_walls(char **map, t_mlx *d, t_pos *p, t_int draw)
{
	double		wall_x;
	double		tex_draw_start;
	t_int		coord_tex;
	int			*buffer;
	int			side;

	side = side_text(d);
	if (!p->side)
		wall_x = p->pos.y + p->walldist * p->raydir.y;
	else
		wall_x = p->pos.x + p->walldist * p->raydir.x;
	wall_x -= floor(wall_x);
	coord_tex.x = (int) (wall_x * (double)d->t[side].width);
	if ((!p->side && p->raydir.x > 0) || (p->side && p->raydir.y < 0))
		coord_tex.x = d->t[side].width - coord_tex.x - 1;
	tex_draw_start = (draw.x - d->height / 2 + p->lineheight / 2);
	buffer = textures_buff(coord_tex, tex_draw_start, draw, d);
	return (buffer);
}
