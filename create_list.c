/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 12:19:05 by panderss          #+#    #+#             */
/*   Updated: 2020/01/04 14:36:11 by panderss         ###   ########.fr       */
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
		return (NULL);
	/*if (content == NULL)
	{
		new->content = NULL;
	}*/
	else
	{
		/*new->x = (int*)malloc(sizeof(size_t));*/
		/*if (new->x == NULL)
		{
			free(new);
			return (NULL);
		}*/
		len = 0;
		while (len < 3)
		{
			new->x[len] = x[len];
			++len;
		}
        /*new->y = (int*)malloc(sizeof(size_t));*/
	/*	if (new->x == NULL)
		{
			free(new);
			return (NULL);
		}*/
		len = 0;
		while (len < 3)
		{
			new->y[len] = y[len];
			++len;
		}		/*	if (new->y == NULL)
		{
			free(new);
			return (NULL);
		}*/	
	}
	new->next = NULL;
	return (new);
}
