/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:25:00 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:25:02 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strcchr(char *src, int c)
{
	while (*src)
		if (*src++ == c)
			return (1);
	return (0);
}

size_t	ft_strlenn(char *src, int c)
{
	size_t len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	return (len);
}

char	*ft_stradd(char **dst, char *str)
{
	char	*res;
	size_t	index;
	size_t	len;

	if (!(res = malloc(sizeof(char *) * (ft_strlenn(*dst, 0)
		+ ft_strlenn(str, 0) + 1))))
		return (0);
	len = 0;
	while ((*dst)[len])
	{
		res[len] = (*dst)[len];
		len++;
	}
	index = 0;
	while (str[index])
	{
		res[index + len] = str[index];
		index++;
	}
	res[index + len] = 0;
	free(*dst);
	*dst = res;
	return (res);
}

char	*ft_firstchr(char *src, int c)
{
	char	*res;
	size_t	len;

	len = ft_strlenn(src, c);
	if (!(res = malloc(len + 1)))
		return (0);
	res[len] = 0;
	while (len--)
		res[len] = src[len];
	return (res);
}

char	*ft_chrmove(char **dst, int c)
{
	char	*res;
	size_t	index;
	size_t	len;

	index = ft_strlenn(*dst, c);
	if (!(res = malloc(ft_strlenn(*dst, 0) - index + 1)))
		return (0);
	len = ft_strlenn(*dst, 0) - index;
	res[len] = 0;
	while (len--)
		res[len] = (*dst)[index + 1 + len];
	free(*dst);
	*dst = res;
	return (res);
}
