/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/14 20:11:06 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_win
{
	void		*win_ptr;
	char		*name;
	int 		size_x;
	int 		size_y;
	int			ligne;
	int			x_ligne;
	int			y_ligne;
}				t_win;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	t_win		*win;
}				t_mlx;
/*
 *					event.c
 */
int		ft_key_hook(int key, void *para);
int		ft_mouse_hook(int button, int x, int y, void *para);


/*
 *					util.c
 */
t_mlx	*ft_new_mlx();
t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int size_x, int size_y);
/*
 *
 */
void	ft_draw_ligne(t_mlx *mlx_all,int x, int y, int color);

#endif
