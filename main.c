/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:33:52 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/16 17:33:56 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	count_space(t_map *map)
{
	if ((WIN_X - 400) / (map->size_x * 1.0) > (WIN_Y - 300) /
		(map->size_y * 1.0))
		return ((WIN_Y - 300) / (map->size_y * 1.0));
	else
		return ((WIN_X - 400) / (map->size_x * 1.0));
}

static t_point	**base_points(t_point **base, t_map *map)
{
	unsigned int	i;
	unsigned int	j;
	double			space;
	double			x;
	double			y;

	space = count_space(map);
	if (map->size_y % 2)
		y = map->center_y - ((map->size_y / 2) * space + space / 2);
	else
		y = map->center_y - (map->size_y / 2) * space;
	j = -1;
	while (++j < map->size_y)
	{
		x = map->center_x - (map->size_x / 2) * space;
		i = -1;
		while (++i < map->size_x)
		{
			base[j][i].x = x - map->center_x;
			base[j][i].y = y - map->center_y;
			x += space;
		}
		y += space;
	}
	return (base);
}

int				main(int ac, char **av)
{
	t_mlx	all;

	if (ac != 2)
		return (ft_usage());
	if (check_map(av[1], &all) == 0)
		return (ft_error());
	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 1450, 920, "fdf");
	all.base = base_points(all.base, all.map);
	reset_map(&(all.map), &all);
	mlx_hook(all.win, 2, 5, my_key_funct, &all);
	mlx_hook(all.win, 17, 1L << 17, exit_x, &all);
	mlx_loop(all.mlx);
	free_all(&all);
	sleep(5);
	return (0);
}
