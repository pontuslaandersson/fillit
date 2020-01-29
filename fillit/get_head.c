/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_head.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 21:53:51 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:55:28 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*get_head(char *file)
{
	static char	*start_grid[4];
	int			lines_read;
	t_piece		*start;

	lines_read = 0;
	while (lines_read < 4)
	{
		new_line(file, start_grid, lines_read);
		lines_read++;
	}
	start = find_coords(start_grid);
	return (start);
}
