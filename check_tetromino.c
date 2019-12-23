/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetromino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:15 by panderss          #+#    #+#             */
/*   Updated: 2019/12/23 15:29:09 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int     check_file(char *file)
{
    int i;
    int newline;

    while (file[i] != '\0')
    {
      if (file[i] == '\n')
            ++newline;
        if (file[i] != '\n' && file[i] != '.' && file[i] != '#')
            return (-1);
        ++i;
    }
    if ((newline - 4) % 5 != 0 || (i - 20) % 21 != 0)
        return (-1);
    else
        return (0);
}

int		check_hash(char *tetro)
{
	int i;
	int	hash;
	
	i = 0;
	hash = 0;
	while (tetro[i] != '\0')
	{
		if (tetro[i] == '#')
			hash++;
		++i;
	}
	return (hash);
}

int		check_dot(char *tetro)
{
	int i;
	int	dot;
	
	i = 0;
	dot = 0;
	while (tetro[i] != '\0')
	{
		if (tetro[i] == '.')
			dot++;
		++i;
	}	
	return (dot);
}

int		check_newlines(char *tetro)
{
	if (tetro[4] != '\n' || tetro[9] != '\n' || tetro[14] != '\n' ||
		   tetro[19] != '\n' || tetro[20] != '\n')
	{
		ft_putendl("Wrong number of newlines detected.");
		return (-1);
	}
	return (0);
}

int		check_tetrominos(char *file)
{
	int	hash;
	int dot;
	int	total;

	if (check_file != 0)
	{
		display_error();
		return (-1);
	}
	hash = check_hash(tetro);
	dot = check_dot(tetro);
	total = ft_strlen(tetro);
	if (hash != 4 || dot != 12 || total != 22 
		|| check_newlines(tetro) != 0 || is_valid_shape(tetro) == 0)
	{
		ft_putnbr(is_valid_shape(tetro));
		ft_putendl("");
		ft_putnbr(hash);
		ft_putendl("");
		ft_putnbr(dot);
		ft_putendl("");
		ft_putnbr(total);
		ft_putendl("");
		return (-1);
	}
	ft_putnbr(hash);
	ft_putendl("");
	ft_putnbr(dot);
	ft_putendl("");
	ft_putnbr(total);
	ft_putendl("");
	return (0);
}
