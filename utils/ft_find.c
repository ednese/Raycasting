/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:45:30 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 16:56:56 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


int		ft_find(char *s, char *c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c[0])
		{
			if (s[i] != 'S')
				return (1);
			else if (s[i + 1] == c[1])
				return (1);
		}
		i++;
	}
	return (0);
}