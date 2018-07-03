/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ovirchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:43:16 by ovirchen          #+#    #+#             */
/*   Updated: 2018/01/29 12:43:18 by ovirchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		size_x_map(int *fd, char *file, t_map **map)
{
	char			*str;
	char			**split;
	int				gnl;
	unsigned int	i;

	if ((*fd = open(file, O_RDONLY)) == -1)
		return (0);
	(*map)->size_y = 0;
	(*map)->size_x = 0;
	while ((gnl = get_next_line(*fd, &str)))
	{
		if (gnl == -1 || (split = ft_strsplit(str, ' ')) == NULL)
			return (0);
		free(str);
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		if ((*map)->size_x != 0 && (*map)->size_x != i)
			return (0);
		(*map)->size_x = i;
		(*map)->size_y++;
	}
	close(*fd);
	return (1);
}

static int		open_file(char *file, t_mlx *all)
{
	int	fd;

	all->map = (t_map*)malloc(sizeof(t_map));
	if (all->map == NULL || size_x_map(&fd, file, &(all->map)) == 0
		|| ((fd = open(file, O_RDONLY)) == -1))
	{
		free(all->map);
		return (-1);
	}
	all->map->center_x = WIN_X / 2;
	all->map->center_y = WIN_Y / 2;
	if ((all->map->points = (t_point**)malloc(sizeof(t_point*) *
		(all->map->size_y + 1))) == NULL)
	{
		free(all->map);
		return (-1);
	}
	if ((all->base = (t_point**)malloc(sizeof(t_point*) * (all->map->size_y
		+ 1))) == NULL)
	{
		free(all->map);
		free(all->map->points);
		return (-1);
	}
	return (fd);
}

static int		gnl(int fd, t_mlx *all, char ***split00, unsigned int j)
{
	int		gnl;
	char	**split;
	char	*str;

	if ((gnl = get_next_line(fd, &str)) == -1)
		return (-1);
	if (gnl == 0)
		return (0);
	if ((split = ft_strsplit(str, ' ')) == NULL)
	{
		free(all->map);
		return (-1);
	}
	free(str);
	*split00 = split;
	all->map->points[j] = (t_point*)malloc(sizeof(t_point) *
			(all->map->size_x + 1));
	all->base[j] = (t_point*)malloc(sizeof(t_point) *
			(all->map->size_x + 1));
	return (1);
}

static void		take_color(t_mlx *all, unsigned int i, unsigned int j,
	char **split)
{
	char			*tmp;

	all->base[j][i].z = ft_atoi(split[i]);
	if ((tmp = strchr(split[i], ',')))
		all->base[j][i].color = atoi_hex(++tmp);
	else if (all->base[j][i].z == 0)
		all->base[j][i].color = 0xFFFFFF;
	else
		all->base[j][i].color = 0xff002b;
}

int				check_map(char *file, t_mlx *all)
{
	int				fd;
	char			**split;
	unsigned int	i;
	unsigned int	j;

	if ((fd = open_file(file, all)) == -1)
		return (0);
	j = -1;
	while (gnl(fd, all, &split, ++j) > 0)
	{
		i = -1;
		while (split[++i] && i < all->map->size_x)
			take_color(all, i, j, split);
		i = 0;
		while (split[i])
			free(split[i++]);
		free(split);
		if (i != all->map->size_x)
		{
			free(all->map);
			return (0);
		}
	}
	close(fd);
	return (all->map->scale = 1);
}
