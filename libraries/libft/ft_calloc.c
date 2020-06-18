/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:33:08 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 16:07:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*to_re;

	if (!count && !size)
		return (0);
	if (!(to_re = malloc(count * size)))
		return (NULL);
	return (ft_memset(to_re, 0, count));
}
