/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:45:12 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/21 18:45:51 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <math.h>

t_bres		*ft_new_bres(int x1, int y1, int x2, int y2)
{
	t_bres	*new;

	new = (t_bres *)ft_memalloc(sizeof(t_bres));
	new->x1 = x1;
	new->y1 = y1;
	new->x2 = x2;
	new->y2 = y2;
	new->dx = x1 - x2;
	new->dy = y1 - y2;
	new->x_inc = (new->dx < 0) ? 1 : -1;
	new->y_inc = (new->dy < 0) ? 1 : -1;
	new->i = 1;
	new->dx = fabs(new->dx);
	new->dy = fabs(new->dy);
	new->error = (new->dx >= new->dy) ? new->dx / 2 : new->dy / 2;
	return (new);
}

void		ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color)
{
	t_bres *bres;

	bres = ft_new_bres(mlx_all->win->x_ligne, mlx_all->win->y_ligne, x, y);
	while ((bres->i <= bres->dx && bres->dx >= bres->dy)
			|| (bres->i <= bres->dy && bres->dx <= bres->dy))
	{
		bres->i++;
		bres->error += (bres->dx >= bres->dy) ? bres->dy : bres->dx;
		if (bres->dx >= bres->dy)
			bres->x1 += bres->x_inc;
		else
			bres->y1 += bres->y_inc;
		if ((bres->error >= bres->dx && bres->dx >= bres->dy)
				|| (bres->error >= bres->dy && bres->dx <= bres->dy))
		{
			bres->error -= (bres->dx >= bres->dy) ? bres->dx : bres->dy;
			if (bres->dx >= bres->dy)
				bres->y1 += bres->y_inc;
			else
				bres->x1 += bres->x_inc;
		}
		mlx_pixel_put(mlx_all->mlx_ptr,
				mlx_all->win->win_ptr, bres->x1, bres->y1, color);
	}
}

int		ft_draw_map(t_mlx *mlx_all)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	while (i < mlx_all->map->height)
	{
		j = 0;
		while (j < mlx_all->map->len)
		{
			mlx_all->win->x_ligne = 
				((i * mlx_all->cam->di_x) - (j * mlx_all->cam->di_y))
				* -cos(0.523599)
				+ (1920 / 2 - mlx_all->map->len / 2)
				+ mlx_all->cam->left_right;
			mlx_all->win->y_ligne = -(mlx_all->map->map[i][j] *
				   	mlx_all->cam->di_z)
				+ ((i * mlx_all->cam->di_x) + (j * mlx_all->cam->di_y))
				* sin(0.523599)
				+ (1080 / 2 - mlx_all->map->height / 2)
				+ mlx_all->cam->up_down;
			if (j + 1 < mlx_all->map->len)
			{
				x =
					((i * mlx_all->cam->di_x) - ((j + 1)) * mlx_all->cam->di_y)
					* -cos(0.523599)
					+ (1920 / 2 - mlx_all->map->len / 2)
					+ mlx_all->cam->left_right;
				y = -(mlx_all->map->map[i][j + 1] * mlx_all->cam->di_z)
					+ ((i * mlx_all->cam->di_x)
					+ ((j + 1)) * mlx_all->cam->di_y)
					* sin(0.523599)
					+ (1080 / 2 - mlx_all->map->height / 2)
					+ mlx_all->cam->up_down;
				ft_draw_ligne(mlx_all, x, y, 0xFFFF00);
			}
			if (i + 1 < mlx_all->map->height)
			{

				ft_draw_ligne(mlx_all,
					(((i + 1) * mlx_all->cam->di_x) - (j * mlx_all->cam->di_y))
				   	* -cos(0.523599) + (1920 / 2 - mlx_all->map->len / 2)
					+ mlx_all->cam->left_right ,-(mlx_all->map->map[i + 1][j]
					* mlx_all->cam->di_z) + (((i + 1) * mlx_all->cam->di_x)
					+ (j * mlx_all->cam->di_y)) * sin(0.523599)
					+ (1080 / 2 - mlx_all->map->height / 2)
					+ mlx_all->cam->up_down ,0xFFFF00);
			}
			j++;
		}
		i++;
	}
	return (0);
}
