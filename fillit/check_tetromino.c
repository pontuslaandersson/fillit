/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetromino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amchakra <amchakra@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 15:44:55 by amchakra          #+#    #+#             */
/*   Updated: 2020/01/27 20:10:31 by amchakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Checks inside the tetro piece if the dots, hashes and new lines are in the
** correct places
*/

int	check_format(char *file, int c)
{
	int i;

	i = 0;
	while (i++ < 19)
	{
		if ((i % 5 < 4 && file[i] != '.' && file[i] != '#') ||
			((i % 5 == 4) && file[i] != '\n'))
			return (-1);
	}
	return (0);
}

/*
** Checks whether the shape of the tetro is correct. There are 6 contacts
** between all the tetromino hashes, except in case of a square, when there
** are contacts.
*/

int	check_shape(char *file, int c)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i <= 19)
	{
		if (file[c + i] == '#')
		{
			if (i >= 5 && file[c + i - 5] == '#')
				j++;
			if (i <= 17 && file[c + i + 1] == '#')
				j++;
			if (i <= 13 && file[c + i + 5] == '#')
				j++;
			if (i >= 1 && file[c + i - 1] == '#')
				j++;
		}
		i++;
	}
	if (j != 6 && j != 8)
		return (-1);
	return (0);
}

/*
** Checks whether in each 21 (20 if at the end) characters,
** the tetrominos have the correct grid and shape.
*/

int	check_tetro(char *file)
{
	int	i;
	int	newline;

	i = 0;
	newline = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
			++newline;
		++i;
		if (newline == 5)
		{
			if ((check_shape(file, (i - 21)) != 0) ||
				(check_format(file, (i - 21)) != 0))
				return (-1);
			newline = 0;
		}
	}
	if ((check_shape(file, (i - 20)) != 0) ||
		(check_format(file, (i - 20)) != 0))
		return (-1);
	return (0);
}

/*
** checks for:
** - that correct characters are present,
** - correct number of lines,
** - correct number of tetro blocks
** - the size of the file is for no more than 26 tetros, i.e. 545 characters
*/

int	check_file(char *file)
{
	int i;
	int	hash;
	int dot;
	int newline;

	i = 0;
	hash = 0;
	dot = 0;
	newline = 0;
	while (file[i] != '\0')
	{
		if (file[i] == '#')
			hash++;
		if (file[i] == '.')
			dot++;
		if (file[i] == '\n')
			newline++;
		i++;
	}
	if ((hash % 4 != 0) || (dot % 12 != 0) ||
		((newline - 4) % 5 != 0 ||
		(i - 20) % 21 != 0 || i > 545))
		return (-1);
	return (newline);
}

/*
** Checks if the file contains tetrominos and returns the number
** of lines.
*/

int	check_tetrominos(char *file)
{
	int	total;

	if ((total = check_file(file)) < 0 || (check_tetro(file) != 0))
		return (-1);
	return (total);
}
