#include "libft.h"

int		check_hash(char **tetro)
{
	int i;
	int j;
	int	hash;

	j = 0;
	i = 0;
	hash = 0;
	while (j < 4)
	{
		while (tetro[j][i] != '\0')
		{
			if (tetro[j][i] == '#')
				hash++;
			++i;
		}
		i = 0;
		++j;
	}
	return (hash);
}

int		check_dot(char **tetro)
{
	int i;
	int j;
	int	dot;

	j = 0;
	i = 0;
	dot = 0;
	while (j < 4)
	{
		while (tetro[j][i] != '\0')
		{
			if (tetro[j][i] == '.')
				dot++;
			++i;
		}
		i = 0;
		++j;
	}
	return (dot);
}

int		check_total(char **tetro)
{
	int i;
	int j;
	int	total;

	j = 0;
	i = 0;
	total = 0;
	while (j < 4)
	{
		while (tetro[j][i] != '\0')
		{
			++total;
			++i;
		}
		i = 0;
		++j;
	}
	return (total);
}

int		check_tetromino(char *tetro)
{
	int	hash;
	int dot;
	int	total;

	hash = check_hash(tetro);
	dot = check_dot(tetro);
	total = check_total(tetro);
	if (hash != 4 || dot != 12 || total != 19)
	{
		return (-1);
	}
	return (0);
}
