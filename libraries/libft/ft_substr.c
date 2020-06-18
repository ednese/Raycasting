/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:32:41 by esende            #+#    #+#             */
/*   Updated: 2019/10/19 08:54:27 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start > ft_strlen(s))
		return ("\0");
	if (ft_strlen(s) - start > len)
	{
		if (!(sub = malloc((len + 1) * sizeof(char))))
			return (NULL);
	}
	else if (!(sub = malloc((ft_strlen(s) - start + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return ((char *)sub);
}
