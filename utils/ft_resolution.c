/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:08 by esende            #+#    #+#             */
/*   Updated: 2020/07/01 10:18:46 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_atonum(char *s, int *i)
{
	int res;

	res = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		res = (res * 10) + (s[*i] - 48);
		(*i)++;
	}
	return (res);
}

void	windows(t_mlx *d)
{
	int width;
	int height;

	mlx_get_screen_size(d->mlx_ptr, &width, &height);
	if (d->width > width)
		d->width = width;
	if (d->height > height)
		d->height = height;
}

int		data_resolution(char *s, int save, int i)
{
	int d;

	d = 0;
	if (s[i] >= '0' && s[i] <= '9')
		d += save + 1;
	else if (i
		&& s[i] != ' ')
		ft_error(13);
	else if (!i
		&& s[i] != ' '
		&& s[0] != 'R')
		ft_error(13);
	return (d);
}

void	ft_resolution(char *s, t_mlx *d)
{
	int		i;
	int		e;
	int		save;

	i = 0;
	save = 0;
	while (s[i])
	{
		e = data_resolution(s, save, i);
		if (e == 1)
			d->width = ft_atonum(s, &i);
		else if (e == 2)
			d->height = ft_atonum(s, &i);
		else
			i++;
		if (e)
			save = e;
	}
	if (e != 2)
		ft_error(10);
	windows(d);
}
