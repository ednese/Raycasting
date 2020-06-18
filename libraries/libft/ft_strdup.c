/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:40:04 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 16:25:09 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1) + 1;
	if (!(dest = (char *)malloc(sizeof(char) * (size))))
		return (NULL);
	size = 0;
	while (s1[size])
	{
		dest[size] = s1[size];
		size++;
	}
	dest[size] = 0;
	return (dest);
}
