/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixels.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:39:12 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:02:05 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdbool.h>

char	*tolowercase(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] += 'a' - 'A';
		index++;
	}
	return (str);
}

bool	equal(char *str, char *str1)
{
	size_t	index;

	index = 0;
	while (str[index] && str[index] == str1[index])
		index++;
	if (str[index] == str1[index])
		return (true);
	return (false);
}

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

int		ft_put_pixels(t_mlx *d, int n)
{
	static int i;

	if (!i)
		i = 0;
	i++;
	if (!n)
		ft_pos(&d->p, d->filemap, d);
	d->img.img_ptr = mlx_new_image(d->mlx_ptr, d->width, d->height);
	d->img.data =
		(int *)mlx_get_data_addr(d->img.img_ptr, &d->img.bpp,
				&d->img.size_l, &d->img.endian);
	ft_fill_walls(d->filemap, d);
	ft_fill_color(0, 0, d);
	mlx_put_image_to_window(d->mlx_ptr, d->win, d->img.img_ptr, 0, 0);
	if ((d->ac > 2 && i == 1 && equal(tolowercase(d->argv[2]), "--save"))
		|| (d->save && i > 1))
		header_file(d, d->argv[3]);
	mlx_destroy_image(d->mlx_ptr, d->img.img_ptr);
	return (0);
}
