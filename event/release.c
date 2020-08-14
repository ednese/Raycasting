/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:06:58 by esende            #+#    #+#             */
/*   Updated: 2020/07/01 10:09:59 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		release(int key, t_mlx *d)
{
	if (key == EXIT)
		ft_exit(d);
	if (key == UP)
		d->input -= 1 << 0;
	if (key == DOWN)
		d->input -= 1 << 1;
	if (key == LEFT)
		d->input -= 1 << 2;
	if (key == RIGHT)
		d->input -= 1 << 3;
	if (key == CAMLEFT)
		d->input -= 1 << 4;
	if (key == CAMRIGHT)
		d->input -= 1 << 5;
	return (0);
}
