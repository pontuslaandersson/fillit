#include "fillit.h"

int		find_dot(t_piece *cursor, char **map, int x, int y)
{
	int ret;

	ret = 1;
	while (y < ft_strlen(map[0]) && ret != 0)
	{
		/*while (map[y][x] != '.' && map[y][x] != '\0')*/
		if (map[y][x] == '.')
		{
			ret = check_candidate(cursor, map, x, y);
			if (ret == -1 && map[y][x + 1] != '\0' && map[y][x + 1] == '.')
				ret = check_candidate(cursor, map, x + 1, y);
		}
		x++;
		if (map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
	}
	/*if (cursor->next != NULL)
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
		}*/
	/*if (ret == 0)
		return (0);*/
	return (ret);
}