/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:39:12 by esende            #+#    #+#             */
/*   Updated: 2020/06/28 19:43:08 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_fill_color(int w, int h, t_mlx *d)
{
	h = -1;
	while (++h < d->height / 2)
	{
		w = -1;
		while (++w < d->width)
		{
			if (!d->img.data[h * d->width + w])
				d->img.data[h * d->width + w] = d->sky;
		}
	}
	while (++h < d->height)
	{
		w = -1;
		while (++w < d->width)
		{
			if (!d->img.data[h * d->width + w])
				d->img.data[h * d->width + w] = d->floor;
		}
	}
}

void	ft_fill_menu(int w, int h, t_mlx *d)
{
	h = -1;
	while (++h < d->height)
	{
		w = -1;
		while (++w < d->width / 4)
			d->img.data[h * d->width + w] = WHITE;
	}
}

void	update_pos(t_mlx *d, int sign, char **map, int pos)
{
	if (pos == 0)
	{
		if (map[(int)d->p.pos.y][(int)(d->p.pos.x +
					(d->p.dir.x * sign) * 0.1)] != '1')
			d->p.pos.x = d->p.pos.x + (d->p.dir.x * sign) * 0.1;
		if (map[(int)(d->p.pos.y + (d->p.dir.y *
						sign) * 0.1)][(int)(d->p.pos.x)] != '1')
			d->p.pos.y = d->p.pos.y + (d->p.dir.y * sign) * 0.1;
	}
	else
	{
		if (map[(int)d->p.pos.y][(int)(d->p.pos.x -
					(d->p.dir.y * sign) * 0.1)] != '1')
			d->p.pos.x = d->p.pos.x - (d->p.dir.y * sign) * 0.05;
		if (map[(int)(d->p.pos.y + (d->p.dir.x *
						sign) * 0.1)][(int)(d->p.pos.x)] != '1')
			d->p.pos.y = d->p.pos.y + (d->p.dir.x * sign) * 0.05;
	}
}

void	move_player(t_mlx *d)
{
	if (d->input & 1 << 0)
		update_pos(d, 1, d->filemap, 0);
	if (d->input & 1 << 1)
		update_pos(d, -1, d->filemap, 0);
	if (d->input & 1 << 2)
		update_pos(d, 1, d->filemap, 1);
	if (d->input & 1 << 3)
		update_pos(d, -1, d->filemap, 1);
	if (d->input & 1 << 4)
		ft_rotate(d, (double)0.06, 1);
	if (d->input & 1 << 5)
		ft_rotate(d, (double)0.06, 0);
}

int		ft_put_pixels(t_mlx *d)
{
	static int i;

	if (!i)
		i = 0;
	i++;
	d->img.img_ptr = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->img.data =
		(int *)mlx_get_data_addr(d->img.img_ptr, &d->img.bpp,
				&d->img.size_l, &d->img.endian);
	move_player(d);
	ft_fill_color(0, 0, d);
	ft_fill_walls(d->filemap, d);
	if ((d->ac > 2 && i == 1 && equal(tolowercase(d->argv[2]), "--save"))
			|| (d->save == 2 && i > 1))
		header_file(d, "screen");
	else if (i >= 1 || d->save)
		mlx_put_image_to_window(d->mlx_ptr, d->win, d->img.img_ptr, 0, 0);
	mlx_destroy_image(d->mlx_ptr, d->img.img_ptr);
	return (0);
}
