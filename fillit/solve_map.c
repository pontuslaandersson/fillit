/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:55:02 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:51:18 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			backtrack(t_piece *cursor, char **map, int j, int i)
{
	int x;
	int y;
	int replaced;

	replaced = 0;
	while (j < (int)ft_strlen(map[0]) && replaced < 4)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == cursor->letter)
			{
				map[j][i] = '.';
				if (replaced == 0)
				{
					x = i;
					y = j;
				}
				++replaced;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (y * ft_strlen(map[0]) + x + 1);
}

int			solve_map(t_piece *cursor, char **map, int x, int y)
{
	int			ret;
	int			n;

	while (cursor != NULL)
	{
		ret = find_dot(cursor, map, x, y);
		if (ret == -1 && cursor->prev != NULL)
		{
			cursor = cursor->prev;
			n = backtrack(cursor, map, 0, 0);
			x = n % ft_strlen(map[0]);
			y = n / ft_strlen(map[0]);
			ret = find_dot(cursor, map, x, y);
		}
		if (ret == 0)
		{
			cursor = cursor->next;
			y = 0;
			x = 0;
		}
		if (ret == -1 && (cursor == NULL || cursor->prev == NULL))
			return (-1);
	}
	return (0);
}
