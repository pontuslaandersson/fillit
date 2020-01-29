/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:19:05 by panderss          #+#    #+#             */
/*   Updated: 2020/01/29 16:27:22 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*create_list(int *x, int *y)
{
	t_piece	*new;
	int		len;

	if (!(new = (t_piece*)ft_memalloc(sizeof(t_piece))))
		display_error();
	else
	{
		len = 0;
		while (len < 3)
		{
			new->x[len] = x[len];
			new->y[len] = y[len];
			++len;
		}
		new->letter = 'A';
	}
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
