/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:09:02 by esende            #+#    #+#             */
/*   Updated: 2020/03/04 19:50:54 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int e)
{
	if (e == 1)
		ft_putstr("Error\nToo few walls around the map.\n");
	if (e == 2)
		ft_putstr("Error\n Invalid map.\n");
	if (e == 3)
		ft_putstr("Error\nNo position for the player in the map.\n");
	if (e == 5)
		ft_putstr("Error\nProblem with textures.\n");
	exit(0);
}
