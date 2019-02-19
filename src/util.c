/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:30:51 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/19 17:59:14 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_mlx	*ft_new_mlx()
{
	t_mlx	*new;

	new = (t_mlx *)ft_memalloc(sizeof(t_mlx));
	if (new == NULL)
		return (NULL);
	new->mlx_ptr = mlx_init();
	new->map = (t_map *)ft_memalloc(sizeof(t_map));
	if (new->map == NULL)
		return (NULL);
	new->map->len = -1;
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

t_point		*ft_new_point(int x, int y)
{
	t_point *new;

	new = (t_point *)ft_memalloc(sizeof(t_point));
	new->x = x;
	new->y = y;
	return (new);
}

void		ft_free_point(t_point *old)
{
	return (ft_memdel((void **)old));
}

int		ft_ishexa(char c)
{
	if (ft_isdigit(c) == 1
			|| ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')))
		return (1);
	return (0);
}
