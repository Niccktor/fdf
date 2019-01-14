/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 18:43:16 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int argc, char **argv)
{
	t_mlx	*mlx_all;

	mlx_all = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (argc != 2)
	{
		ft_putstr("usage : ./fdf map_file\n");
		return (-1);
	}
	argv[1] = "test";
	mlx_all->mlx_ptr = mlx_init();
	mlx_all->win_ptr= mlx_new_window(mlx_all->mlx_ptr,
			500, 500, "Je suis une fenetre !");
	mlx_key_hook(mlx_all->win_ptr, ft_key_hook, (void *)mlx_all);
	mlx_mouse_hook(mlx_all->win_ptr, ft_mouse_hook, (void *)mlx_all);
	mlx_loop(mlx_all->mlx_ptr);
	return (0);
}
