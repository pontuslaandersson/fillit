/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 16:24:44 by panderss          #+#    #+#             */
/*   Updated: 2020/01/04 16:53:39 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_piece     *create(int *x, int *y, t_piece* next);

t_piece		*add_piece(t_piece *ret, int *x, int *y)
{
    /* go to the last node */
    t_piece *cursor = ret;
    while(cursor->next != NULL)
        cursor = cursor->next;
 
    /* create a new node */
    t_piece	*new_node =  create(x, y, NULL);
	new_node->prev = cursor;
    cursor->next = new_node;
 
    return (ret);
}

/*void	add_piece(t_piece **alst, t_piece *new)
{
	if (alst != NULL && new != NULL)
	{
		ft_putendl("Adding node.");
		new->next = *alst;
		*alst = new;
	}
}*/
