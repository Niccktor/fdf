/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:45:12 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/16 13:39:27 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
void		test_segment(t_mlx *mlx_all, int x, int y, int color);
/*
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
*/

/*								pappy								*/
/*void		ft_draw_ligne(t_mlx *mlx_all, t_point *point1,
		t_point *point2, int color)
{
	t_point		*mid;
	int			x;
	int			y;

	ft_putstr("-------draw--------\n");
	ft_putnbr(point1->x);
	ft_putstr("\n");
	ft_putnbr(point1->y);
	ft_putstr("\n mlx var : \n");
	ft_putnbr(mlx_all->win->x_ligne);
	ft_putstr("\n");
	ft_putnbr(mlx_all->win->y_ligne);
	ft_putstr("\n Calcul : \n");
	ft_putnbr((mlx_all->win->x_ligne + point1->x) / 2);
	ft_putstr("\n");
	ft_putnbr((mlx_all->win->y_ligne + point1->y) / 2);
	ft_putstr("\n count : \n");
	ft_putnbr(mlx_all->win->count);
	ft_putstr("\n");
	ft_putstr("-------------------\n");

	mlx_all->win->count++;
	mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr,
			point1->x, point1->y, color);
	if (mlx_all->win->count <= 1000)
	{
		return ;
	}
	else if (point2 == NULL)
	{
		x = (mlx_all->win->x_ligne + point1->x) / 2;
		y = (mlx_all->win->y_ligne + point1->y) / 2;
		mid = ft_new_point(x, y);
		return (ft_draw_ligne(mlx_all, mid, point1, color));
	}
	else
	{
		x = (point1->x + point2->x) / 2;
		y = (point1->y + point2->y) / 2;
		mid = ft_new_point(x, y);
		return (ft_draw_ligne(mlx_all, point1, mid, color),
				ft_draw_ligne(mlx_all, mid, point2, color));
	}
}*/

void		ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color)
{

	test_segment(mlx_all, x, y, color);
/*	t_bres	*bres;
	int i;

	bres = ft_new_bres(mlx_all->win->x_ligne, mlx_all->win->y_ligne, x, y);
	i = 0;

	ft_putstr("-------Draw--------\nbres : \ncor :\nx : ");
	ft_putnbr(bres->cor->x);
	ft_putstr("\ny : ");
	ft_putnbr(bres->cor->y);
	ft_putstr("\nex : ");
	ft_putnbr(bres->ex);
	ft_putstr("\ney : ");
	ft_putnbr(bres->ey);
	ft_putstr("\ndx : ");
	ft_putnbr(bres->dx);
	ft_putstr("\ndy : ");
	ft_putnbr(bres->dy);
	ft_putstr("\ndx_const : ");
	ft_putnbr(bres->dx_const);
	ft_putstr("\ndy_const : ");
	ft_putnbr(bres->dy_const);
	ft_putstr("\nx_inc : ");
	ft_putnbr(bres->x_inc);
	ft_putstr("\ny_int : ");
	ft_putnbr(bres->y_inc);
	ft_putstr("\n------------------\n");*/

/*	if (bres->dx_const == 0)
	{
		while ()
	}
	if (bres->dx_const > bres->dy_const)
	{
		while (i <= bres->dx_const)
		{
			mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr,bres->cor->x,
					bres->cor->y, color);
			i++;
			bres->cor->x += bres->x_inc;
			bres->ex -= bres->dy;
			if (bres->ex < 0)
			{
				bres->cor->y += bres->y_inc;
				bres->ex += bres->dx;
			}
		}
	}
	else
		ft_draw_ligne2(mlx_all, bres, color);*/
}
/*
void	ft_draw_ligne2(t_mlx *mlx_all, t_bres *bres, int color)
{
	int i;

	i = 0;
	while (i <= bres->dx_const)
	{
		mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr,bres->cor->x ,
				bres->cor->y, color);
		i++;
		bres->cor->y += bres->y_inc;
		bres->ey -= bres->dx;
		if (bres->ey < 0)
		{
			bres->cor->x += bres->x_inc;
			bres->ey += bres->dy;
		}
	}
}
*/

/*

	ft_putstr("-------draw--------\npoint1 : \n X : ");
	ft_putnbr(point1->x);
	ft_putstr("\n y : ");
	ft_putnbr(point1->y);
	ft_putstr("\n mlx var : \n X : ");
	ft_putnbr(mlx_all->win->x_ligne);
	ft_putstr("\n Y : ");
	ft_putnbr(mlx_all->win->y_ligne);
	ft_putstr("\n Calcul : \n dx : ");
	ft_putnbr(dx);
	ft_putstr("\n Dy : ");
	ft_putnbr(dy);
	ft_putstr("\n dx mod dy : ");
	ft_putnbr(dx % dy);
	ft_putstr("\n dx div dy : ");
	ft_putnbr(dx / dy);
	ft_putstr("\n-------------------\n");*/


/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


void		test_segment(t_mlx *mlx_all, int x, int y, int color)
{
	int x1;
	int y1;
	int dx;
	int dy;
	int e;

	x1 = mlx_all->win->x_ligne;
	y1 = mlx_all->win->y_ligne;
	e = x - x1;
	dx = e * 2;
	dy = (y - y1) * 2;
	while (x1 <= x)
	{
		mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win->win_ptr, x1, y1, color);
		x1++;
		e -= dy;
		if (e <= 0)
		{
			y1++;
			e += dx;
		}
	}
}














