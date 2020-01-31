/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:07:46 by panderss          #+#    #+#             */
/*   Updated: 2020/01/28 11:52:33 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Extracts a new line from the source string (file), putting it into our grid.
*/

void		new_line(char *file, char **grid, int lines_read)
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
		ft_strdel(&tmp);
	}
}
