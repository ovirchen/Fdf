/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:50:02 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/16 16:50:03 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <math.h>

# define WIN_X 1450
# define WIN_Y 920
# define PI 3.141592
# define MV 5
# define L 2

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	unsigned int	color;
}				t_point;

typedef struct	s_line
{
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x0;
	double			y0;
	double			d;
	unsigned int	color;
}				t_line;

typedef struct	s_map
{
	unsigned int	size_x;
	unsigned int	size_y;
	int				deg_x;
	int				deg_y;
	int				deg_z;
	double			center_x;
	double			center_y;
	double			scale;
	double			max_x;
	double			max_y;
	double			min_x;
	double			min_y;
	t_point			**points;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	t_point	**base;
	t_map	*map;
}				t_mlx;

int				ft_error(void);
int				ft_usage(void);
int				exit_x(t_mlx *all);

int				check_map(char *file, t_mlx *all);
unsigned int	atoi_hex(char *str);
t_map			*copy_map(t_map	*tmap);
int				my_key_funct(int keycode, t_mlx *all);
void			reset_map(t_map **map, t_mlx *all);
void			find_max_min(t_map **map);
void			free_all(t_mlx *all);

void			draw_map(t_map **map, t_mlx *all);

void			move_map_left(t_map **map, t_mlx *all);
void			move_map_right(t_map **map, t_mlx *all);
void			move_map_up(t_map **map, t_mlx *all);
void			move_map_down(t_map **map, t_mlx *all);

void			par_x_map(t_map **map, t_mlx *all);
void			par_y_map(t_map **map, t_mlx *all);
void			par_z_map(t_map **map, t_mlx *all);
void			iso_map(t_map **map, t_mlx *all);
void			rotate(t_map **map, t_point **base);
void			rotate_map(t_map **map, t_mlx *all, int i);

void			zoom_plus(t_map **map, t_mlx *all);
void			zoom_minus(t_map **map, t_mlx *all);

void			win_text(t_mlx *all);

#endif
