/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:07:03 by esende            #+#    #+#             */
/*   Updated: 2020/07/01 10:09:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	position(t_mlx *d, int key)
{
	if (key == EXIT)
		ft_exit(d);
	if (key == UP)
		d->input += 1 << 0;
	if (key == DOWN)
		d->input += 1 << 1;
	if (key == LEFT)
		d->input += 1 << 2;
	if (key == RIGHT)
		d->input += 1 << 3;
	if (key == CAMLEFT)
		d->input += 1 << 4;
	if (key == CAMRIGHT)
		d->input += 1 << 5;
}

int		press(int key, t_mlx *d)
{
	if (key == EXIT || key == UP || key == DOWN || key == LEFT
		|| key == RIGHT || key == CAMLEFT || key == CAMRIGHT)
		position(d, key);
	else if (key == 65471)
		d->save = 2;
	return (0);
}
