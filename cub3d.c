/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:18:03 by esende            #+#    #+#             */
/*   Updated: 2020/06/28 19:33:48 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <X11/X.h>

int		main(int ac, char **av)
{
	t_mlx	d;

	d.ac = ac;
	d.argv = av;
	d.save = 1;
	d.input = 0;
	if (av[2] && equal(tolowercase(av[2]), "--save"))
		d.save = 0;
	if (!av[1])
		ft_error(6);
	ft_init_struct(&d, d.argv);
	ft_pos(&d.p, d.filemap, &d);
	ft_put_pixels(&d);
	mlx_hook(d.win, KeyPress, KeyPressMask, press, &d);
	mlx_hook(d.win, KeyRelease, KeyReleaseMask, release, &d);
	mlx_hook(d.win, DestroyNotify, StructureNotifyMask, ft_exit, &d);
	mlx_loop_hook(d.mlx_ptr, ft_put_pixels, &d);
	mlx_loop(d.mlx_ptr);
	return (0);
}
