/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:34:30 by esende            #+#    #+#             */
/*   Updated: 2020/02/27 14:26:16 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_lib(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == 0)
		return (0);
	while ((char)c != s[i] && s[i])
		i++;
	if (!s[i] && c)
		return (0);
	return ((char *)&s[i]);
}
