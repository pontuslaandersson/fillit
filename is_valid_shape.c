/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amchakra <amchakra@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 16:15:16 by amchakra          #+#    #+#             */
/*   Updated: 2019/12/21 16:52:41 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Testing whether the tertromino is valid by checking if there is a connection 
** between #  and # above, to the right, below and to the left. If the total 
** count is 6 or 8, then the shape is valid.  
*/

int		is_valid_shape(char *tetro)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i <= 19)
	{
		if (tetro[i] == '#')
		{
			if (i >= 5 && tetro[i - 5] == '#')
				j++;
			if (i <= 17 && tetro[i + 1] == '#')
				j++;
			if (i <= 13 && tetro[i + 5] == '#')
				j++;
			if (i >= 1 && tetro[i - 1] == '#')
				j++;
		}
		i++;
	}
	if (j == 6 || j == 8)
		return (1);
	return (0);
}
