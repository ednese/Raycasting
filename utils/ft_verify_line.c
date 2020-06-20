/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 11:40:18 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 12:54:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_verify_line(char *s)
{
	int i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i])
	{
		if (s[i] != 'N' && s[i] != 'S' && s[i] != 'E' && s[i] != 'W'
			&& s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != 'X')
				return (1);
		i++;
	}
	return (0);
}
