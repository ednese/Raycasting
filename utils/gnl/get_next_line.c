/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 14:25:10 by esende            #+#    #+#             */
/*   Updated: 2020/06/27 21:08:10 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line_init(char **line, char **memory, char **buffer)
{
	if (!line || BUFFER_SIZE <= 0)
		return (1);
	if (!*memory)
	{
		if (!(*memory = malloc(sizeof(char *))))
			return (1);
		**memory = 0;
	}
	if (!(*buffer = malloc(BUFFER_SIZE + 1)))
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*memory[256];
	char		*buffer;
	int			ret;

	if (get_next_line_init(line, &memory[fd], &buffer))
		return (-1);
	ret = 1;
	while (!ft_strcchr(memory[fd], '\n')
		&& (ret = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[ret] = 0;
		ft_stradd(&memory[fd], buffer);
	}
	*line = ft_firstchr(memory[fd], '\n');
	ft_chrmove(&memory[fd], '\n');
	free(buffer);
	if (ret <= 0)
	{
		free(memory[fd]);
		memory[fd] = 0;
		return (ret);
	}
	return (1);
}
