/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 15:09:20 by panderss          #+#    #+#             */
/*   Updated: 2019/12/28 17:26:42 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>
#include "fillit.h"

int		get_tetro(int fd, char **argv)
{
	char	*grid[4];
	char	*line;
	int		ret;
	int		lines_read;

	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1 && lines_read < 4)
	{
		grid[lines_read] = ft_strdup(line);
		free(line);
		lines_read++;
	}
	ft_putendl("test1");
	ft_putendl(grid[0]);
	ft_putendl(grid[1]);
	ft_putendl(grid[2]);
	ft_putendl(grid[3]);
	return (0);
}
