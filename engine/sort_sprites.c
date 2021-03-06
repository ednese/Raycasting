/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:57:11 by esende            #+#    #+#             */
/*   Updated: 2020/06/20 14:04:29 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	fill_tab(double *tab, double *maxstock, int n, int k)
{
	double	stock;
	int		newtab;
	int		i;

	stock = 0;
	i = 0;
	while (i < n)
	{
		if (tab[i] > stock && (tab[i] < *maxstock || !k))
		{
			stock = tab[i];
			newtab = i;
		}
		else if (k == n - 1 && tab[i] == 0)
		{
			stock = tab[i];
			newtab = i;
		}
		i++;
	}
	*maxstock = stock;
	return (newtab);
}

int	*sort_sprites(int n, double *tab)
{
	double	maxstock;
	int		*newtab;
	int		k;

	k = 0;
	newtab = malloc(sizeof(int *) * n);
	maxstock = 0;
	while (k < n)
	{
		newtab[k] = fill_tab(tab, &maxstock, n, k);
		k++;
	}
	return (newtab);
}
