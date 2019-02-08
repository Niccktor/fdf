/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:06:50 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/08 20:12:17 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		main(int argc, char **argv)
{
	//t_mlx	*mlx_all;

	if (argc != 2)
	{
		ft_putstr("usage : ./fdf map_file\n");
		return (-1);
	}
	if (ft_read_file(argv[1]) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	/*
	mlx_all = ft_new_mlx();
	mlx_all = ft_new_win(mlx_all, "fdf", 1920, 1080);
	mlx_key_hook(mlx_all->win->win_ptr, ft_key_hook, (void *)mlx_all);
	mlx_mouse_hook(mlx_all->win->win_ptr, ft_mouse_hook, (void *)mlx_all);
	mlx_loop(mlx_all->mlx_ptr);*/
	return (0);
}
/*
int		main()
{
	char **test;

	test = (char **)ft_memalloc(sizeof(char *) * 5);
	test[0] = ft_strnew(20);
	ft_strcpy(test[0], "Bonjour");
	test[1] = ft_strnew(20);
	ft_strcpy(test[1], "test");
	test[2] = ft_strnew(20);
	ft_strcpy(test[2], "thomas");
	test[3] = ft_strnew(20);
	ft_strcpy(test[3], "42");
	test[4] = NULL;
	while (*test != NULL)
	{
		while (**test != '\0')
		{
			ft_putchar(**test);
			(*test)++;
		}
		ft_putstr("\n");
		test++;
	}
	return (0);
}*/
