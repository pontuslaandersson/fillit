/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:19:05 by panderss          #+#    #+#             */
/*   Updated: 2020/01/22 18:18:36 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_piece		*create_list(int *x, int *y)
{
	t_piece	*new;
	int		len;

	new = (t_piece*)ft_memalloc(sizeof(t_piece));
	if (new == NULL)
	{
		ft_putendl("Error creating node.");
		return (NULL);
	}
	else
	{
			len = 0;
		while (len < 3)
		{
			new->x[len] = x[len];
			++len;
		}
    		len = 0;
		while (len < 3)
		{
			new->y[len] = y[len];
			++len;
		}
		new->letter = 'A';
	}
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
