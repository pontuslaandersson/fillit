/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:34:03 by panderss          #+#    #+#             */
/*   Updated: 2020/01/22 18:18:17 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*t_piece		*add_piece(t_piece *ret, int *x, int *y)
{
    t_piece *cursor = ret;
    while(cursor->next != NULL)
        cursor = cursor->next;

    t_piece	*new_node =  create(x, y, cursor, NULL);
    cursor->next = new_node;

    return (ret);
}*/

t_piece		*save_addlink_coords(t_piece *start, char **grid, int j, int i, int n)
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
	return (add_piece(start, x, y, n));
}

/* Finds hashes, saves their coords by calling save_choords. */

t_piece		*add_link(t_piece *start, char **grid, int n)
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
				return (save_addlink_coords(start, grid, j, i, n));
			++i;
		}
		++j;
	}
	display_error();
	exit(-1);
}
