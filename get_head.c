/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:53:51 by panderss          #+#    #+#             */
/*   Updated: 2020/01/25 13:37:17 by panderss         ###   ########.fr       */
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
	lines_read = 0;
	while (lines_read < 4)
	{
		ret = new_line(file, start_grid, lines_read);
		lines_read++;
	}
	start = find_coords(start_grid);
	free_array(start_grid);
	return (start);
}
