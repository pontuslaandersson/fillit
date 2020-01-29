/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amchakra <amchakra@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:17:12 by amchakra          #+#    #+#             */
/*   Updated: 2020/01/29 15:17:13 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int n)
{
	char	**map;
	char	**tmp;
	int		x;
	int		y;

	tmp = (char**)malloc(sizeof(char*) * n);
	y = 0;
	while (y < n)
	{
		if (!(tmp[y] = ft_strnew(n)))
		{
			display_error();
			exit(-1);
		}
		x = 0;
		while (x < n)
		{
			tmp[y][x] = '.';
			x++;
		}
		y++;
	}
	map = tmp;
	return (map);
}
