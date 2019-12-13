/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/12 16:17:12 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

void	display_error(void)
{
	ft_putstr("error");
}

int		main(int argc, char **argv)
{
	char	*grid[4];
	char	*line;
	int		ret;
	int		lines_read;
	int		fd;

	ft_putendl("Starting program.");
	if (argc != 2)
	{
		//ft_putendl("error");
		display_error();
		return (-1);
	}
	else
	{
		lines_read = 0;
		blocks = 0;
		if (!(fd = open(argv[1], O_RDONLY)) || fd < 0 || fd > FD_MAX)
		{
			display_error();
			return (-1);
		}
		while ((ret = get_next_line(fd, &line)) == 1 && lines_read < 4)
		{
			grid[lines_read] = ft_strdup(line);
			free(line);
			lines_read++;
		}
		ft_putendl(grid[0]);
		ft_putendl(grid[1]);
		ft_putendl(grid[2]);
		ft_putendl(grid[3]);
	}
	return (0);
}
