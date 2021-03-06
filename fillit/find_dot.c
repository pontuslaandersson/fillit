/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:07:46 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:55:48 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		find_dot(t_piece *cursor, char **map, int x, int y)
{
	int ret;

	ret = 1;
	while (y < (int)ft_strlen(map[0]) && ret != 0)
	{
		if (map[y][x] == '.')
		{
			ret = check_candidate(cursor, map, x, y);
			if (ret == -1 && map[y][x + 1] != '\0' && map[y][x + 1] == '.')
				ret = check_candidate(cursor, map, x + 1, y);
		}
		x++;
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	return (ret);
}
