/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 20:13:18 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 12:38:57 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strcchr(char *src, int c);
char	*ft_stradd(char **dst, char *str);
char	*ft_firstchr(char *src, int c);
char	*ft_chrmove(char **dst, int c);
int		get_next_line(int fd, char **line);

#endif
