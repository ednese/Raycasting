/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srch_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:50:01 by esende            #+#    #+#             */
/*   Updated: 2020/05/16 13:51:33 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dble	srch_sprites(char **map, int n)
{
	t_dble	tab;
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	tab.x = malloc(sizeof(double) * n);
	tab.y = malloc(sizeof(double) * n);
	while (map[y] && n)
	{
		x = 0;
		while(map[y][x] && n)
		{
			if (map[y][x] == '2')
			{
				tab.x[i] = x + 0.5;
				tab.y[i] = y + 0.5;
				i++;
				n--;
			}
			x++;
		}
		y++;
	}
	return (tab);
}