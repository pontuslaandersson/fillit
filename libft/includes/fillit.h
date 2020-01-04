/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 13:32:32 by panderss          #+#    #+#             */
/*   Updated: 2020/01/04 13:32:38 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef	struct		s_piece
{
	int				x[3];
	int				y[3];
	char			letter;
	struct s_piece	*next;
}					t_piece;

void	display_error(void);

#endif
