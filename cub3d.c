/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:18:03 by esende            #+#    #+#             */
/*   Updated: 2020/06/19 21:28:55 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>

int		main(int ac, char **av)
{
	t_mlx	d;

	d.ac = ac;
	d.argv = av;
	if (!av[1])
		ft_error(6);
	ft_init_struct(&d, d.argv);
	ft_put_pixels(&d, 0, 1);
	mlx_hook(d.win, KeyPress, KeyPressMask, key, &d);
	mlx_mouse_hook(d.win, managed_mouse, &d);
	mlx_hook(d.win, DestroyNotify, StructureNotifyMask, ft_exit, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
