/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 14:54:07 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 13:08:15 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l1;
	int		l2;
	char	*res;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!(res = malloc(sizeof(char *) * (l1 + l2 + 1))))
		return (0);
	l1 = 0;
	l2 = 0;
	while (s1[l1])
	{
		res[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
	{
		res[l1 + l2] = s2[l2];
		l2++;
	}
	res[l1 + l2] = 0;
	return (res);
}
