/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:23:19 by panderss          #+#    #+#             */
/*   Updated: 2019/12/17 17:39:44 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	resolve_shape(char **tetro, int j, int i)
{
	if (j == 0)
	{
		if (i == 0)
		{
			/*check next three*/
		}
		if (i == 1)
		{
			/*check next two*/
		}
		if (i == 2)
		{
			/*check next one*/
		}
		if (i == 3)
		{
			/*check below*/
		}
	}
	if (j == 1)
	{
		if (i == 0)
		{
			/*check next three*/
		}
		if (i == 1)
		{
			/*check next two*/
		}
		if (i == 2)
		{
			/*check next one*/
		}
		if (i == 3)
		{
			/*check below*/
		}
	}
	
	if (j == 2)
	{
		if (i == 0)
		{
			/*check next three*/
		}
		if (i == 1)
		{
			/*check next two*/
		}
		if (i == 2)
		{
			/*check next one*/
		}
		if (i == 3)
		{
			/*check below*/
		}
	}
	
	if (j == 3)
	{
		if (i == 0)
		{
			/*return result*/
		}
	}
	
/*	if (tetro[j][i+1] == '#')*/
}

int			check_shape(char **tetro)
{
	int ret;
	int j;
	int i;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (tetro[j][i] != '\0')
		{
			if (tetro[j][i] == '#')
			{
				resolve_shape(tetro, j, i);
			}
			++i;
		}
		i = 0;
		++j;
	}
}
