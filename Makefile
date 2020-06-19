# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: esende <esende@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/28 16:30:48 by esende            #+#    #+#              #
#    Updated: 2020/06/19 20:35:52 by esende           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX		=	-lmlx -lX11 -lXext -lbsd -lm
#CFLAGS	=	-Wall -Wextra -Werror
NAME	=	cub3D
SRCS	=	cub3d.c ./utils/gnl/get_next_line.c ./utils/gnl/get_next_line_utils.c ./engine/ft_init.c ./utils/ft_resolution.c ./utils/ft_itoahex.c ./utils/ft_itoa_color.c ./utils/ft_rgb_to_hex.c ./utils/ft_atoi_base.c ./utils/ft_free.c ./utils/ft_transfert_map.c ./utils/ft_error.c ./utils/ft_verify_line.c ./utils/ft_strmore.c ./engine/ft_put_pixels.c ./engine/ft_pos_map.c ./engine/ft_rotate.c ./utils/ft_abs.c ./event/key.c ./event/exit.c ./engine/verline.c ./engine/verline_tex.c ./engine/walls.c ./event/mouse.c ./engine/textures_init.c ./engine/textures_walls.c ./engine/menu.c ./engine/fill_sprites.c ./engine/srch_sprites.c ./engine/sort_sprites.c ./engine/verline_sprite.c ./engine/init_ray.c ./engine/screenshot.c ./engine/file_arg.c ./engine/check_map.c ./engine/file_x.c

OBJSRCS	=	$(SRCS:.c=.o)

$(NAME) : $(OBJSRCS)
	@echo "\033[0;33m[Libft compilation...]\033[0;32m"
	@$(MAKE) -C ./libraries/libft
	@echo "\033[0;33m[Cub3D compilation...]\033[0;32m"
	@gcc $(OBJSRCS) -I./includes $(CFLAGS) $(MLX) ./libraries/libft/libft.a -o $(NAME)
	@echo "\033[0;32m[Done]\n\033[1;34m[Now you can run the program !]\033[1;34m"

all : $(NAME)

clean :
	@echo "\033[0;31m[Removing ...]"
	rm -rf $(OBJSRCS)
	$(MAKE) clean -C ./libraries/libft

fclean : clean
	$(MAKE) fclean -C ./libraries/libft
	rm -rf $(NAME)
	rm -rf *.bmp

re : fclean all
