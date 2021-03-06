/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:09:47 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 22:28:44 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			check_overflow(t_piece *head, char **map, int x, int y)
{
	if ((head->x[0] + x + 1) > (int)ft_strlen(map[0]) ||
		(head->x[1] + x + 1) > (int)ft_strlen(map[0]) ||
		(head->x[2] + x + 1) > (int)ft_strlen(map[0]) ||
		(head->y[0] + y + 1) > (int)ft_strlen(map[0]) ||
		(head->y[1] + y + 1) > (int)ft_strlen(map[0]) ||
		(head->y[2] + y + 1) > (int)ft_strlen(map[0]))
		return (-1);
	else
		return (0);
}

int			check_negative(t_piece *head, char **map, int y)
{
	int x;

	x = 0;
	if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
	{
		while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 ||
					(head->x[2] + x) < 0) && map[y][x] != '\0')
			++x;
	}
	return (x);
}

int			place_first(t_piece *head, char **map, int x, int y)
{
	int hash;

	hash = 0;
	x = check_negative(head, map, y);
	if (check_overflow(head, map, x, y))
		return (-1);
	map[y][x] = head->letter;
	while (hash < 3)
	{
		if (map[head->y[hash] + y][head->x[hash] + x] == '.')
		{
			map[head->y[hash] + y][head->x[hash] + x] = head->letter;
			++hash;
		}
	}
	return (0);
}
