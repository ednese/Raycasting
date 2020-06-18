/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:19:32 by esende            #+#    #+#             */
/*   Updated: 2020/06/18 17:33:13 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	update_pos(t_mlx *d, int sign, char **map)
{
	if (map[(int) d->p.pos.y][(int) (d->p.pos.x + (d->p.dir.x * sign) * 0.1)] != '1')
		d->p.pos.x = d->p.pos.x + (d->p.dir.x * sign) * 0.1;
	if (map[(int)(d->p.pos.y + (d->p.dir.y * sign) * 0.1)][(int)(d->p.pos.x)] != '1')
		d->p.pos.y = d->p.pos.y + (d->p.dir.y * sign) * 0.1;
}

void	update_pos_inv(t_mlx *d, int sign, char **map)
{
	if (map[(int) d->p.pos.y][(int) (d->p.pos.x - (d->p.dir.y * sign) * 0.1)] != '1')
		d->p.pos.x = d->p.pos.x - (d->p.dir.y * sign) * 0.1;
	if (map[(int)(d->p.pos.y + (d->p.dir.x * sign) * 0.1)][(int)(d->p.pos.x)] != '1')
		d->p.pos.y = d->p.pos.y + (d->p.dir.x * sign) * 0.1;
}

int		key(int key, t_mlx *d)
{
	int	k;
	char *nbr;
	char *screen;
	static int i;

	k = 1;
	if (!i)
			i = 0;
	nbr = ft_itoa(i);
	screen = ft_strjoin("screenshot_", nbr);
	ft_putchar('\n');
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
	else if (key == 65471)
	{
		d->save = 1;
		d->argv[3] = screen;
		i++;
	}
	else
		k = 0;
	if (k)
		ft_put_pixels(d, 1, 1);
	free(nbr);
	free(screen);
	return (0);
}
