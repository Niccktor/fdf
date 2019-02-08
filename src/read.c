/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:52 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/08 20:32:45 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <fcntl.h>

/*char	***/int ft_read_file(char *file)
{
//	t_map	*map;
	int		fd;
	char	*line;
	char	**split;


	fd = open(file, O_RDONLY);
	
//	map = (t_map *)ft_memalloc();

	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		ft_check_file(split);
	}
	return (0);
}

int 	ft_check_file(char **split)
{
	int i;

	while (*split != NULL)
	{
		i = 0;
		while (**split != '\0')
		{
			if ((i == 0 && **split == '-')
					|| ft_isdigit(**split) == 1)
				(*split)++;
			else if (**split == ',')
			{
				ft_putstr("Len split hexa : ");
				ft_putnbr(ft_strlen(*split));
				ft_putstr("\nStr split : ");
				ft_putstr(*split);
				ft_putstr("\nStr split sub : ");
				ft_putstr(ft_strsub(*split, 1, 8));
				ft_putstr("\n");
				split++;
			}
			else
				return (-1);
			i++;
		}
		split++;
	}
	return (0);
}
