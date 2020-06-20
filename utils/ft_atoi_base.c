/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:14:10 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:26:00 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		position_char_base(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_sign(char c, int *sign)
{
	if (c == '-')
		return (*sign *= -1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int		ft_blank(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((base[0] == '\0') || (base[1] == '\0'))
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == ' ' || base[i] == '+' || base[i] == '-'
				|| base[i] == '\t' || base[i] == '\n' || base[i] == '\v'
				|| base[i] == '\f' || base[i] == '\r'
				|| (base[i] <= 32 && base[i] > 126))
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int res;
	int sign;
	int size_base;

	res = 0;
	sign = 1;
	size_base = check_base(base);
	while (ft_blank(*str))
		str++;
	while (ft_sign(*str, &sign))
		str++;
	while (position_char_base(*str, base) != -1)
	{
		res = size_base * (res + position_char_base(*str, base));
		str++;
	}
	res = res / size_base;
	return (res * sign);
}
