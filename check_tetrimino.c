/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 12:14:43 by panderss          #+#    #+#             */
/*   Updated: 2019/12/16 16:33:07 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DOES NOT WORK! */

int		check_tetrimino(char **tetri)
{
	int i;
	int j;
	int	hash;

	j = 0;
	i = 0;
	hash = 0;
	while (j < 4)
	{
		while (tetri[j][i] != '\0')
		{
			if (tetri[j][i] != '.' || tetri[j][i] != '#')
			{
				return (-1);
			}
			else if (tetri[j][i] == '#')
				hash++;
			++i;
		}
		i = 0;
		++j;
	}
	if (hash != 4)
		return (-1);
	return (0);
}
