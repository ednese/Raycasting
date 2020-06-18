/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:56:21 by esende            #+#    #+#             */
/*   Updated: 2020/04/20 14:59:54 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char		*str;
	unsigned int		i;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	//return (*s);
}