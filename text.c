/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 16:41:53 by ovirchen          #+#    #+#             */
/*   Updated: 2018/02/22 16:41:54 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	win_text(t_mlx *all)
{
	mlx_string_put(all->mlx, all->win, 50, 50, 0x00fff2, "HOW TO USE");
	mlx_string_put(all->mlx, all->win, 50, 80, 0x00c8ff, "Move: A W D S");
	mlx_string_put(all->mlx, all->win, 50, 110, 0x008cff, "Rotate X: 1 - 2");
	mlx_string_put(all->mlx, all->win, 50, 130, 0x008cff, "Rotate Y: 3 - 4");
	mlx_string_put(all->mlx, all->win, 50, 150, 0x008cff, "Rotate X: 5 - 6");
	mlx_string_put(all->mlx, all->win, 50, 180, 0x0048ff, "Base map: Enter");
	mlx_string_put(all->mlx, all->win, 50, 200, 0x0048ff, "Front view: 7");
	mlx_string_put(all->mlx, all->win, 50, 220, 0x0048ff, "Right view: 8");
	mlx_string_put(all->mlx, all->win, 50, 240, 0x0048ff, "Top view: 9");
	mlx_string_put(all->mlx, all->win, 50, 260, 0x0048ff, "Iso view: Space");
	mlx_string_put(all->mlx, all->win, 50, 290, 0xff002b, "Exit: Esc");
}

int		ft_error(void)
{
	write(1, "error\n", 6);
	return (1);
}

int		ft_usage(void)
{
	write(1, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
	return (1);
}

int		exit_x(t_mlx *all)
{
	free_all(all);
	exit(1);
	return (0);
}

void	free_all(t_mlx *all)
{
	unsigned int j;

	j = -1;
	while (++j < all->map->size_y)
	{
		free(all->base[j]);
		free(all->map->points[j]);
	}
	free(all->base);
	free(all->map->points);
	free(all->map);
}
