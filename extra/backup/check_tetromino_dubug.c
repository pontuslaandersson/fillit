/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetromino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:14:43 by panderss          #+#    #+#             */
/*   Updated: 2019/12/17 14:50:25 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	count_characters()*/

int		check_tetromino(char **tetro)
{
	int i;
	int j;
	int	hash;
	int dot;
	int	total;

	j = 0;
	i = 0;
	hash = 0;
	dot = 0;
	total = 0;
	while (j < 4)
	{
		while (tetro[j][i] != '\0')
		{
			/*if (tetro[j][i] != '.' && tetro[j][i] != '#')
			{
				ft_putstr("Non-legal character found: ");
				ft_putendl(&tetro[j][i]);
				return (-1);
			}*/
			if (tetro[j][i] == '#')
				hash++;
			if (tetro[j][i] == '.')
				dot++;
			total++;
			++i;
		}
		i = 0;
		++j;
	}
	if (hash != 4 || dot != 12 || total != 16)
	{
		ft_putnbr(hash);
		ft_putendl("");
		ft_putnbr(dot);
		ft_putendl("");
		ft_putnbr(total);
		ft_putendl("");
		ft_putendl("Incorrect number of blocks, dots, or total found.");
		return (-1);
	}
	return (0);
}
