/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:52 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/19 15:20:02 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <fcntl.h>

int		ft_parse_map(char *file, t_mlx *mlx_all)
{
	char	*line;
	int		fd;

	if ((mlx_all->map->height = ft_get_height(file)) == 0)
			return (-1);
	mlx_all->map->map = (int **)ft_memalloc(sizeof(int *) *
			(mlx_all->map->height + 1));
	mlx_all->map->color = (int **)ft_memalloc(sizeof(int *) *
			(mlx_all->map->height + 1));
	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_check_line(line) == -1)
			return (-1);
		ft_putstr(line);
		ft_putchar('\n');
		ft_get_map(mlx_all, ft_strsplit(line));
	}
	return (0);
}

void	ft_get_map(t_mlx *mlx_all, char **line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		ft_putnbr(ft_atoi(line[i]));
		ft_putstr("\n");
		i++;
	}
	mlx_all->map->len = 0;
}

int		ft_check_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i + j] != '\0')
	{
		j = 0;
		if (line[i] == ',')
		{
			ft_putstr("\n");/**/
			j = 1;
			while (line[i + j] != ' ' && line[i + j] != '\0')
			{
				ft_putchar(line[i + j]);/**/
				if ((j == 1 && line[i + j] == '0')
						|| (j == 2 && line[i + j] == 'x')
						|| (j > 2 && j < 9 && ft_ishexa(line[i + j ]) == 1))
					j++;
				else  
					return (-1);
			}
		}
		i++;
	}
	return (0);
}

int		ft_get_height(char *file)
{
	char	*line;
	int		fd;
	int		height;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (-1);
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}
