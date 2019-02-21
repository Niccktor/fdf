/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:54:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/21 20:14:11 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>


static void		ft_iso_right(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	mlx_all->win->x_ligne =
		((i * mlx_all->cam->di_x) - (j * mlx_all->cam->di_y))
		* -cos(mlx_all->cam->angle)
		+ (mlx_all->win->width / 2 - mlx_all->map->len / 2)
		+ mlx_all->cam->left_right;
   	mlx_all->win->y_ligne = -(mlx_all->map->map[i][j]
		* mlx_all->cam->di_z)
		+ ((i * mlx_all->cam->di_x) + (j * mlx_all->cam->di_y))
		* sin(mlx_all->cam->angle)
		+ (mlx_all->win->height / 2 - mlx_all->map->height / 2)
		+ mlx_all->cam->up_down;
	if (j + 1 < mlx_all->map->len)
	{
		x =((i * mlx_all->cam->di_x) - (j + 1) * mlx_all->cam->di_y)
			* -cos(mlx_all->cam->angle)
			+ (mlx_all->win->width / 2 - mlx_all->map->len / 2)
			+ mlx_all->cam->left_right;
		y = -(mlx_all->map->map[i][j + 1] * mlx_all->cam->di_z)
			+ ((i * mlx_all->cam->di_x)
			+ ((j + 1)) * mlx_all->cam->di_y)
			* sin(mlx_all->cam->angle)
			+ (mlx_all->win->height / 2 - mlx_all->map->height / 2)
			+ mlx_all->cam->up_down;
		ft_draw_ligne(mlx_all, x, y, 0xFF0000);
	}
}

static void		ft_iso_down(t_mlx *mlx_all, int i, int j)
{
	ft_draw_ligne(mlx_all,
			(((i + 1) * mlx_all->cam->di_x) - (j * mlx_all->cam->di_y))
			* -cos(mlx_all->cam->angle) + (mlx_all->win->width / 2 - mlx_all->map->len / 2)
			+ mlx_all->cam->left_right ,-(mlx_all->map->map[i + 1][j]
			* mlx_all->cam->di_z) + (((i + 1) * mlx_all->cam->di_x)
			+ (j * mlx_all->cam->di_y)) * sin(mlx_all->cam->angle)
			+ (mlx_all->win->height / 2 - mlx_all->map->height / 2)
			+ mlx_all->cam->up_down ,0xFF0000);
}

void			ft_iso(t_mlx *mlx_all)
{
	int i;
	int j;

	i = 0;
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			ft_iso_right(mlx_all, i, j);
			if (i < mlx_all->map->height - 1)
				ft_iso_down(mlx_all, i, j);
			j++;
		}
		i++;
	}
}
