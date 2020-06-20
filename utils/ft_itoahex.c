/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoahex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:24:09 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 12:51:01 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_itoahex(unsigned int n)
{
	char			*base;
	char			*res;
	long int		i;

	i = 0;
	base = "0123456789ABCDEF";
	while (n >= 16)
	{
		i++;
		n /= 16;
	}
	if (!(res = malloc(sizeof(char) * i + 2)))
		return (0);
	res[i + 1] = 0;
	while (i >= 0)
	{
		res[i] = base[n % 16];
		i--;
	}
	return (res);
}
