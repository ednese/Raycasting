/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 14:46:49 by esende            #+#    #+#             */
/*   Updated: 2020/06/18 19:17:38 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_bmp(int fd, t_mlx *d)
{
	int	h;
	int	w;

	h = d->height;
	while (h-- >= 0)
	{
		w = -1;
		while (++w < d->width)
			write(fd, &d->img.data[h * d->width + w], 4);
	}
}

void	header_image(int fd, t_mlx *d)
{
	int size;
	int plane;
	int unused;

	size = 40;
	plane = 1;
	unused = 0;
	write(fd, &size, sizeof(int));
	write(fd, &d->width, sizeof(int));
	write(fd, &d->height, sizeof(int));
	write(fd, &plane, sizeof(short int));
	write(fd, &d->img.bpp, sizeof(short int));
	write(fd, &unused, sizeof(int) * 6);
}

void	header_file(t_mlx *d, char *filename)
{
	int fd;
	int size;
	int offset;

	if (!filename)
		filename = "save";
	filename = ft_strjoin(filename, ".bmp");
	ft_putstr("Creating ");
	ft_putstr(filename);
	ft_putstr("...%\n");
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	size = 54 + 4 * d->width * d->height;
	offset = 54;
	write(fd, "BM", sizeof(short int));
	write(fd, &size, sizeof(int));
	write(fd, "\0\0\0\0", sizeof(int));
	write(fd, &offset, sizeof(int));
	header_image(fd, d);
	img_bmp(fd, d);
	d->save = 0;
	free(filename);
}
