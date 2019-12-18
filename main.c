/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/18 14:59:57 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

void	display_error(void)
{
	ft_putstr("error");
}

/*int		check_tetromino(char *tetro);*/

int		read_file(int fd, char **line)
{
	char	*str;
	char	*tmp;
	char	buf[22];
	int		lines_read;
	int		ret;

	lines_read = 0;
	/*while ((ret = get_next_line(fd, line)) == 1)
	{
		/*if (str == 0)
			str = ft_strnew(0);
		tmp = ft_strjoin(str, *line);
		str = tmp;
		lines_read++;
	}
	ft_putstr("Lines read: ");
	ft_putnbr(lines_read);
	ft_putendl("");*/
	ret = read(fd, buf, 21);
	ft_putstr("Characters read from file: ");
	ft_putnbr(ret);
	ft_putendl("");
	if (ret < 0)
		ft_putendl("Read failed");
	str = ft_strdup(buf);
	ft_putendl("Map read: ");
	ft_putstr(str);
	/*if (check_tetromino(tmp) != 0)
	{
		ft_putendl("Tetromino checker failed.");
		display_error();
		return (-1);
	}
	else
	{
		ft_putendl("Valid tetromino read.");
		ft_putendl(tmp[0]);
		ft_putendl(tmp[1]);
		ft_putendl(tmp[2]);
		ft_putendl(tmp[3]);
		ret = check_shape(tmp);
	}*/
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
