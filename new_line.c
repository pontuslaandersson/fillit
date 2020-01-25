/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 22:07:46 by panderss          #+#    #+#             */
/*   Updated: 2020/01/25 11:44:33 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	return (1);
}
