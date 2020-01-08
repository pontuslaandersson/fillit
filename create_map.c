#include "fillit.h"

char	**create_map(int n)
{
	char	**map;
	int		y;	
	int		x;

	map = (char**)malloc(sizeof(char*) * n);
	y = 0;
	while (y < n)
	{
		if (!(map[y] = ft_strnew(n + 1)))
		{
			display_error();
			exit (-1);
		}
		y++;
	}
	x = 0;
	y = 0;
	while (y < n)
	{
		ft_putendl("* Filling line with dots...");
		while (map[y][x] != '\0')
		{
			map[y][x] = '.';
			x++;
		}
		y++;
	}
	x = 0;
	y = 0;
	while (y < n)
	{
		ft_putendl("* Printing a line in array...");
		ft_putendl(map[y]);
		y++;
	}
	return (map);
}
