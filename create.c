/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:08:25 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 16:20:21 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*create(int *x, int *y, t_piece *prev)
{
	int			len;
	t_piece		*new_node;

	new_node = (t_piece*)malloc(sizeof(t_piece));
	if (new_node == NULL)
	{
		return (NULL);
	}
	len = 0;
	while (len < 3)
	{
		new_node->x[len] = x[len];
		new_node->y[len] = y[len];
		++len;
	}
	new_node->prev = prev;
	new_node->next = NULL;
	return (new_node);
}
