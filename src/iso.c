/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:54:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/20 23:09:40 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void		ft_iso_right(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	mlx_all->win->x_ligne = ((j - i)
		+ (mlx_all->map->height / 2 - mlx_all->map->len / 2))
		* mlx_all->cam->di_x + (mlx_all->win->width / 2)
		+ mlx_all->cam->left_right;
	mlx_all->win->x_ligne = ((j + i)
		- (mlx_all->map->height / 2 + mlx_all->map->len / 2))
		* mlx_all->cam->di_y + (mlx_all->win->height / 2)
		- mlx_all->map->map[i][j] * mlx_all->cam->di_z
		+ mlx_all->cam->up_down;
	if (j < mlx_all->map->len - 1)
	{
		x = (((j + 1) - i)
			+ (mlx_all->map->height / 2 - mlx_all->map->len / 2))
			* mlx_all->cam->di_x + mlx_all->win->width / 2
			+ mlx_all->cam->left_right;
		y = (((j + 1) + i)
			- (mlx_all->map->height / 2 + mlx_all->map->len / 2))
			* mlx_all->cam->di_y + mlx_all->win->height / 2
			- mlx_all->map->map[i][j + 1] * mlx_all->cam->di_z
			+ mlx_all->cam->up_down;
	ft_putstr("---------------\nx = ");
	ft_putnbr(x);
	ft_putstr(" y = ");
	ft_putnbr(y);
	ft_putstr("\n---------------");
		ft_draw_ligne(mlx_all, x, y, 0xFFFFFF);
	}
}

static void		ft_iso_down(t_mlx *mlx_all, int i, int j)
{
	int x;
	int y;

	x = ((j - (i + 1))
			+ (mlx_all->map->height / 2 - mlx_all->map->len / 2))
			* mlx_all->cam->di_x + mlx_all->win->width / 2
			+ mlx_all->cam->left_right;
	y = ((j + (i + 1))
			- (mlx_all->map->height / 2 + mlx_all->map->len / 2))
			* mlx_all->cam->di_y + mlx_all->win->height / 2
			- mlx_all->map->map[i + 1][j] * mlx_all->cam->di_z
			+ mlx_all->cam->up_down;

	ft_putstr("---------------\nx = ");
	ft_putnbr(x);
	ft_putstr(" y = ");
	ft_putnbr(y);
	ft_putstr("\n---------------");
	ft_draw_ligne(mlx_all, x, y, 0xFFFFFF);
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
