/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:28:06 by esende            #+#    #+#             */
/*   Updated: 2020/07/01 10:35:59 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_atonumc(char *s, int *i)
{
	int	res;

	res = 0;
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		res = (res * 10) + (s[*i] - 48);
		(*i)++;
	}
	if (res > 255)
		ft_error(12);
	return (res);
}

char	*ft_fill_rgb(int r, int g, int b)
{
	char	*rhex;
	char	*ghex;
	char	*bhex;
	char	*temp;
	char	*res;

	rhex = ft_itoahex_color(r);
	ghex = ft_itoahex_color(g);
	bhex = ft_itoahex_color(b);
	temp = ft_strjoin(rhex, ghex);
	res = ft_strjoin(temp, bhex);
	free(rhex);
	free(ghex);
	free(bhex);
	free(temp);
	return (res);
}

int		data_rgb(char *s, int save, int i)
{
	static int	v;
	int			d;

	d = 0;
	if (!v || !i)
		v = 0;
	if (s[i] >= '0' && s[i] <= '9')
		d += save + 1;
	else if (i && s[i] != ' ' && s[i] != ',')
		ft_error(13);
	else if (!i
			&& s[i] != ' '
			&& s[i] != ','
			&& s[0] != 'C'
			&& s[0] != 'F')
		ft_error(13);
	if (s[i] == ',')
		v--;
	if (d && !v)
		v = 1;
	else if (d && v)
		ft_error(13);
	return (d);
}

char	*ft_init_rgb(char *s, int r, int g, int b)
{
	int		i;
	int		d;
	int		save;

	i = 0;
	save = 0;
	while (s[i])
	{
		d = data_rgb(s, save, i);
		if (d == 1)
			r = ft_atonumc(s, &i);
		else if (d == 2)
			g = ft_atonumc(s, &i);
		else if (d == 3)
			b = ft_atonumc(s, &i);
		else
			i++;
		if (d)
			save = d;
	}
	if (save != 3)
		ft_error(11);
	return (ft_fill_rgb(r, g, b));
}

int		ft_rgb_to_hex(char *s)
{
	char	*str;
	int		res;

	str = ft_init_rgb(s, 0, 0, 0);
	res = ft_atoi_base(str, "0123456789ABCDEF");
	free(str);
	return (res);
}
