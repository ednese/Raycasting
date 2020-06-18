/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:10:36 by esende            #+#    #+#             */
/*   Updated: 2020/05/05 03:23:35 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		managed_mouse(int key, int w, int h, t_mlx *d)
{
  static int det;
  static int x;
  static int r;

  if (!det)
    det = 0;
  if (!x)
    x = 0;
  if (!r)
    r = 0;
  if (!x && !det && w >= 534 && w <= 959 && h >= 470 && h<= 573)
  {
      //mlx_clear_window(d->mlx_ptr, d->win);
      //mlx_destroy_window(d->mlx_ptr, d->win);
      //ft_init_struct(&d, d->argv);
      ft_put_pixels(d, 1, 1);
      det++;
  }
  else if (!r && x && !det && w >= 534 && w <= 959 && h >= 470 && h<= 573)
  {
      ft_put_pixels(d, 1, 3);
      r++;
  }
  else if (r && x && !det && w >= 534 && w <= 959 && h >= 470 && h<= 573)
  {
      r = 0;
      det = 0;
      x = 0;
      d->width = 2560;
      d->height = 1440;
      ft_put_pixels(d, 1, 0);
  }
  else if (r && x && !det && w >= 534 && w <= 959 && h >= 696 && h<= 818)
  {
      r = 0;
      det = 0;
      x = 0;
      d->width = 1920;
      d->height = 1080;
      ft_put_pixels(d, 1, 0);
  }
  else if (r && x && !det && w >= 534 && w <= 959 && h >= 961 && h<= 1066)
  {
      r = 0;
      det = 0;
      x = 0;
      d->width = 1280;
      d->height = 720;
      ft_put_pixels(d, 1, 0);
  }
  else if (!det && w >= 534 && w <= 959 && h >= 696 && h<= 818)
  {
    x = 1;
    ft_put_pixels(d, 1, 2);
  }
  else if (!r && !x && !det && w >= 534 && w <= 959 && h >= 961 && h<= 1066)
      ft_exit(d);
  else
  {
    ft_putstr("x =");
	 ft_putnbr(w);
    ft_putchar('\n');
    ft_putstr("y =");
    ft_putnbr(h);
    ft_putchar('\n');
  }
	return (0);
}
