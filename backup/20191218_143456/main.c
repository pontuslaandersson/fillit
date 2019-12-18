/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/17 18:11:40 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

void	display_error(void)
{
	ft_putstr("error");
}

int		check_tetromino(char *tetro);

int		read_tetromino(int fd, char **line)
{
//	char	*grid[4];
//	char	*tmp[4];
	char	*str;
	char	*tmp;
	char	tetro[20];
	int		lines_read;
	int		ret;

	lines_read = 0;
	while ((ret = get_next_line(fd, line)) == 1 && lines_read < 4)
	{
		/*BUILD TMP STRING TO SEND TO VALIDATOR*/
		lines_read++;
	}
/*	tmp[0] = ft_strdup(grid[0]);
	tmp[1] = ft_strdup(grid[1]);
	tmp[2] = ft_strdup(grid[2]);
	tmp[3] = ft_strdup(grid[3]);
	ft_putstr("Lines read: ");
	ft_putnbr(lines_read);
	ft_putchar('\n');
	ft_putendl(tmp[0]);
	ft_putendl(tmp[1]);
	ft_putendl(tmp[2]);
	ft_putendl(tmp[3]);*/
	if (check_tetromino(tmp) != 0)
	{
		ft_putendl("Tetromino checker failed.");
		display_error();
		return (-1);
	}
	else
	{
		ft_putendl("Valid tetromino read.");
		/*ft_putendl(tmp[0]);
		ft_putendl(tmp[1]);
		ft_putendl(tmp[2]);
		ft_putendl(tmp[3]);*/
		ret = check_shape(tmp);
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
		ft_putendl("usage: ./fillit tetromino_file");
		return (-1);
	}
	else
	{
		if (!(fd = open(argv[1], O_RDONLY)) || fd < 0 || fd > FD_MAX)
		{
			display_error();
			return (-1);
		}
		ret = read_tetromino(fd, &line);
	}
	return (0);
}
