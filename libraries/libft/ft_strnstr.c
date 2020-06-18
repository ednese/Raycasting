/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:29:14 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 16:03:55 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int	i;
	int j;

	i = 0;
	if (to_find[0] != 0)
	{
		while (str[i] != 0 && len > 0)
		{
			j = 0;
			while (to_find[j] == str[i + j] && len - j)
			{
				if (to_find[j + 1] == 0)
					return ((char *)&str[i]);
				j++;
			}
			i++;
			len--;
		}
		return (0);
	}
	return ((char *)str);
}
