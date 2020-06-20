/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:18:53 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 13:52:16 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "./libraries/libft/libft.h"
# include "utils/gnl/get_next_line.h"

# define XK_MISCELLANY
# define XK_LATIN1
# include <X11/keysymdef.h>

# define FR +2
# define UP			122
# define DOWN		115
# define LEFT		113
# define RIGHT		100
# define CAMLEFT	XK_Left
# define CAMRIGHT	XK_Right
# define EXIT		XK_Escape
# define GRAY		0x808080
# define WHITE		0xffffff
# define BLACK		0x000001
# define RED		0xFF0000
# define BROWN		0x800000
# define YELLOW		0xFFFF00
# define LIME		0x00FF00
# define GREEN		0x008000
# define BLUE		0x0000FF
# define PINK		0xFF00FF
# define PURPLE		0x800080
# define GROUND		0xF08080
# define SKY		0x00FFFF

typedef struct		s_double
{
	double		x;
	double		y;
}					t_double;

typedef struct		s_dble
{
	double		*x;
	double		*y;
}					t_dble;

typedef struct		s_int
{
	int			x;
	int			y;
}					t_int;

typedef struct		s_compass
{
	char		*north;
	char		*south;
	char		*east;
	char		*west;
}					t_compass;

typedef struct		s_menu
{
	int			play;
	int			quit;
}					t_menu;

typedef struct		s_tex
{
	char		*path;
	void		*tex;
	int			*ptr;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
	int			endian;
	t_int		start;
	t_int		end;
}					t_tex;

typedef struct		s_arg
{
	int			r;
	int			no;
	int			so;
	int			we;
	int			ea;
	int			s;
	int			f;
	int			c;
}					t_arg;

typedef struct		s_spt
{
	int			vmovescreen;
	int			spritescreen_x;
	int			spriteheight;
	int			spritewidth;
}					t_spt;

typedef struct		s_pos
{
	t_double	pos;
	t_double	dir;
	t_double	plane;
	t_double	camera;
	t_double	raydir;
	t_double	sidedist;
	t_double	deltadist;
	t_int		map;
	t_int		step;
	double		walldist;
	int			lineheight;
	int			side;
}					t_pos;

typedef struct		s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_mlx
{
	double		*zbuffer;
	void		*mlx_ptr;
	void		*win;
	char		*map;
	char		*arg;
	char		**filemap;
	char		**argv;
	int			width;
	int			height;
	int			floor;
	int			sky;
	int			save;
	int			ac;
	int			error;
	int			index;
	int			numsprites;
	t_img		img;
	t_pos		p;
	t_spt		s;
	t_tex		t[5];
}					t_mlx;

void				ft_init_struct(t_mlx *d, char **av);
int					ft_resolution(char *s, t_mlx *d);
char				*ft_itoahex(unsigned int n);
char				*ft_itoahex_color(long int n);
int					ft_atoi_base(char *str, char *base);
int					ft_rgb_to_hex(char *s);
void				ft_free_str(char **str);
char				*ft_transfert_map(int fd, char *line);
void				ft_error(int e);
int					ft_verify_line(char *s);
char				*ft_strmore(char **s, char *c);
int					ft_put_pixels(t_mlx *d, int n);
int					ft_pos(t_pos *p, char **map, t_mlx *d);
double				ft_abs(double n);
void				ft_rotate(t_mlx *d, double v, int n);
int					key(int key, t_mlx *d);
int					ft_exit(t_mlx *d);
void				ft_fill_walls(char **map, t_mlx *d);
int					ft_verline(t_mlx *d, t_int size, int x, int color);
int					ft_verline_tex(t_mlx *d, t_int size, int x, int *color);
int					*textures_walls(t_mlx *d, t_pos *p, t_int draw);
void				textures_init(t_mlx *d, char *s);
void				fill_sprites(char **map, t_mlx *d);
t_dble				srch_sprites(char **map, int n);
int					*sort_sprites(int n, double *tab);
int					ft_verline_sprite(t_mlx *d, t_int size, int x, int *color);
void				init_ray(t_pos *p, t_mlx *d, int x);
void				header_file(t_mlx *d, char *filename);
void				init_arg(t_mlx *d);
int					check_map(char **map);
int					ft_file_x(char **file, int ret, int d, int f);

#endif
