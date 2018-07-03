/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:47:52 by ovirchen          #+#    #+#             */
/*   Updated: 2018/02/22 15:47:53 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_move(int keycode, t_mlx *all)
{
	if (keycode == 0 || keycode == 123)
		move_map_left(&(all->map), all);
	else if (keycode == 2 || keycode == 124)
		move_map_right(&(all->map), all);
	else if (keycode == 13 || keycode == 126)
		move_map_up(&(all->map), all);
	else if (keycode == 1 || keycode == 125)
		move_map_down(&(all->map), all);
}

static void	key_zoom(int keycode, t_mlx *all)
{
	if (keycode == 24 || keycode == 69)
		zoom_plus(&(all->map), all);
	if (keycode == 27 || keycode == 78)
		zoom_minus(&(all->map), all);
}

static void	key_rotate(int keycode, t_mlx *all)
{
	if (keycode == 18 || keycode == 83)
		rotate_map(&(all->map), all, 1);
	else if (keycode == 19 || keycode == 84)
		rotate_map(&(all->map), all, 2);
	else if (keycode == 20 || keycode == 85)
		rotate_map(&(all->map), all, 3);
	else if (keycode == 21 || keycode == 86)
		rotate_map(&(all->map), all, 4);
	else if (keycode == 23 || keycode == 87)
		rotate_map(&(all->map), all, 5);
	else if (keycode == 22 || keycode == 88)
		rotate_map(&(all->map), all, 6);
}

int			my_key_funct(int keycode, t_mlx *all)
{
	if (keycode == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		free_all(all);
		exit(0);
	}
	else if (keycode == 36)
		reset_map(&(all->map), all);
	else if (keycode == 89 || keycode == 26)
		par_x_map(&(all->map), all);
	else if (keycode == 91 || keycode == 28)
		par_y_map(&(all->map), all);
	else if (keycode == 92 || keycode == 25)
		par_z_map(&(all->map), all);
	else if (keycode == 49)
		iso_map(&(all->map), all);
	key_move(keycode, all);
	key_rotate(keycode, all);
	key_zoom(keycode, all);
	return (0);
}
