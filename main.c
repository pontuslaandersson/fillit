/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2019/12/27 16:00:48 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		check_tetrominos(char *file);

char    *get_file(int fd)
{
    static char *str;
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	char		*tmp;

    while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
    {
		buf[ret] = '\0';
		if (str == NULL)
			str = ft_strnew(0);
		tmp = ft_strjoin(str, buf);
		ft_strdel(&str);
		str = tmp;
	}
	if (ret < 0)
		return (NULL);
	ft_putendl("String read into str:");
	ft_putstr(str);
	return (str);
}

int		read_file(int fd)
{
	char		*file;
	int			tetros_read;
	
	file = get_file(fd);
	if (file == NULL)
	{
		display_error();
		return (-1);
	}
	/*tetros_read = 0;*/
	tetros_read = check_tetrominos(file);
	if (tetros_read == 0)
		ft_putendl("File validated by checker!");
	else
	{
		ft_putendl("Wah, wah...");
		display_error();
		return (-1);
	}
	/*while (tetros_read < 26)
	{
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
		ret = read_file(fd);
	}
	return (0);
}
