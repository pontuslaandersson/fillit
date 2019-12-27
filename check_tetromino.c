/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetromino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panderss <panderss@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 13:22:15 by panderss          #+#    #+#             */
/*   Updated: 2019/12/27 15:28:52 by panderss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		is_valid_shape(char *file)
{
	int		i;
	int		j;
	int		k;
	int		c;

	i = 0;
	j = 0;
	while (file[c] != '\0')
	{
		while (i <= 19)
		{
			if (file[i] == '#')
			{
				if (i >= 5 && file[i - 5] == '#')
					j++;
				if (i <= 17 && file[i + 1] == '#')
					j++;
				if (i <= 13 && file[i + 5] == '#')
					j++;
				if (i >= 1 && file[i - 1] == '#')
					j++;
		}
		i++;
		c++;
		if (c % 21 == 0)
		{
			if (j != 6 && j != 8)
				return (-1);
			j = 0;
			i = 0;
		}
		}
	}
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
		{
         	ft_putendl("Character error.");
		 	return (-1);
		}
        ++i;
    }
    if ((newline - 4) % 5 != 0 || (i - 20) % 21 != 0)
	{
		ft_putendl("Error: Programmer sucks at math.");
        return (-1);
	}
    else
        return ((i - 20) / 21);
}

int		check_hash(char *file)
{
	int i;
	int	hash;
	
	i = 0;
	hash = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '#')
			hash++;
		++i;
	}
	if (hash % 4 != 0)
	{
		display_error();
		return (-1);
	}
	return (0);
}

int		check_dot(char *file)
{
	int i;
	int	dot;
	
	i = 0;
	dot = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '.')
			dot++;
		++i;
	}
	if (dot % 12 != 0)
	{
		display_error();
		return (-1);
	}
	return (0);
}

int		check_newlines(char *file)
{
	int i;
	int	newline;
	
	i = 0;
	newline = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			newline++;
		++i;
	}
	if ((newline - 4) % 5 != 0)
	{
		display_error();
		return (-1);
	}
	return (0);
}

int		check_tetrominos(char *file)
{
	int	hash;
	int dot;
	int	total;
	int tetros;

	if ((tetros = check_file(file)) <= 0)
	{
		ft_putendl("Check_file function non-functional; least function of them all.");
		display_error();
		return (-1);
	}
	if (check_hash(file) != 0 || check_dot(file) != 0 || check_newlines(file) != 0 
			|| is_valid_shape(file) != 0)
	{
		ft_putendl("Validation failed!");
		display_error();
		return (-1);
	}
	return (0);
}
