#include "fillit.h"

char	**create_map(int n)
{
	char	**map;
	char	**tmp;
	int		y;	
	int		x;

	tmp = (char**)malloc(sizeof(char*) * n);
	y = 0;
	while (y < n)
	{
		if (!(tmp[y] = ft_strnew(n)))
		{
			display_error();
			exit (-1);
		}
		++y;
	}
	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			tmp[y][x] = '.';
			x++;
		}
		y++;
	}
	map = tmp;
	return (map);
}
