/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2020/01/02 15:40:08 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fillit.h"
#include <fcntl.h>

int		store_tetro(char *file);

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
	int			ret;
	
	file = get_file(fd);
	if (file == NULL)
	{
		display_error();
		return (-1);
	}
	/*tetros_read = 0;*/
	ret = check_tetrominos(file);
	if (ret == 0)
		ft_putendl("File validated by checker!");
	else
	{
		ft_putendl("Invalid file; exiting. Wah, wah...");
		display_error();
		return (-1);
	}
	ret = store_tetro(file);
/*	while (1)
		ft_putendl("Loops and leaks...");*/
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
