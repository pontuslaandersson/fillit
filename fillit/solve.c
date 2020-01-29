/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:03:04 by panderss          #+#    #+#             */
/*   Updated: 2020/01/28 19:42:16 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**reinitialize_map(char **map)
{
	int n;

	n = ft_strlen(map[0]);
	free_map(map);
	map = create_map(n + 1);
	return (map);
}

void		print_map(char **map)
{
	int				line;

	line = 0;
	while (line < ft_strlen(map[0]))
	{
		ft_putendl(map[line]);
		++line;
	}
	free_map(map);
}

void		free_map(char **map)
{
	int				i;
	int				limit;

	i = 0;
	limit = ft_strlen(map[0]);
	if (map != NULL)
	{
		while (i < limit)
		{
			ft_strdel(&map[i]);
			++i;
		}
	}
}

/*
** Find the initial size of the map using the number of tetros and
** using the idea that the the smallest tetro needs a 2x2 square
*/

char		**initialize_map(int newlines)
{
	char			**map;
	int				map_size;
	int				sqr_size;

	sqr_size = 2;
	while (sqr_size * sqr_size < ((newlines + 1) / 5) * 4)
		sqr_size++;
	map = create_map(sqr_size);
	return (map);
}

void		solve(t_piece *head, int newlines, int max)
{
	static char		**map;
	int				ret;
	t_piece			*cursor;
	int				n;

	map = initialize_map(newlines);
	ret = place_first(head, map, 0, 0);
	while (ret == -1)
	{
		map = reinitialize_map(map);
		ret = place_first(head, map, 0, 0);
	}
	cursor = head->next;
	while (solve_map(cursor, map, 0, 0) == -1)
	{
		map = reinitialize_map(map);
		ret = place_first(head, map, 0, 0);
	}
	if (ret == 0)
	{
		print_map(map);
		exit(0);
	}
}
