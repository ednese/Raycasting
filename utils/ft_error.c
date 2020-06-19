/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:09:02 by esende            #+#    #+#             */
/*   Updated: 2020/06/19 21:56:16 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int e)
{
	ft_putstr("\033[0;31mError\n");
	if (e == 1)
		ft_putstr("Not enough arguments in the scene description file.\n");
	else if (e == 2)
		ft_putstr("Invalid map.\n");
	else if (e == 3)
		ft_putstr("No position for the player in the map.\n");
	else if (e == 4)
		ft_putstr("Texture was not found.\n");
	else if (e == 5)
		ft_putstr("Wrong format for texture.\n");
	else if (e == 6)
		ft_putstr("An argument is missing\n");
	else if (e == 7)
		ft_putstr("The scene description file is not in the right format\n");
	else if (e == 8)
		ft_putstr("The scene description file was not found\n");
	else if (e == 9)
		ft_putstr("Map is missing in the scene description file\n");
	exit(0);
}
