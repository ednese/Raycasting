/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 09:20:51 by esende            #+#    #+#             */
/*   Updated: 2019/10/19 09:26:48 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_trimset(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_trimlen(char const *str, char const *set)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (ft_trimset(str[i], set) == 0)
			res++;
		i++;
	}
	return (res);
}

int		ft_trimcchr(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str);
	while (ft_trimset(str[i - 1], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*toreturn;

	if (!(toreturn = malloc(sizeof(char) * (ft_trimlen(s1, set) + 1))))
		return (NULL);
	j = 0;
	i = 0;
	while (ft_trimset(s1[i], set) == 1 && s1[i])
		i++;
	while (i < ft_trimcchr(s1, set))
	{
		toreturn[j] = s1[i];
		j++;
		i++;
	}
	toreturn[j] = '\0';
	return (toreturn);
}
