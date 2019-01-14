/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 19:51:02 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mlx	*ft_new_mlx()
{
	t_mlx	*new;

	new = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	new->mlx_ptr = mlx_init();
	return (new);
}

t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int size_x, int size_y)
{
	mlx_all->win = (t_win *)ft_memalloc(sizeof(t_win));
	mlx_all->win->name = s;
	mlx_all->win->size_x = size_x;
	mlx_all->win->size_y = size_y;
	mlx_all->win->win_ptr = mlx_new_window(mlx_all->mlx_ptr,mlx_all->win->size_x
			, mlx_all->win->size_y, mlx_all->win->name);
	mlx_all->win->ligne = 0;
	mlx_all->win->x_ligne = 0;
	mlx_all->win->y_ligne = 0;

	return (mlx_all);
}
