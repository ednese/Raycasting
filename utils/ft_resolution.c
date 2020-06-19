/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:08 by esende            #+#    #+#             */
/*   Updated: 2020/06/18 22:48:50 by esende           ###   ########.fr       */
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

int		ft_resolution(char *s, t_mlx *d)
{
	int i;
	int width;
    int height;

	i = 0;
	d->width = 0;
	d->height = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9' && !d->width)
			d->width = ft_atonum(s, &i);
		else if (s[i] >= '0' && s[i] <= '9' && d->width)
			d->height = ft_atonum(s, &i);
		else
			i++;
	}
	mlx_get_screen_size(d->mlx_ptr, &width, &height);
	if (d->width > width)
        d->width = width;
	if (d->height > height)
        d->height = height;
	return (0);
}
