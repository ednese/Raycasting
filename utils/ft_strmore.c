/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:59:37 by esende            #+#    #+#             */
/*   Updated: 2020/06/14 16:55:14 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int        ft_len_arg(char *s)
{
    int len;

    len = 0;
    while(s[len] && s[len] != ' ')
        len++;
    return (len);
}

char    *ft_strmore(char **s, char *c)
{
    char    *res;
    size_t    index;
    size_t    len;
    size_t    arg;

    arg = ft_len_arg(c);
    if (!(res = malloc(sizeof(char *) * (ft_strlen(*s) + arg + 2))))
        return (0);
    len = 0;
    while ((*s)[len])
    {
        res[len] = (*s)[len];
        len++;
    }
    index = 0;
    while (c[index] && index < arg)
    {
        res[len + index] = c[index];
        index++;
    }
    res[len + index++] = '\n';
    res[len + index] = 0;
    free(*s);
    *s = res;
    return (res);
}