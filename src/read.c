/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeguin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 17:34:52 by tbeguin           #+#    #+#             */
/*   Updated: 2019/02/08 18:22:38 by tbeguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <fcntl.h>

/*char	***/int ft_check_file(char *file)
{
	int		fd;
	int		i;
	char	*line;
	char	**split;

	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		split = ft_strsplit(line, ' ');
		i = -1;
		while (split[++i] != '\0')
		{
			ft_putstr(split[i]);
		}
		ft_putstr("\n");
	}
	return (0);
}
