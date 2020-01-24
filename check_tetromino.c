#include "libft.h"
#include "fillit.h"

int	check_format(char *file, int c)
{
	int i;
	i = 0;
	while (i++ < 19)
	{
		if (i % 5 < 4 && file[i] != '.' && file[i] != '#')
			return (-1);
		if ((i % 5 == 4) && file[i] != '\n')
			return (-1);
	}
	return (0);
}

int	is_valid_format(char *file)
{
	int	c;
	int	newline;
	c = 0;
	newline = 0;
	while (file[c] != '\0')
	{
		if (file[c] == '\n')
			++newline;
		++c;
		if (newline == 5)
		{
 /*			ft_putstr("Entering shape validation at c index: ");
			ft_putnbr(c);
			ft_putendl("");
			ft_putendl("* Checking format."); */
			if (check_format(file, (c - 21)) != 0)
			{
/*				ft_putendl("Invalid format detected!"); */
				return (-1);
			}
			newline = 0;
		}
	}
/*	ft_putendl("* Checking format one last time!"); */
	if (check_format(file, (c - 20)) != 0)
	{
/*		ft_putendl("Invalid format detected on last block!"); */
		return (-1);
	}
/*	ft_putendl("Is_valid_format checker OK. We're in good *format*!"); */
	return (0);
}
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

	int	is_valid_shape(char *file)
	{
		int	c;
		int	newline;

		c = 0;
		newline = 0;
		while (file[c] != '\0')
		{
			if (file[c] == '\n')
				++newline;
			++c;
			if (newline == 5)
			{
/*				ft_putstr("Entering shape validation at c index: ");
				ft_putnbr(c);
				ft_putendl("");
				ft_putendl("* Checking shape."); */
				if (check_shape(file, (c - 21)) != 0)
				{
/*					ft_putendl("Invalid shape detected!"); */
					return (-1);
				}
				newline = 0;
			}
		}
/*		ft_putendl("* Checking shape one last time!"); */
		if (check_shape(file, (c - 20)) != 0)
		{
/*			ft_putendl("Invalid shape detected on last block!"); */
			return (-1);
		}
/*		ft_putendl("Is_valid checker OK. We're in good *shape*!"); */
		return (0);
	}

/*
** checks for: 
** - that correct characters are present, 
** - correct number of lines, 
** - correct number of tetro blocks
** - the size of the file is for no more than 26 tetros, i.e. 545 characters
*/
	int     check_file(char *file)
	{
		int i;
		int newline;
		i = 0;
		newline = 0;
		while (file[i] != '\0')
		{
			if (file[i] == '\n')
				++newline;
			if (file[i] != '\n' && file[i] != '.' && file[i] != '#')
			{
/*				ft_putendl("Character error."); */
				return (-1);
			}
			++i;
		}
		if ((newline - 4) % 5 != 0 || (i - 20) % 21 != 0 || i > 545)
		{
/*			ft_putnbr(newline);
			ft_putendl("");
			ft_putnbr(i);
			ft_putendl("");
			ft_putendl("Error: Programmer sucks at math."); */
			return (-1);
		}
		else
			return (0);
	}
	int	check_hash(char *file)
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
/*		ft_putendl("Hash checker OK."); */
		return (0);
	}
	int	check_dot(char *file)
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
/*		ft_putendl("Dot checker OK."); */
		return (0);
	}
	int	check_newlines(char *file)
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
/*		ft_putendl("Newline checker OK."); */
		return (newline);
	}
/* Checks hashes, dots, newlines, shapes of entire file. */
int	check_tetrominos(char *file)
{
	int	hash;
	int dot;
	int	total;
	int tetros;

	if ((tetros = check_file(file)) < 0)
	{
/*		ft_putendl("Check_file function non-functional."); */
	display_error();
	return (-1);
	}
	if (check_hash(file) != 0 || check_dot(file) != 0 || 
		(total = check_newlines(file)) < 0 || is_valid_shape(file) != 0 ||
		is_valid_format(file) != 0)
	{
		return (-1);
	}
	return (total);
}
