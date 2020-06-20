/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 16:36:18 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:28:25 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_exit(t_mlx *d)
{
	free(d->arg);
	mlx_clear_window(d->mlx_ptr, d->win);
	mlx_destroy_window(d->mlx_ptr, d->win);
	ft_putstr("Quit\n");
	exit(-1);
}
