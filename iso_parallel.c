/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 12:51:40 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/30 12:51:41 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	atoi_hex(char *str)
{
	int				i;
	unsigned int	hex;
	unsigned int	res;

	if (str[1] == 'x' || str[1] == 'X')
		str += 2;
	i = 0;
	while (i < 6 && str[i])
		i++;
	hex = 1;
	res = 0;
	while (--i >= 0)
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = res + hex * (str[i] - 48);
		else if (str[i] >= 97 && str[i] <= 102)
			res = res + hex * (str[i] - 87);
		else if (str[i] >= 65 && str[i] <= 70)
			res = res + hex * (str[i] - 55);
		hex *= 16;
	}
	return (res);
}

void			par_x_map(t_map **map, t_mlx *all)
{
	(*map)->center_x = WIN_X / 2;
	(*map)->center_y = WIN_Y / 2;
	(*map)->deg_x = -90;
	(*map)->deg_y = 0;
	(*map)->deg_z = 0;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}

void			par_y_map(t_map **map, t_mlx *all)
{
	(*map)->center_x = WIN_X / 2;
	(*map)->center_y = WIN_Y / 2;
	(*map)->deg_x = 0;
	(*map)->deg_y = -90;
	(*map)->deg_z = 90;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}

void			par_z_map(t_map **map, t_mlx *all)
{
	(*map)->center_x = WIN_X / 2;
	(*map)->center_y = WIN_Y / 2;
	(*map)->deg_x = 0;
	(*map)->deg_y = 0;
	(*map)->deg_z = 0;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}

void			iso_map(t_map **map, t_mlx *all)
{
	(*map)->center_x = WIN_X / 2;
	(*map)->center_y = WIN_Y / 2;
	(*map)->deg_x = -60;
	(*map)->deg_y = 30;
	(*map)->deg_z = 0;
	rotate(map, all->base);
	find_max_min(map);
	draw_map(map, all);
}
