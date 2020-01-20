#include "fillit.h"

int		find_dot(t_piece *cursor, char **map, int x, int y, int placed)
{
	int ret;

	ret = 1;
	/*ft_putendl("Debug 1");*/
	while (y < ft_strlen(map[0]) && ret != 0)
	{
		/*ft_putendl("Debug 2");*/
		while (map[y][x] != '.' && map[y][x] != '\0')
			x++;
		if (map[y][x] == '.')
		{
			/*ft_putendl("Debug 3");*/
			ret = check_candidate(cursor, map, x, y, placed);
			if (ret == -1)
				ret = find_dot(cursor, map, x + 1, y, placed);
		}
		if (map[y][x] == '\0')
		{
			/*ft_putendl("Debug 4");*/
			x = 0;
			y++;
		}
		/*if (y == ft_strlen(map[0]) && map[y - 1][x] == '\0')
		{
			ft_putendl("Backtraaaaaack!");
			backtrack(cursor, map, placed);
		}*/
	}
	if (cursor->next != NULL)
		{
			cursor = cursor->next;
			placed++;
			ft_putstr("Recursively calling find_dot from find_dot with piece ");
			ft_putchar(65 + placed);
            ft_putchar('\n');
			x = 0;
			y = 0;
			while (ret != 0)
				ret = find_dot(cursor, map, x, y, placed);
		}
	/*if (ret == 0)
		return (0);*/
	return (ret);
}