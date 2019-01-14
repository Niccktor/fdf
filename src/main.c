/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 16:27:06 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int 	ft_hook(int key)
{
	ft_putnbr(key);
	ft_putstr("\n");
	return (0);
}

int		main(int argc, char **argv)
{
	void *mlx_ptr;
	void *mlx_win;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf map_file\n");
		return (-1);
	}
	argv[1] = "test";
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 500, 500, "Je suis une fenetre !");
	mlx_key_hook(mlx_win, ft_hook, (void *)0);
	mlx_loop(mlx_ptr);
	return (0);
}
