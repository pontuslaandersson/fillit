/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:24:44 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 16:20:22 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
