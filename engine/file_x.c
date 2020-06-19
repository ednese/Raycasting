/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 20:29:13 by esende            #+#    #+#             */
/*   Updated: 2020/06/19 22:06:11 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_file_x(char **file, int ret, int d, int f)
{
	int		i;
	char	*res;

	i = -1;
	while ((*file)[++i])
	{
		if ((*file)[i] == '1')
			ret = 1;
		if ((*file)[i] != '1' && (*file)[i] != ' ')
		    d = 1;
	}
	if (!ret || (d && f) || !(res = malloc(strlen(*file) + 1)))
	    return (0);
	i = -1;
	while ((*file)[++i])
	{
		if ((*file)[i] == ' ')
			res[i] = 'X';
		else
			res[i] = (*file)[i];
	}
	res[i] = 0;
	free(*file);
	*file = res;
	return (1);
}