/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:09:05 by panderss          #+#    #+#             */
/*   Updated: 2020/01/07 22:09:07 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
