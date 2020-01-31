/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:03:04 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 22:23:12 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Re-initializes map at size + 1 when and if solve_map realises it needs a
** bigger map.
*/

char		**reinitialize_map(char **map)
{
	int n;

	n = ft_strlen(map[0]);
	free_map(map);
	map = create_map(n + 1);
	return (map);
}

/*
** Prints the map once solve_map is complete.
*/

void		print_map(char **map)
{
	size_t				line;

	line = 0;
	while (line < ft_strlen(map[0]))
	{
		ft_putendl(map[line]);
		++line;
	}
	free_map(map);
}

/*
** Frees the map when it is no longer used.
*/

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
	free(map);
}

/*
** Finds the initial size of the map using the number of tetros and
** using the idea that the the smallest tetro needs a 2x2 square
*/

char		**initialize_map(int newlines)
{
	char			**map;
	int				sqr_size;

	sqr_size = 2;
	while (sqr_size * sqr_size < ((newlines + 1) / 5) * 4)
		sqr_size++;
	map = create_map(sqr_size);
	return (map);
}

/*
** Initializes the map, places the first tetro, and then calls
** solve_map to solve the smallest square, re-sizes the map if
** solve_map returns -1, and prints the map upon solve_map
** returning 0.
*/

void		solve(t_piece *head, int newlines)
{
	static char		**map;
	int				ret;
	t_piece			*cursor;

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
