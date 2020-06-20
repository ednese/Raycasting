/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:02:43 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:11:28 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_int	draw_start(t_mlx *d, t_double transform)
{
	t_int	drawstart;

	d->s.spritescreen_x = (int)((d->width / 2) *
		(1 + transform.x / transform.y));
	d->s.vmovescreen = (int)(0.0 / transform.y);
	d->s.spriteheight = abs((int)(d->height / transform.y));
	d->s.spritewidth = abs((int)(d->height / transform.y));
	drawstart.y = -d->s.spriteheight / 2 + d->height / 2 + d->s.vmovescreen;
	if (drawstart.y < 0)
		drawstart.y = 0;
	drawstart.x = -d->s.spritewidth / 2 + d->s.spritescreen_x;
	if (drawstart.x < 0)
		drawstart.x = 0;
	return (drawstart);
}

int		*fill_buffer_sprites(t_mlx *d, t_int start, t_int ds, t_int de)
{
	unsigned int	color;
	t_int			tex;
	int				det;
	int				index;
	int				*buffer;

	index = 0;
	tex.x = (int)
		(256 * (start.x - (-d->s.spritewidth / 2 + d->s.spritescreen_x))
		* d->t[4].width / d->s.spritewidth) / 256;
	buffer = malloc(sizeof(int *) * (de.y - ds.y + 1));
	while (++start.y < de.y)
	{
		det = (start.y - d->s.vmovescreen) *
			256 - d->height * 128 + d->s.spriteheight * 128;
		tex.y = ((det * d->t[4].height) / d->s.spriteheight) / 256;
		color = d->t[4].ptr[d->t[4].width * tex.y + tex.x];
		buffer[index] = color;
		index++;
	}
	return (buffer);
}

void	draw_sprites(t_mlx *d, t_double transform, t_int ds, t_int de)
{
	t_int	start;
	t_int	draw;
	int		*buffer;

	start.x = ds.x - 1;
	start.y = ds.y - 1;
	while (++start.x < de.x)
	{
		if (transform.y > 0 && start.x > 0 && start.x < d->width
			&& transform.y < d->zbuffer[start.x])
		{
			draw.x = ds.y;
			draw.y = de.y;
			buffer = fill_buffer_sprites(d, start, ds, de);
			ft_verline_sprite(d, draw, start.x, (int *)buffer);
			free(buffer);
		}
	}
}

void	engine_sprites(int i, int *s_ord, t_dble tab_sprite, t_mlx *d)
{
	t_double	sprite;
	double		invdet;
	t_double	transform;
	t_int		drawend;
	t_int		drawstart;

	sprite.x = tab_sprite.x[s_ord[i]] - d->p.pos.x;
	sprite.y = tab_sprite.y[s_ord[i]] - d->p.pos.y;
	invdet = 1.0 / (d->p.plane.x * d->p.dir.y - d->p.dir.x * d->p.plane.y);
	transform.x = invdet * (d->p.dir.y * sprite.x - d->p.dir.x * sprite.y);
	transform.y = invdet * (-d->p.plane.y * sprite.x + d->p.plane.x * sprite.y);
	drawstart = draw_start(d, transform);
	drawend.y = d->s.spriteheight / 2 + d->height / 2 + d->s.vmovescreen;
	if (drawend.y >= d->height)
		drawend.y = d->height - 1;
	drawend.x = d->s.spritewidth / 2 + d->s.spritescreen_x;
	if (drawend.x >= d->width)
		drawend.x = d->width - 1;
	draw_sprites(d, transform, drawstart, drawend);
}

void	fill_sprites(char **map, t_mlx *d)
{
	int		i;
	int		*s_ord;
	double	*sprite_dist;
	t_dble	tab_sprite;

	i = -1;
	sprite_dist = malloc(sizeof(double) * d->numsprites);
	tab_sprite = srch_sprites(map, d->numsprites);
	while (++i < d->numsprites)
		sprite_dist[i] =
			((d->p.pos.x - tab_sprite.x[i]) * (d->p.pos.x - tab_sprite.x[i])) +
			((d->p.pos.y - tab_sprite.y[i]) * (d->p.pos.y - tab_sprite.y[i]));
	s_ord = sort_sprites(d->numsprites, sprite_dist);
	i = 0;
	while (i < d->numsprites)
	{
		engine_sprites(i, s_ord, tab_sprite, d);
		i++;
	}
	free(s_ord);
	free(sprite_dist);
	free(tab_sprite.x);
	free(tab_sprite.y);
}
