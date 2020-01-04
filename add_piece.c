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

void	add_piece(t_piece **alst, t_piece *new)
{
	if (alst != NULL && new != NULL)
	{
		ft_putendl("Adding node.");
		new->next = *alst;
		*alst = new;
	}
}
