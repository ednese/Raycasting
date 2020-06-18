/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:07:02 by esende            #+#    #+#             */
/*   Updated: 2020/05/05 03:04:01 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_checkchar(const char c, char charset)
{
	if (c == charset)
		return (0);
	return (1);
}

char	*ft_strncpy(char *dest, const char *src, int i, int n)
{
	int	j;

	j = 0;
	while (j < n && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_malloc(char **tab, int n, int size)
{
	int	i;

	i = 0;
	if (!(tab[size] = malloc(sizeof(char) * (n + 1))))
	{
		while (i < size)
		{
			free(tab[i]);
			i++;
		}
		free(tab);
		return (NULL);
	}
	return (tab[size]);
}

int		ft_nsize_words(const char *str, char charset, int size, int i)
{
	int	words;

	words = 0;
	while (str[i] && !size)
	{
		if (ft_checkchar(str[i], charset))
		{
			words++;
			while (ft_checkchar(str[i], charset) && str[i])
				i++;
		}
		else
			i++;
	}
	while (ft_checkchar(str[i], charset) && size && str[i])
	{
		words++;
		i++;
	}
	return (words);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	int		check;
	char	**tab;

	if (!(tab = malloc(sizeof(char *) * (ft_nsize_words(s, c, 0, 0) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	check = 1;
	while (s[++i])
	{
		if (ft_checkchar(s[i], c) && check)
		{
			if (!(tab[j] = ft_malloc(tab, ft_nsize_words(s, c, 1, i), j)))
				return (NULL);
			tab[j] = ft_strncpy(tab[j], s, i, ft_nsize_words(s, c, 1, i));
			j++;
			check = 0;
		}
		else if (!ft_checkchar(s[i], c))
			check = 1;
	}
	tab[j] = NULL;
	return (tab);
}
