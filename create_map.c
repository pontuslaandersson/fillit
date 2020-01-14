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
		ft_putendl("Creating line.");
		if (!(map[y] = ft_strnew(n + 1)))
		{
			display_error();
			exit (-1);
		}
		++y;
	}
	y = 0;
	while (y < n)
	{
		ft_putendl("* Filling line with dots...");
		x = 0;
		map[y] = (char*)malloc((sizeof(char) * n) + 1);
		while (x < n)
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
	ft_putendl("Returning map...");
	return (map);
}
