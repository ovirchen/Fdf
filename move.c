/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:28:20 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/30 12:28:23 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	find_max_min(t_map **map)
{
	unsigned int	i;
	unsigned int	j;

	j = -1;
	(*map)->max_x = (*map)->points[0][0].x;
	(*map)->min_x = (*map)->points[0][0].x;
	(*map)->max_y = (*map)->points[0][0].y;
	(*map)->min_y = (*map)->points[0][0].y;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			if ((*map)->points[0][0].x > (*map)->max_x)
				(*map)->max_x = (*map)->points[0][0].x;
			else if ((*map)->points[0][0].x < (*map)->min_x)
				(*map)->min_x = (*map)->points[0][0].x;
			if ((*map)->points[0][0].y > (*map)->max_y)
				(*map)->max_y = (*map)->points[0][0].y;
			else if ((*map)->points[0][0].y < (*map)->min_y)
				(*map)->min_y = (*map)->points[0][0].y;
		}
	}
}

void	move_map_left(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	if (((*map)->min_x + (*map)->center_x - MV) >= 0)
	{
		(*map)->center_x -= MV;
		(*map)->min_x -= MV;
		(*map)->max_x -= MV;
		j = -1;
		while (++j < (*map)->size_y)
		{
			i = -1;
			while (++i < (*map)->size_x)
				(*map)->points[j][i].x -= MV;
		}
		draw_map(map, all);
	}
}

void	move_map_right(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	if (((*map)->max_x + (*map)->center_x + MV) <= WIN_X)
	{
		(*map)->center_x += MV;
		(*map)->max_x += MV;
		(*map)->min_x += MV;
		j = -1;
		while (++j < (*map)->size_y)
		{
			i = -1;
			while (++i < (*map)->size_x)
				(*map)->points[j][i].x += MV;
		}
		draw_map(map, all);
	}
}

void	move_map_up(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	if ((*map)->min_y + (*map)->center_y - MV >= 0)
	{
		(*map)->center_y -= MV;
		(*map)->min_y -= MV;
		(*map)->max_y -= MV;
		j = -1;
		while (++j < (*map)->size_y)
		{
			i = -1;
			while (++i < (*map)->size_x)
				(*map)->points[j][i].y -= MV;
		}
		draw_map(map, all);
	}
}

void	move_map_down(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	if ((*map)->max_y + (*map)->center_y + MV <= WIN_Y)
	{
		(*map)->center_y += MV;
		(*map)->min_y += MV;
		(*map)->max_y += MV;
		j = -1;
		while (++j < (*map)->size_y)
		{
			i = -1;
			while (++i < (*map)->size_x)
				(*map)->points[j][i].y += MV;
		}
		draw_map(map, all);
	}
}
