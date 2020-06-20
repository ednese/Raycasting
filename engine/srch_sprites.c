/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srch_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:11:42 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:11:44 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_dble	srch_sprites(char **map, int n)
{
	t_dble	tab;
	t_int	c;
	int		i;

	c.y = 0;
	i = 0;
	tab.x = malloc(sizeof(double) * n);
	tab.y = malloc(sizeof(double) * n);
	while (map[c.y] && n)
	{
		c.x = 0;
		while (map[c.y][c.x] && n)
		{
			if (map[c.y][c.x] == '2')
			{
				tab.x[i] = c.x + 0.5;
				tab.y[i] = c.y + 0.5;
				i++;
				n--;
			}
			c.x++;
		}
		c.y++;
	}
	return (tab);
}
