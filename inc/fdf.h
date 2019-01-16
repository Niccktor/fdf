/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/01/16 14:32:53 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_bres
{
	t_point		*cor1;
	t_point		*cor2;
	int			x_inc;
	int			y_inc;
	int			ex;
	int			ey;
	int			dx;
	int 		dy;
	int			dx_const;
	int			dy_const;
	int 		e;
}				t_bres;


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
t_point *ft_new_point(int x, int y);
t_bres	*ft_new_bres(int x1, int y1, int x2, int y2);
int		ft_abs(int x);
/*
 *
 */
void	ft_draw_ligne(t_mlx *mlx_all, int x, int y/*, t_point *point1, t_point *point2*/, int color);
void	ft_draw_ligne2(t_mlx *mlx_all, t_bres *bres, int color);


#endif
