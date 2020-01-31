/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:59:19 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:41:57 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Trims the file, removing the tetromino just stored, and frees the grid.
*/

char		*trim_file_and_free_grid(char *file, char **grid)
{
	char *tmp;

	tmp = ft_strsub(file, 21, ft_strlen(file));
	free(file);
	file = tmp;
	free(grid[0]);
	free(grid[1]);
	free(grid[2]);
	free(grid[3]);
	return (file);
}

/*
** Trims the file, removing the tetromino just stored.
*/

char		*trim_file(char *file)
{
	char *tmp;

	tmp = ft_strsub(file, 21, ft_strlen(file));
	free(file);
	file = tmp;
	return (file);
}

/*
** Saves the coordinates in int arrays, and sends them to create_list.
*/

t_piece		*save_coords(char **grid, int j, int i)
{
	int count;
	int start_x;
	int start_y;
	int x[3];
	int y[3];

	start_x = i - 1;
	start_y = j;
	count = 0;
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
	return (create_list(x, y));
}

/*
** Finds hashes, saves their coordinates by calling save_choords.
*/

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
				return (save_coords(grid, j, i + 1));
			++i;
		}
		++j;
	}
	display_error();
	exit (-1);
}

/*
** Reads from file into 2D array, calls find_coords to store them.
*/

t_piece		*store_tetro(char *file, int newlines)
{
	static char	*grid[4];
	int			lines_read;
	t_piece		*start;
	int			n;

	start = get_head(file);
	file = trim_file(file);
	lines_read = 0;
	n = 1;
	while ((newlines - 5) > 0)
	{
		lines_read = 0;
		while (lines_read < 4)
		{
			new_line(file, grid, lines_read);
			++lines_read;
		}
		add_link(start, grid, n);
		file = trim_file_and_free_grid(file, grid);
		newlines = newlines - 5;
		++n;
	}
	free(file);
	return (start);
}
