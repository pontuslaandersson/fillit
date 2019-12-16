/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/16 16:32:24 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

void	display_error(void)
{
	ft_putstr("error");
}

/*int		validate_tetrimino(char **tetr)
{

}*/

int		read_tetrimino(int fd, char **line)
{
	char	*grid[4];
	char	*tmp[4];
	int		lines_read;
	int		ret;

	lines_read = 0;	
	while ((ret = get_next_line(fd, line)) == 1 && lines_read < 4)
	{
		grid[lines_read] = ft_strdup(*line);
		//free(line);
		lines_read++;
	}
	tmp[0] = ft_strdup(grid[0]);
	tmp[1] = ft_strdup(grid[1]);
	tmp[2] = ft_strdup(grid[2]);
	tmp[3] = ft_strdup(grid[3]);
	if (check_tetrimino(tmp) != 0)
	{
		display_error();
		return (-1);
	}
	else
	{
		ft_putendl("Valid tetrimino read.");
		ft_putendl(tmp[0]);
		ft_putendl(tmp[1]);
		ft_putendl(tmp[2]);
		ft_putendl(tmp[3]);
	
	}
	return (0);
}	

int		main(int argc, char **argv)
{
	char		*line;
	int			ret;
	int			fd;

	if (argc != 2)
	{
		//ft_putendl("error");
		display_error();
		return (-1);
	}
	else
	{
		if (!(fd = open(argv[1], O_RDONLY)) || fd < 0 || fd > FD_MAX)
		{
			display_error();
			return (-1);
		}
		ret = read_tetrimino(fd, &line);
	}
	return (0);
}
