/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_candidate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:04:51 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 21:56:29 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_candidate(t_piece *cursor, char **map, int x, int y)
{
	if (y + 1 == (int)ft_strlen(map[0]) && x + 1 == (int)ft_strlen(map[0]))
		return (-1);
	if ((y + (cursor->y[0])) < (int)ft_strlen(map[0])
			&& (y + (cursor->y[1])) < (int)ft_strlen(map[0])
			&& (y + (cursor->y[2])) < (int)ft_strlen(map[0]))
	{
		if (map[y + cursor->y[0]][x + cursor->x[0]] == '.')
		{
			if (map[y + (cursor->y[1])][x + (cursor->x[1])] == '.')
			{
				if (map[y + (cursor->y[2])][x + (cursor->x[2])] == '.')
				{
					map[y][x] = cursor->letter;
					map[y + cursor->y[0]][x + cursor->x[0]] = cursor->letter;
					map[y + cursor->y[1]][x + cursor->x[1]] = cursor->letter;
					map[y + cursor->y[2]][x + cursor->x[2]] = cursor->letter;
					return (0);
				}
			}
		}
	}
	return (-1);
}
