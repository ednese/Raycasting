/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:35:27 by esende            #+#    #+#             */
/*   Updated: 2020/06/21 11:05:18 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	file_arg(t_mlx *d, t_arg info, int i)
{
	while (d->arg[++i])
	{
		if (d->arg[i] == 'R')
			info.r += 1;
		else if (d->arg[i] == 'N')
			info.no += 1;
		else if (d->arg[i] == 'S' && d->arg[i + 1] == 'O')
			info.so += 1;
		else if (d->arg[i] == 'W')
			info.we += 1;
		else if (d->arg[i] == 'E' && d->arg[i + 1] == 'A')
			info.ea += 1;
		else if (d->arg[i] == 'S' && (d->arg[i + 1] == '\n' || !d->arg[i + 1]))
			info.s += 1;
		else if (d->arg[i] == 'F')
			info.f += 1;
		else if (d->arg[i] == 'C')
			info.c += 1;
	}
	if (info.r != 1 || info.no != 1 || info.so != 1
			|| info.we != 1 || info.ea != 1 || info.s != 1
			|| info.f != 1 || info.c != 1)
		ft_error(1);
}

void	init_arg(t_mlx *d)
{
	t_arg	info;

	info.r = 0;
	info.no = 0;
	info.so = 0;
	info.we = 0;
	info.ea = 0;
	info.s = 0;
	info.f = 0;
	info.c = 0;
	file_arg(d, info, -1);
}
