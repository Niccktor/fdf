/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/08 20:29:29 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_map
{
	int				*depth;
	int				*color;
	int				len;
	struct t_map	*prev;
	struct t_map	*next;
}					t_map;

typedef struct		s_bres
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	double			dx;
	double			dy;
	int				x_inc;
	int				y_inc;
	int				i;
	int				error;
}					t_bres;


typedef struct		s_win
{
	void			*win_ptr;
	char			*name;
	int 			size_x;
	int 			size_y;
	int				ligne;
	int				x_ligne;
	int				y_ligne;
}					t_win;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	t_win			*win;
}					t_mlx;

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
/*
 *					read.c
 */
int		ft_read_file(char *file);
int		ft_check_file(char **split);

#endif
