/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etore_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 13:59:19 by panderss          #+#    #+#             */
/*   Updated: 2020/01/07 22:30:43 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*get_head(char *file);

t_piece		*add_link(t_piece *start, char **grid);

t_piece	*start_list(int *x, int *y)
{
	t_piece *start;

	ft_putendl("Starting list.");
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
	ft_putendl("First block assumed to be at x = 0, y = 0.");
	ft_putstr("Relative coordinates of second block: ");
	ft_putnbr(x[0]);
	ft_putstr(", ");
	ft_putnbr(y[0]);
	ft_putendl("");
	ft_putstr("Relative coordinates of third block: ");
	ft_putnbr(x[1]);
	ft_putstr(", ");
	ft_putnbr(y[1]);
	ft_putendl("");
	ft_putstr("Relative coordinates of second block: ");
	ft_putnbr(x[2]);
	ft_putstr(", ");
	ft_putnbr(y[2]);
	ft_putendl("Saving coordinates in struct...");
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

/* Gets each line of the 2D array. */

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
		file = tmp;
	}
	if ((file[len]) == '\0')
		return (0);
	/*else if (file[len] == '\0')
	{
		grid[lines_read] = ft_strdup(file);
		ft_strdel(&file);
		return (0);
	}*/
	return (1);
}

/* Reads from file into 2D array, calls find_coords to store them in linked list. */

t_piece		*store_tetro(char *file, int newlines)
{
	static char	*grid[4];
	int			ret;
	int			lines_read;
	t_piece		*start;

	start = get_head(file);
	file = ft_strsub(file, 42, ft_strlen(file));
	newlines = newlines - 5;
	lines_read = 0;
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
		ft_putendl("Transforming into 2d array...");
		lines_read = 0;
		while (lines_read < 4)
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
		add_link(start, grid);
		file = ft_strsub(file, 21, ft_strlen(file));
		newlines = newlines - 5;
	}
	/*if (ret == -1)
	{
		ft_putendl("Oops, I did it again...");
		display_error();
		return (-1);
	}*/
	return (start);
}
