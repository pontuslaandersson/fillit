/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:34:03 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:29:42 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Puts the coordinates relative to the first hash (x = 0, y = 0), putting them
** into arrays. These are then saved by calling and returning add_piece.
*/

t_piece		*save_addlink_coords(t_piece *start, char **grid, int j, int i)
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
	return (add_piece(start, x, y));
}

/*
** Adds a node to the linked linked list containing our tetromino shapes.
** This is done by first finding a hash, and calling save_addlink_coords
** to save the coordinates, and assign_letter to add the letter to the 
** node.
*/

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
				ret = save_addlink_coords(start, grid, j, i + 1);
				ret = assign_letter(start, n);
				return (ret);
			}
			++i;
		}
		++j;
	}
	display_error();
	exit (-1);
}
