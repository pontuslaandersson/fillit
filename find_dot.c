#include "fillit.h"

int		find_dot(t_piece *cursor, char **map, int x, int y, int placed)
{
	int ret;

	ret = 1;
	while (y < ft_strlen(map[0]) && ret != 0)
	{
		while (map[y][x] != '.' && map[y][x] != '\0')
			x++;
		if (map[y][x] == '.')
		{
			ret = check_candidate(cursor, map, x, y, placed);
			if (ret == -1)
				ret = find_dot(cursor, map, x + 1, y, placed);
		}
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		if (y == ft_strlen(map[0]) && map[y - 1][x] == '\0')
		{
			ft_putendl("Backtraaaaaack!");
			backtrack(cursor, map, placed);
		}
	}
	/*if (ret == 0)
		return (0);*/
	return (0);
}