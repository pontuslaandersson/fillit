/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/20 15:59:24 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

/*	ret = read(fd, buf, 21);
	ft_putstr("Characters read from file: ");
	ft_putnbr(ret);
	ft_putendl("");
	if (ret < 0)
		ft_putendl("Read failed");
	tetro = ft_strdup(buf);
	ft_putendl("Map read: ");
	ft_putstr(tetro);
	if (check_tetromino(tetro) != 0)
	{
		ft_putendl("Map element checker failed.");
		ft_putendl(tetro);
		display_error();
		return (-1);
	}
	else
	{
		ft_putendl("Valid map element read.");
		ft_putstr(tetro);
	}
	return (0);
*/

void	display_error(void)
{
	ft_putstr("error");
}

int		check_tetromino(char *tetro);



int		check_file(char *file);

int		read_file(int fd, char **line)
{
	static char	*file;
	char		*tetro;
	char		buf[21];
	ssize_t		ret;
	int			tetros_read;
	
	tetros_read = 0;
	while (tetros_read < 26 && (ret = read(fd, buf, 21)) >  0)
	{
		ft_putstr("read return: ");
		ft_putnbr(ret);
		ft_putendl("");
		if (ret < 0)
			ft_putendl("Read failed");
		tetro = ft_strdup(buf);
		ft_putendl("Map read: ");
		ft_putstr(tetro);
		if (check_tetromino(tetro) != 0)
		{
			ft_putendl("Map element checker failed.");
			ft_putendl(tetro);
			display_error();
			return (-1);
		}
		else
		{
			ft_putendl("Valid map element read.");
			ft_putstr(tetro);
		}
		++tetros_read;
	}
	if (ret != 0)
	{
		display_error();
		ft_putstr("\nRead return not 0; more than 26 tetros in file.");
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
		ret = read_file(fd, &line);
	}
	return (0);
}
