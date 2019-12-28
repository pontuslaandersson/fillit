/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:59:19 by panderss          #+#    #+#             */
/*   Updated: 2019/12/28 18:08:36 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		new_line(char *file, char **grid, int lines_read)
{
	char	*tmp;
	int		len;

	len = 0;
	while (file[len] != '\n' && file[len] != '\0')
		len++;
	if (file[len] == '\n')
	{
		grid[lines_read] = ft_strsub(file, (lines_read * 5), len);
		tmp = ft_strdup(file + len + 1);
//		ft_strdel(&file);
		file = tmp;
	}
	else if (file[len] == '\0')
	{
		grid[lines_read] = ft_strdup(file);
		ft_strdel(&file);
		return (0);
	}
	return (1);
}

int		store_tetro(char *file)
{
	static char	*grid[4];
	char		*line;
	int			ret;
	int			lines_read;

	/*Malloc for 2d array.*/
	lines_read = 0;
	while (lines_read < 4)
	{
		if (!(grid[lines_read] = ft_strnew(5)))
		{
			display_error();
			return (-1);
		}
		lines_read++;
	}
	ft_putendl("Transforming to 2d array...");
	lines_read = 0;
	while (/*(ret = new_line(file, grid, lines_read)) == 0 &&*/ lines_read < 4)
	{
		ret = new_line(file, grid, lines_read);
		ft_putendl("Increasing lines_read...");
		lines_read++;
	}
	ft_putnbr(ret);
	ft_putstr("First line of array: ");
	ft_putendl(grid[0]);/* Lines to display what we have read from the string.*/
	ft_putstr("Second line of array: ");
	ft_putendl(grid[1]);
	ft_putstr("Third line of array: ");
	ft_putendl(grid[2]);
	ft_putstr("Fourth line of array: ");
	ft_putendl(grid[3]);
	return (0);
}
