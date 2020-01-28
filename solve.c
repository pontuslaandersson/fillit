/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:03:04 by panderss          #+#    #+#             */
/*   Updated: 2020/01/28 14:25:56 by panderss         ###   ########.fr       */
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
