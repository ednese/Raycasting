/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esende <esende@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 13:57:11 by esende            #+#    #+#             */
/*   Updated: 2020/05/16 13:57:17 by esende           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		fill_tab(double *tab, double *maxstock, int n, int k)
{
	int i;
	double    stock;
	int    newtab;
	
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

int		*sort_sprites(int n, double *tab)
{
	int i;
	int k;
	double    stock;
	double  maxstock;
	int    *newtab;

	newtab = malloc(sizeof(int *)  * n);
	i = 0;
	k = 0;
	maxstock = 0;
	while (k < n)
	{
	    newtab[k] = fill_tab(tab, &maxstock, n, k);
	    stock = 0;
		k++;
	}
	return (newtab);
}
