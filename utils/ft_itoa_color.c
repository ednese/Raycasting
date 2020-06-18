/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:17:14 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 13:09:42 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_print_num(int i, char *base, int n)
{
	char	*res;
	int		d;

	d = 0;
	if (!i)
	{
		d = 1;
		i++;
	}
	if (!(res = malloc(sizeof(char *) * (i + 2))))
		return (0);
	res[i + 1] = 0;
	while (i >= d)
	{
		res[i] = base[n % 16];
		n /= 16;
		i--;
	}
	if (d)
		res[0] = '0';
	return (res);
}

char	*ft_itoahex_color(long int n)
{
	long int	nb;
	long int	i;

	i = 0;
	nb = n;
	while (n >= 16)
	{
		i++;
		n /= 16;
	}
	return (ft_print_num(i, "0123456789ABCDEF", nb));
}
