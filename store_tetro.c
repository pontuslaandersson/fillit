/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:59:19 by panderss          #+#    #+#             */
/*   Updated: 2020/01/25 16:52:32 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece	*start_list(int *x, int *y)
{
	t_piece *start;

	start = create_list(x, y);
	return (start);
}

t_piece		*save_coords(char **grid, int j, int i)
{
	int count;
	int start_x;
	int start_y;
	int x[3];
	int y[3];

	start_x = i;
	start_y = j;
	count = 0;
	++i;
	while (count < 3 && j < 4)
	{
		while (grid[j][i] != '\0' && count < 3)
		{
			if (grid[j][i] == '#')
			{
				x[count] = (i - start_x);
				y[count] = (j - start_y);
				++count;
			}
			++i;
		}
		i = 0;
		++j;
	}
	return (start_list(x, y));
}

/* Finds hashes, saves their coords by calling save_choords. */

t_piece		*find_coords(char **grid)
{
	int i;
	int j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (grid[j][i] != '\0') 
		{
			if (grid[j][i] == '#')
				return (save_coords(grid, j, i));
			++i;
		}
		++j;
	}
	display_error(); 
	exit(-1);
}

/* Reads from file into 2D array, calls find_coords to store them in linked list. */

t_piece		*store_tetro(char *file, int newlines)
{
	static char	*grid[4];
	int			ret;
	int			lines_read;
	t_piece		*start;
	int			n;
/*	char		*tmp; */

	start = get_head(file);
	file = ft_strsub(file, 21, ft_strlen(file));
	newlines = newlines - 5;
	lines_read = 0;
	n = 1;
	while (newlines > 0)
	{
		while (lines_read < 4)
		{
			if (!(grid[lines_read] = ft_strnew(5)))
			{
				display_error(); 
				exit (-1);
			}
			lines_read++;
		}
		lines_read = 0;
		while (lines_read < 4)
		{
			ret = new_line(file, grid, lines_read);
			lines_read++;
		}
		add_link(start, grid, n);
		file = ft_strsub(file, 21, ft_strlen(file));
		newlines = newlines - 5;
		++n;
	}
	return (start);
}
