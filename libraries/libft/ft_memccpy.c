/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:23:15 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 13:25:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*source;
	char	*dest;
	size_t	i;

	i = 0;
	source = (char *)src;
	dest = (char *)dst;
	while (i < n)
	{
		dest[i] = source[i];
		if (c == dest[i])
			return (dst + i + 1);
		i++;
	}
	return (0);
}
