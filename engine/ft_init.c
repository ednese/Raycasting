/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:46:10 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:00:20 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		format_cub(char **av)
{
	int i;

	i = 0;
	while (av[1][i])
	{
		if (av[1][i] == 'c' && av[1][i + 1] == 'u')
		{
			if (av[1][i + 2] == 'b' && av[1][i + 3] == 0)
				return (0);
		}
		i++;
	}
	ft_error(7);
	return (-1);
}

int		ft_managed_map(char *s, t_mlx *d)
{
	if (s[0] != '\n' && s[0] != ' ' && s[0] != '\0')
		ft_strmore(&d->arg, s);
	if (s[0] == 'R')
		ft_resolution(s, d);
	else if (s[0] == 'F')
		d->floor = ft_rgb_to_hex(s);
	else if (s[0] == 'C')
		d->sky = ft_rgb_to_hex(s);
	return (0);
}

int		ft_managed_textures(char **av, t_mlx *d)
{
	int		ret;
	char	*s;
	int		fd;

	s = NULL;
	fd = open(av[1], O_RDONLY);
	ret = get_next_line(fd, &s);
	while (ret && (s[0] != 'X' && s[0] != '1'))
	{
		if (s[0] == 'N' || s[0] == 'S' || s[0] == 'E' || s[0] == 'W')
			textures_init(d, s);
		ft_free_str(&s);
		ret = get_next_line(fd, &s);
	}
	ft_free_str(&s);
	return (0);
}

int		ft_managed_file(t_mlx *d, char **av)
{
	char	*file;
	int		fd;
	int		ret;
	char	*s;

	format_cub(av);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error(8);
	file = NULL;
	ret = get_next_line(fd, &file);
	while (ret && (!ft_file_x(&file, 0, 0, 1)))
	{
		ft_managed_map(file, d);
		ft_free_str(&file);
		ret = get_next_line(fd, &file);
	}
	s = ft_transfert_map(fd, file);
	d->filemap = ft_split(s, '\n');
	free(s);
	if (!check_map(d->filemap))
		ft_error(2);
	return (fd);
}

void	ft_init_struct(t_mlx *d, char **av)
{
	d->arg = malloc(1);
	*d->arg = 0;
	d->error = 0;
	d->mlx_ptr = mlx_init();
	ft_managed_file(d, av);
	d->win = mlx_new_window(d->mlx_ptr, d->width, d->height, "CUB3D");
	d->map = NULL;
	ft_managed_textures(av, d);
	init_arg(d);
	d->save = 0;
}
