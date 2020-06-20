/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfert_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:12:03 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 12:54:12 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdouble(char **s, char *s1)
{
	int		size;
	char	*dest;

	size = ft_strlen(s1);
	if (!(dest = malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	size = 0;
	while (s1[size])
	{
		dest[size] = s1[size];
		size++;
	}
	dest[size] = '\n';
	dest[size + 1] = 0;
	free(*s);
	*s = dest;
	return (*s);
}

char	*ft_strnjoin(char **dst, char *str)
{
	char	*res;
	size_t	index;
	size_t	len;

	if (!(res = malloc(ft_strlen(*dst) + ft_strlen(str) + 2)))
		return (NULL);
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
	res[index + len] = '\n';
	res[index + len + 1] = 0;
	free(*dst);
	*dst = res;
	return (*dst);
}

int		map_missing(char *file)
{
	int		i;
	int		d;

	i = -1;
	d = 0;
	while (file[++i])
	{
		if (file[i] != '1' && file[i] != '2' &&
			file[i] != 'X' && file[i] != ' ')
		    d = 1;
	}
	if (d || i <= 0)
	    return (0);
	return (1);
}

char	*ft_transfert_map(int fd, char *line)
{
	char	*s;
	int		rd;

	if (!(s = malloc(1)))
		return NULL;
	*s = 0;
	rd = 1;
	if (!map_missing(line))
		ft_error(9);
	ft_strdouble(&s, line);
	ft_free_str(&line);
	rd = get_next_line(fd, &line);
	while (rd)
	{
		ft_file_x(&line, 0, 0, 0);
		ft_strnjoin(&s, line);
		ft_free_str(&line);
		rd = get_next_line(fd, &line);
	}
	ft_file_x(&line, 0, 0, 0);
	ft_strnjoin(&s, line);
	ft_free_str(&line);
	return (s);
}
