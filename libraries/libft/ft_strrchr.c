/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:05:43 by esende            #+#    #+#             */
/*   Updated: 2019/10/18 11:37:25 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (c)
		i--;
	while ((char)c != s[i] && s[i] && c && i)
		i--;
	if ((!s[i] || s[i] != (char)c) && c)
		return (0);
	return ((char *)&s[i]);
}
