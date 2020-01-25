/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:50 by panderss          #+#    #+#             */
/*   Updated: 2020/01/25 14:46:05 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

t_piece		*store_tetro(char *file, int newlines);

int		check_tetrominos(char *file);

/* Reads the file into a buffer, and which it joins to previously read */
/* material. It keeps going until it has read the whole file into a string, */
/* which it then returns. */

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
		/*ft_strdel(&tmp);*/
	}
	if (ret < 0)
		return (NULL);
	return (str);
}

/* Where the action happens. Calls get_file, calls check_tetrominos, */
/* calls store_tetro. */

int		read_file(int fd)
{
	static char		*file;
	int				ret;
	t_piece			*head;
	int				max;
	
	file = get_file(fd);
	if (file == NULL)
	{
		display_error();
		return (-1);
	}
	ret = check_tetrominos(file);
	if (ret == -1)
		return (-1);
	head = store_tetro(file, ret);
	ft_strdel(&file);
	max = ((ret + 1) / 5);
	solve(head, ret, max);
	del_list(head);
	return (0);
}

/* Main opens file and goes to read_file.*/

int		main(int argc, char **argv)
{
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
		if (ret == -1)
		{
			display_error();
			return (-1); 
		}
	}
	while (1)
	{
		
	}
	return (0);
}
