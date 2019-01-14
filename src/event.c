/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:31:01 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 18:43:14 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

#define BLEU 0x0A5FE8
#define WHITE 0xFFFFFF

int 	ft_key_hook(int key, void *para)
{
	t_mlx *mlx_all;

	mlx_all = (t_mlx *)para;
	if (key == 53)
	{
		mlx_destroy_window(mlx_all->mlx_ptr, mlx_all->win_ptr);
		exit(0);
		return (1);
	}
	ft_putstr("----------------------key----------------------\n");
	ft_putnbr(key);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	return (0);
}

int		ft_mouse_hook(int button, int x, int y, void *para)
{
	t_mlx *mlx_all;

	mlx_all = (t_mlx *)para;
	ft_putstr("----------------------mouse--------------------\n");
	ft_putnbr(button);
	ft_putstr("\n");
	ft_putnbr(x);
	ft_putstr("\n");
	ft_putnbr(y);
	ft_putstr("\n");
	ft_putstr("-----------------------------------------------\n");
	if (button == 1)
	{
		mlx_pixel_put(mlx_all->mlx_ptr, mlx_all->win_ptr, x, y, WHITE);
	}

	return (0);
}
