/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:07:46 by panderss          #+#    #+#             */
/*   Updated: 2020/01/07 22:08:21 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	/*if ((file[len]) == '\0')
		return (0);*/
	/*else if (file[len] == '\0')
	{
		grid[lines_read] = ft_strdup(file);
		ft_strdel(&file);
		return (0);
	}*/
	return (1);
}
