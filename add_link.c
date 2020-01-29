/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:34:03 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 16:20:46 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*save_addlink_coords(t_piece *start, char **grid, int j, int i)
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
	return (add_piece(start, x, y));
}

t_piece		*add_link(t_piece *start, char **grid, int n)
{
	int			i;
	int			j;
	t_piece		*ret;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (grid[j][i] != '\0')
		{
			if (grid[j][i] == '#')
			{
				ret = save_addlink_coords(start, grid, j, i);
				ret = assign_letter(start, n);
				return (ret);
			}
			++i;
		}
		++j;
	}
	display_error();
	exit(-1);
}
