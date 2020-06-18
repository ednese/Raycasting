/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 09:10:12 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 13:27:57 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*source;
	unsigned char	*dest;
	unsigned char	temp;
	unsigned int	i;

	if (!dst || !src)
		return (NULL);
	i = len;
	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (source > dest)
		while (i--)
		{
			temp = *source++;
			*dest++ = temp;
		}
	else
		while (i--)
		{
			temp = source[i];
			dest[i] = temp;
		}
	return (dst);
}
