/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:43:09 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/30 14:43:11 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	rotate_x(t_point zes, int deg_x)
{
	double	ax;
	t_point	res;

	ax = deg_x * PI / 180;
	res.x = zes.x;
	res.y = zes.y * cos(ax) + zes.z * sin(ax);
	res.z = -zes.y * sin(ax) + zes.z * cos(ax);
	res.color = zes.color;
	return (res);
}

static t_point	rotate_y(t_point zes, int deg_y)
{
	double	ay;
	t_point	res;

	ay = deg_y * PI / 180;
	res.x = zes.x * cos(ay) + zes.z * sin(ay);
	res.y = zes.y;
	res.z = -zes.x * sin(ay) + zes.z * cos(ay);
	res.color = zes.color;
	return (res);
}

static t_point	rotate_z(t_point zes, int deg_z)
{
	double	az;
	t_point	res;

	az = deg_z * PI / 180;
	res.x = zes.x * cos(az) - zes.y * sin(az);
	res.y = zes.x * sin(az) + zes.y * cos(az);
	res.z = zes.z;
	res.color = zes.color;
	return (res);
}

void			rotate(t_map **map, t_point **base)
{
	unsigned int	i;
	unsigned int	j;
	t_point			res;

	j = -1;
	while (++j < (*map)->size_y)
	{
		i = -1;
		while (++i < (*map)->size_x)
		{
			res = rotate_x(base[j][i], (*map)->deg_x);
			res = rotate_y(res, (*map)->deg_y);
			res = rotate_z(res, (*map)->deg_z);
			(*map)->points[j][i] = res;
		}
	}
}

void			rotate_map(t_map **map, t_mlx *all, int i)
{
	if (i == 1)
		(*map)->deg_x += L;
	else if (i == 2)
		(*map)->deg_x -= L;
	else if (i == 3)
		(*map)->deg_y += L;
	else if (i == 4)
		(*map)->deg_y -= L;
	else if (i == 5)
		(*map)->deg_z += L;
	else
		(*map)->deg_z -= L;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}
