/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amchakra <amchakra@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 21:48:59 by amchakra          #+#    #+#             */
/*   Updated: 2020/01/08 21:49:03 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		map_size(int newlines)
{
	int		n;
    int    sqr_size;

	n = ((newlines + 1) / 5) * 4;

    sqr_size = 2;
	while (sqr_size * sqr_size < n)
		sqr_size++;
	return (sqr_size);
}

int		main(void)
{
	int nb;

	nb = map_size (4);
	printf("%d\n", nb);
	nb = map_size (9);
	printf("%d\n", nb);
	nb = map_size (14);
	printf("%d\n", nb);
	nb = map_size (19);
	printf("%d\n", nb);
	nb = map_size (24);
	printf("%d\n", nb);
	nb = map_size (29);
	printf("%d\n", nb);
	nb = map_size (34);
	printf("%d\n", nb);
	nb = map_size (39);
	printf("%d\n", nb);
	nb = map_size (44);
	printf("%d\n", nb);
	nb = map_size (49);
	printf("%d\n", nb);
	nb = map_size (54);
	printf("%d\n", nb);
	nb = map_size (59);
	printf("%d\n", nb);
	nb = map_size (64);
	printf("%d\n", nb);
	nb = map_size (69);
	printf("%d\n", nb);
	nb = map_size (74);
	printf("%d\n", nb);
	nb = map_size (79);
	printf("%d\n", nb);
	nb = map_size (84);
	printf("%d\n", nb);
	nb = map_size (89);
	printf("%d\n", nb);
}
