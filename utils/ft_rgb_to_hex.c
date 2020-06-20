/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:28:06 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 12:35:08 by esende           ###   ########.fr       */
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
	return (res);
}

char	*ft_fill_rgb(int r, int g, int b)
{
	char	*rhex;
	char 	*ghex;
	char 	*bhex;
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

char	*ft_init_rgb(char *s, int r, int g, int b)
{
	int		i;

	i = 0;
	while (s[i] && (!r || !g || !b))
	{
		if (s[i] >= '0' && s[i] <= '9' && !r)
			r = ft_atonumc(s, &i);
		else if (s[i] >= '0' && s[i] <= '9' && !g)
			g = ft_atonumc(s, &i);
		else if (s[i] >= '0' && s[i] <= '9' && !b)
			b = ft_atonumc(s, &i);
		else
			i++;
	}
	if (!r || !g || !b)
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
