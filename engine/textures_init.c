/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:39:12 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:28:06 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	textures_fill(t_tex *t, t_mlx *d)
{
	t->tex = mlx_xpm_file_to_image(d->mlx_ptr, t->path, &t->width, &t->height);
	if (t->tex)
		t->ptr = (int *)mlx_get_data_addr(t->tex, &t->bpp, &t->size_line, &t->endian);
	else
		ft_error(4);
}

char	*textures_path(char *s, int i)
{
	int		j;
	int		index;
	char	*path;

	j = 0;
	while (s[i] == ' ')
		i++;
	index = i;
	while (s[i++])
		j++;
	if (!(path = malloc(sizeof(char) * j + 4)))
		return (NULL);
	j = 0;
	while (s[index])
		path[j++] = s[index++];
	path[j] = 0;
	return (path);
}

int		other_points(t_mlx *d, char *s, int i)
{
	if (s[0] == 'E')
	{
		d->t[2].path = textures_path(s, 2);
		i = 2;
	}
	else if (s[0] == 'W')
	{
		d->t[3].path = textures_path(s, 2);
		i = 3;
	}
	return (i);
}

int		textures_verif(t_tex *t)
{
	int i;

	i = 0;
	while(t->path[i])
	{
		if (t->path[i] == 'x' && t->path[i + 1] == 'p')
		{
			if (t->path[i + 2] == 'm' && t->path[i + 3] == 0)
				return (0);
		}
		i++;
	}
	ft_error(5);
	return (-1);
}

void	textures_init(t_mlx *d, char *s)
{
	int		i;

	i = 0;
	if (s[0] == 'N')
		d->t[0].path = textures_path(s, 2);
	else if (s[0] == 'S')
	{
		if (s[1] == 'O')
			d->t[1].path = textures_path(s, 2);
		else
		{
			d->t[4].path = textures_path(s, 1);
			i = 3;
		}
		i++;
	}
	else
		i = other_points(d, s, i);
	textures_verif(&d->t[i]);
	textures_fill(&d->t[i], d);
}
