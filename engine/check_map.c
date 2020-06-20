/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:17:25 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:14:54 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int        value_direction(char **map, int *x, int *y, int d)
{
    int    axe;

    if (d % 2)
    {
        axe = (d % 4 - 2) * -1;
        if (*x + axe >= 0
            && *x + axe < (int)ft_strlen(map[*y])
            && map[*y][*x + axe] != 'X')
        {
            *x += axe;
            return (1);
        }
    }
    else
    {
        axe = d % 4 - 1;
        if (*y + axe >= 0 && map[*y + axe]
            && *x < (int)ft_strlen(map[*y + axe])
            && map[*y + axe][*x] != 'X')
        {
            *y += axe;
            return (1);
        }
    }
    return (0);
}

int        move_ship(char **map, int *x, int *y, int *d)
{
    int way;

    way = 3;
    while (way < 7)
    {
        if (value_direction(map, x, y, (*d + way) % 4))
        {
            *d = (*d + way) % 4;
            return (*d);
        }
        way++;
    }
    return (-1);
}

int    check_map(char **map)
{
    int    x;
    int    y;
    int    start;
    int    d;

    start = 0;
    while (map[0][start] == 'X')
        start++;
    x = start;
    y = 0;
    d = 1;
    if (move_ship(map, &x, &y, &d) == -1
            || map[y][x] != '1')
            return (0);
    while (x != start || y != 0)
        if (move_ship(map, &x, &y, &d) == -1
            || map[y][x] != '1')
            return (0);
    return (1);
}