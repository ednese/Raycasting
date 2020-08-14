/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 20:47:18 by esende            #+#    #+#             */
/*   Updated: 2020/06/28 21:04:57 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ascii_error(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != '2'
					&& map[y][x] != '0' && map[y][x] != 'X'
					&& map[y][x] != 'N' && map[y][x] != 'S'
					&& map[y][x] != 'E' && map[y][x] != 'W')
				ft_error(2);
			x++;
		}
		y++;
	}
	return (0);
}

int		space_error(char **map)
{
	int x;
	int y;

	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'X' &&
					(map[y - 1][x] != '1' || map[y + 1][x] != '1'
					|| map[y][x - 1] != '1' || map[y][x + 1] != '1')
					&& (map[y - 1][x] != 'X' && map[y + 1][x] != 'X'
						&& map[y][x - 1] != 'X' && map[y][x + 1] != 'X'))
				ft_error(2);
			x++;
		}
		y++;
	}
	ascii_error(map);
	return (0);
}
