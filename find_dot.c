#include "fillit.h"

int		find_dot(t_piece *cursor, char **map, int x, int y, int piece)
{
	int ret;

	ret = 1;
	while (y < ft_strlen(map[0]) && ret != 0)
	{
		while (map[y][x] != '.' && map[y][x] != '\0')
			x++;
		if (map[y][x] == '.')
		{
			ret = check_candidate(cursor, map, x, y, piece);
			if (ret == -1)
				ret = find_dot(cursor, map, x + 1, y, piece);
		}
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	if (ret == 0)
		return (0);
	else
	{
		ft_putendl("We ran out of map.");
		exit (-1);
	}
}