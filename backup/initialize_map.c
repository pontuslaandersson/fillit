/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amchakra <amchakra@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:07:15 by amchakra          #+#    #+#             */
/*   Updated: 2020/01/28 19:39:32 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**initialize_map(int newlines)
{
	char	**map;
	int		map_size;
	int		sqr_size;

	sqr_size = 2;
	while (sqr_size * sqr_size < ((newlines + 1) / 5) * 4)
		sqr_size++;
	map = create_map(sqr_size);

	return (map);
}
