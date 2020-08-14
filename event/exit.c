/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:36:18 by esende            #+#    #+#             */
/*   Updated: 2020/06/28 20:07:32 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_exit(t_mlx *d)
{
	int i;

	i = -1;
	while (d->filemap[++i])
		free(d->filemap[i]);
	i = -1;
	while (++i < 5)
		mlx_destroy_image(d->mlx_ptr, d->t[i].tex);
	if (!d->save)
		mlx_destroy_image(d->mlx_ptr, d->img.img_ptr);
	free(d->filemap);
	free(d->arg);
	if (d->save)
	{
		mlx_clear_window(d->mlx_ptr, d->win);
		mlx_destroy_window(d->mlx_ptr, d->win);
	}
	free(d->mlx_ptr);
	exit(-1);
}
