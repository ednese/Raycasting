/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:39:12 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 17:15:21 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_texture_menu(t_mlx *d, t_tex *t, char *path)
{
		t->tex = mlx_xpm_file_to_image(d->mlx_ptr, path, &t->width, &t->height);
		t->ptr = (int *)mlx_get_data_addr(t->tex, &t->bpp, &t->size_line, &t->endian);
		mlx_put_image_to_window(d->mlx_ptr, d->win, t->tex, 0, 0);
		mlx_destroy_image(d->mlx_ptr, t->tex);
}

int		menu(t_mlx *d, int n, int play)
{
	int from;
	int to;
	t_tex		t;

	if (!play)
	{
		if (!n)
			ft_pos(&d->p, d->filemap, d);
		fill_texture_menu(d, &t, "textures/MENU.xpm");
	}
	else if (play == 2)
	{
		mlx_clear_window(d->mlx_ptr, d->win);
		fill_texture_menu(d, &t, "textures/option.xpm");
	}
	else if (play == 3)
	{
		mlx_clear_window(d->mlx_ptr, d->win);
		fill_texture_menu(d, &t, "textures/graphismes.xpm");
	}
	return (0);
}
