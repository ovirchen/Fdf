/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 17:38:48 by ovirchen          #+#    #+#             */
/*   Updated: 2018/02/24 17:38:49 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_plus(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	(*map)->scale *= 1.01;
	j = -1;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			all->base[j][i].x *= 1.01;
			all->base[j][i].y *= 1.01;
			all->base[j][i].z *= 1.01;
		}
	}
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}

void	zoom_minus(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	(*map)->scale *= 0.99;
	j = -1;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			all->base[j][i].x *= 0.99;
			all->base[j][i].y *= 0.99;
			all->base[j][i].z *= 0.99;
		}
	}
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}
