/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 18:27:27 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/29 18:27:29 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_lines(t_line line, t_map **map, t_mlx *all)
{
	if (abs_double(line.x1 - line.x0) > abs_double(line.y1 - line.y0))
	{
		while (line.x <= line.x1)
		{
			line.y = line.y0 + (line.x - line.x0) * (line.y1 - line.y0)
	/ (line.x1 - line.x0);
			mlx_pixel_put(all->mlx, all->win, line.x +
	(int)(*map)->center_x, line.y + (int)(*map)->center_y, line.color);
			line.x += 1;
		}
	}
	else
	{
		line.d = line.y1 > line.y0 ? 1 : -1;
		while (line.d * line.y <= line.d * line.y1)
		{
			line.x = line.x0 + (line.y - line.y0) * (line.x1 - line.x0)
	/ (line.y1 - line.y0);
			mlx_pixel_put(all->mlx, all->win, line.x +
	(int)(*map)->center_x, line.y + (int)(*map)->center_y, line.color);
			line.y += line.d;
		}
	}
}

static t_line	fill_line_i(t_map **map, t_mlx *all,
	unsigned int i, unsigned int j)
{
	t_line line;

	if (all->base[j][i].z > all->base[j][i - 1].z)
		line.color = (*map)->points[j][i].color;
	else
		line.color = (*map)->points[j][i - 1].color;
	if ((*map)->points[j][i].x > (*map)->points[j][i - 1].x)
	{
		line.x0 = (*map)->points[j][i - 1].x;
		line.x1 = (*map)->points[j][i].x;
		line.y0 = (*map)->points[j][i - 1].y;
		line.y1 = (*map)->points[j][i].y;
	}
	else
	{
		line.x0 = (*map)->points[j][i].x;
		line.x1 = (*map)->points[j][i - 1].x;
		line.y0 = (*map)->points[j][i].y;
		line.y1 = (*map)->points[j][i - 1].y;
	}
	line.x = line.x0;
	line.y = line.y0;
	return (line);
}

static t_line	fill_line_j(t_map **map, t_mlx *all,
	unsigned int i, unsigned int j)
{
	t_line line;

	if (all->base[j][i].z > all->base[j - 1][i].z)
		line.color = (*map)->points[j][i].color;
	else
		line.color = (*map)->points[j - 1][i].color;
	if ((*map)->points[j][i].x > (*map)->points[j - 1][i].x)
	{
		line.x0 = (*map)->points[j - 1][i].x;
		line.x1 = (*map)->points[j][i].x;
		line.y0 = (*map)->points[j - 1][i].y;
		line.y1 = (*map)->points[j][i].y;
	}
	else
	{
		line.x0 = (*map)->points[j][i].x;
		line.x1 = (*map)->points[j - 1][i].x;
		line.y0 = (*map)->points[j][i].y;
		line.y1 = (*map)->points[j - 1][i].y;
	}
	line.x = line.x0;
	line.y = line.y0;
	return (line);
}

void			draw_map(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;
	t_line			line;

	mlx_clear_window(all->mlx, all->win);
	win_text(all);
	j = -1;
	while (++j < (*map)->size_y && !(i = 0))
		while (++i < (*map)->size_x)
		{
			line = fill_line_i(map, all, i, j);
			draw_lines(line, map, all);
		}
	j = 0;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			line = fill_line_j(map, all, i, j);
			draw_lines(line, map, all);
		}
	}
}

void			reset_map(t_map **map, t_mlx *all)
{
	unsigned int	i;
	unsigned int	j;

	(*map)->center_x = WIN_X / 2;
	(*map)->center_y = WIN_Y / 2;
	j = -1;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			all->base[j][i].x = all->base[j][i].x / (*map)->scale;
			all->base[j][i].y = all->base[j][i].y / (*map)->scale;
			all->base[j][i].z = all->base[j][i].z / (*map)->scale;
		}
	}
	(*map)->deg_x = 0;
	(*map)->deg_y = 0;
	(*map)->deg_z = 0;
	(*map)->scale = 1;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}
