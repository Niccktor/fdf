/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 19:36:50 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(/*int argc, char **argv*/)
{
	t_mlx	*mlx_all;

	/*if (argc != 2)
	{
		ft_putstr("usage : ./fdf map_file\n");
		return (-1);
	}*/
	mlx_all = ft_new_mlx();
	mlx_all = ft_new_win(mlx_all, "fdf", 1920, 1080);


	mlx_key_hook(mlx_all->win->win_ptr, ft_key_hook, (void *)mlx_all);
	mlx_mouse_hook(mlx_all->win->win_ptr, ft_mouse_hook, (void *)mlx_all);
	mlx_loop(mlx_all->mlx_ptr);
	return (0);
}
