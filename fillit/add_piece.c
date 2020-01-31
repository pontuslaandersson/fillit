/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:24:44 by panderss          #+#    #+#             */
/*   Updated: 2020/01/31 11:29:17 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Moves to the end of the linked list, creates a new node with our coordinates
** and returns the list.
*/

t_piece		*add_piece(t_piece *ret, int *x, int *y)
{
	t_piece *cursor;
	t_piece	*new_node;

	cursor = ret;
	while (cursor->next != NULL)
		cursor = cursor->next;
	new_node = create(x, y, cursor);
	cursor->next = new_node;
	return (ret);
}
