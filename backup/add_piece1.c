/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:24:44 by panderss          #+#    #+#             */
/*   Updated: 2020/01/25 12:00:46 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*add_piece(t_piece *ret, int *x, int *y, int n)
{
	t_piece *cursor = ret;

	while (cursor->next != NULL)
		cursor = cursor->next;
	t_piece	*new_node =  create(x, y, cursor, NULL, n);
	cursor->next = new_node;

	return (ret);
}
