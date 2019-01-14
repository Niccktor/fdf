/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:45:12 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 20:03:49 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color)
{
	int		dx;
	int		dy;
	int		e;

	e = mlx_all->win->x_ligne - x;
	dx = e * 2;
	dy = (mlx_all->win->y_ligne) * 2;
	while (x <= mlx_all->win->x_ligne)
	{
		mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, x, y, color);
		x++;
		if ((e = e -dy) <= 0)
		{
			y++;
			e+=dx;
		}
	}
}
