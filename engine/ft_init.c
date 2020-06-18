/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:46:10 by esende            #+#    #+#             */
/*   Updated: 2020/06/18 17:30:58 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_managed_map(char *s, t_mlx *d)
{
	if (!ft_find(d->arg, s))
		ft_strmore(&d->arg, s);
	/*else if (s[0] != '\n' && s[0] != ' ')
	{
		ft_error(4);
		return (-1);
	}*/
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
	while (ret && (s[0] < '0' || s[0] > '9'))
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
	int		x;
	char	*s;

	fd = open(av[1], O_RDONLY);
	file = NULL;
	ret = get_next_line(fd, &file);
	while (ret && (file[0] < '0' || file[0] > '9'))
	{
		ft_managed_map(file, d);
		ft_free_str(&file);
		ret = get_next_line(fd, &file);
	}
	s = NULL;
	s = ft_transfert_map(d, fd, file);
	d->filemap = ft_split(s, '\n');
	//if (ft_strdif(file, '1', '\n', ' '))
	//	ft_error(1);
	free(s);
	return (fd);
}

void	ft_init_struct(t_mlx *d, char **av)
{
	d->arg = malloc(1);
	*d->arg = 0;
	d->error = 0;
	ft_managed_file(d, av);
	d->mlx_ptr = mlx_init();
	d->win = mlx_new_window(d->mlx_ptr, d->width, d->height, "CUB3D");
	d->map = NULL;
	ft_managed_textures(av, d);
	d->save = 0;
}
