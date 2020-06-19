/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:33:34 by esende            #+#    #+#             */
/*   Updated: 2020/06/19 22:21:35 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_detect_direction(t_mlx *d, char **map, int x, int y)
{
	if ('0' <= map[y][x] && map[y][x] <= '9')
		return (0);
	else if (map[y][x] == 'S')
	{
		ft_rotate(d, (double)4, 1);
		return (1);
	}
	else if (map[y][x] == 'N')
	{
		ft_rotate(d, (double)2, 1);
		return (2);
	}
	else if (map[y][x] == 'E')
	{
		ft_rotate(d, (double)3, 1);
		return (3);
	}
	else if (map[y][x] == 'W')
		return (4);
	return (0);
}

void	ft_init_pos(t_mlx *d, t_pos *p, int *y)
{
	p->dir.x = -1;
	p->dir.y = 0;
	p->plane.x = 0;
	p->plane.y = 0.66;
	d->numsprites = 0;
	p->pos.x = 0;
	p->pos.y = 0;
	*y = 0;
}

int		ft_pos(t_pos *p, char **map, t_mlx *d)
{
	int x;
	int y;

	ft_init_pos(d, p, &y);
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				d->numsprites++;
			else if (ft_detect_direction(d, map, x, y))
			{
				p->pos.x = x + 0.5;
				p->pos.y = y + 0.5;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (p->pos.x || p->pos.y)
		return (1);
	ft_error(3);
	return (0);
}
