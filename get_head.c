/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:53:51 by panderss          #+#    #+#             */
/*   Updated: 2020/01/07 22:21:41 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*get_head(char *file)
{
	static char	*start_grid[4];
	int			ret;
	int			lines_read;
	t_piece		*start;

	lines_read = 0;
	while (lines_read < 4)
	{
		if (!(start_grid[lines_read] = ft_strnew(5)))
		{
			display_error();
			exit (-1);
		}
		lines_read++;
	}
	ft_putendl("Transforming into 2d array...");
	lines_read = 0;
	while (lines_read < 4)
	{
		ret = new_line(file, start_grid, lines_read);
		ft_putendl("Increasing lines_read...");
		lines_read++;
	}
	ft_putnbr(ret);
	ft_putstr("First line of array: ");
	ft_putendl(start_grid[0]);/* Lines to display what we have read from the string.*/
	ft_putstr("Second line of array: ");
	ft_putendl(start_grid[1]);
	ft_putstr("Third line of array: ");
	ft_putendl(start_grid[2]);
	ft_putstr("Fourth line of array: ");
	ft_putendl(start_grid[3]);
	start = find_coords(start_grid);
	return (start);
}
