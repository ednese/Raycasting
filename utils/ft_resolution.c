/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:01:08 by esende            #+#    #+#             */
/*   Updated: 2020/05/16 21:25:49 by esende           ###   ########.fr       */
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
	if (d->height > 1440)
		d->height = 1440;
	if (d->width > 2560)
		d->width = 2560;
	return (0);
}
