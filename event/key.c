/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:32 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:07:20 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <time.h>

void	update_pos(t_mlx *d, int sign, char **map)
{
	if (map[(int)d->p.pos.y][(int)(d->p.pos.x +
	(d->p.dir.x * sign) * 0.1)] != '1')
		d->p.pos.x = d->p.pos.x + (d->p.dir.x * sign) * 0.1;
	if (map[(int)(d->p.pos.y + (d->p.dir.y *
	sign) * 0.1)][(int)(d->p.pos.x)] != '1')
		d->p.pos.y = d->p.pos.y + (d->p.dir.y * sign) * 0.1;
}

void	update_pos_inv(t_mlx *d, int sign, char **map)
{
	if (map[(int)d->p.pos.y][(int)(d->p.pos.x -
		(d->p.dir.y * sign) * 0.1)] != '1')
		d->p.pos.x = d->p.pos.x - (d->p.dir.y * sign) * 0.1;
	if (map[(int)(d->p.pos.y + (d->p.dir.x *
		sign) * 0.1)][(int)(d->p.pos.x)] != '1')
		d->p.pos.y = d->p.pos.y + (d->p.dir.x * sign) * 0.1;
}

int		position(t_mlx *d, int key)
{
	int	k;

	k = 1;
	if (key == EXIT)
		ft_exit(d);
	else if (key == UP)
		update_pos(d, 1, d->filemap);
	else if (key == DOWN)
		update_pos(d, -1, d->filemap);
	else if (key == LEFT)
		update_pos_inv(d, 1, d->filemap);
	else if (key == RIGHT)
		update_pos_inv(d, -1, d->filemap);
	else if (key == CAMLEFT)
		ft_rotate(d, (double)0.06, 1);
	else if (key == CAMRIGHT)
		ft_rotate(d, (double)0.06, 0);
	else
		k = 0;
	return (k);
}

int		key(int key, t_mlx *d)
{
	int		k;
	time_t	current;
	char	*str;
	char	*screen;

	k = 1;
	current = time(NULL);
	str = asctime(localtime(&current));
	screen = ft_strjoin("screenshot: ", str);
	if (key == EXIT || key == UP || key == DOWN || key == LEFT
		|| key == RIGHT || key == CAMLEFT || key == CAMRIGHT)
		k = position(d, key);
	else if (key == 65471)
	{
		d->argv[3] = screen;
		k = 1;
		d->save = 1;
	}
	else
		k = 0;
	if (k)
		ft_put_pixels(d, 1);
	free(screen);
	return (0);
}
