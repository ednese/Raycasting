/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 11:13:36 by esende            #+#    #+#             */
/*   Updated: 2020/06/21 14:28:06 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	equal(char *str, char *str1)
{
	size_t	index;

	index = 0;
	while (str[index] && str[index] == str1[index])
		index++;
	if (str[index] == str1[index])
		return (true);
	return (false);
}
