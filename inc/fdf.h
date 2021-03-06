/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:09:03 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/27 00:13:06 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct		s_map
{
	int				**map;
	unsigned int	**color;
	int				height;
	int				len;
}					t_map;

typedef struct		s_bres
{
	double			x1;
	double			y1;
	double			x2;
	double			y2;
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
	int 			width;
	int 			height;
	int				ligne;
	int				x_ligne;
	int				y_ligne;
}					t_win;

typedef struct		s_cam
{
	int				up_down;
	int				left_right;
	double			di_x;
	double			di_y;
	double			di_z;
	char			proj;
	double			angle;
}					t_cam;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	t_win			*win;
	t_map			*map;
	t_cam			*cam;
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
t_mlx	*ft_new_win(t_mlx *mlx_all, char *s, int width, int height);
t_mlx	*ft_new_cam(t_mlx *mlx_all);
int		ft_ishexa(char c);
/*
 *					draw.c
 */
t_bres	*ft_new_bres(int x1, int y1, int x2, int y2);
void	ft_draw_ligne(t_mlx *mlx_all, int x, int y, int color);
int		ft_draw_map(t_mlx *mlx_all);
/*
 *					read.c
 */
int		ft_parse_map(char *file, t_mlx *mlx_all);
int		ft_get_map(t_mlx *mlx_all, char **line, int k);
int		ft_check_line(char *line);
int		ft_get_height(char *file);
/*
 *					color.c
 */
unsigned int	ft_get_color(char *rgb);


/*
 * 					iso.c
 */
void			ft_iso(t_mlx *mlx_all);
/*
 *					retation.c
 */
void			ft_x_rotation(t_mlx *mlx_all);


void			ft_print_tab(t_mlx *mlx_all);

#endif
