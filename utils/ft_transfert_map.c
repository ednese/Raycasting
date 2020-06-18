/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transfert_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:12:03 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 17:01:08 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_count_nbr(char *s, t_mlx *d)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			i++;
			ret++;
		}
		else
			i++;
	}
	return (ret);
}

int		ft_delete_space(char **s, t_mlx *d)
{
	int		i;
	int		ret;
	char	*res;

	i = 0;
	ret = 0;
	if (!(res = malloc(ft_count_nbr(*s, d) + 1)))
		return (0);
	while ((*s)[i])
	{
		if ((*s)[i] != ' ')
		{
			res[ret] = (*s)[i];
			ret++;
			i++;
		}
		else
			i++;
	}
	res[ret] = 0;
	free(*s);
	*s = res;
	if (ft_verify_line(*s))
		ft_error(2);
	return (ret);
}

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

char	*ft_strnjoin(char **dst, char *str, t_mlx *d)
{
	char	*res;
	size_t	index;
	size_t	len;

	if (!(res = malloc(ft_strlen(*dst) + ft_count_nbr(str, d) + 2)))
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

char	*ft_transfert_map(t_mlx *d, int fd, char *line)
{
	char	*s;
	int		ret;
	int		tmp;
	int		rd;

	if (!(s = malloc(1)))
		return NULL;
	*s = 0;
	tmp = 0;
	rd = 1;
	ret = ft_count_nbr(line, d);
	tmp = ft_delete_space(&line, d);
	ft_strdouble(&s, line);
	ft_free_str(&line);
	rd = get_next_line(fd, &line);
	while (rd)
	{
		if (ret != tmp)
			ft_error(2);
		tmp = ft_delete_space(&line, d);
		ft_strnjoin(&s, line, d);
		ft_free_str(&line);
		rd = get_next_line(fd, &line);
	}
	ft_free_str(&line);
	return (s);
}
