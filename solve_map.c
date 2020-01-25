#include "fillit.h"

int			backtrack(t_piece *cursor, char **map)
{
	int i;
	int j;
	int x;
	int y;
	int replaced;

	j = 0;
	i = 0;
	x = 0;
	y = 0;
	replaced = 0;
	while (j < ft_strlen(map[0]) && replaced < 4)
	{
		while (map[j][i] != '\0')
		{
			if (map[j][i] == cursor->letter)
			{
				map[j][i] = '.';
				if (replaced == 0)
				{
					x = i;
					y = j;
				}
				++replaced;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (y*ft_strlen(map[0]) + x + 1);
}

int			solve_map(t_piece *head, char **map)
{
	t_piece 	*cursor;
	int			ret;
	int			n;
	int			x;
	int			y;

	cursor = head->next;
	x = 0;
	y = 0;
	while (cursor != NULL)
	{
		ret = find_dot(cursor, map, x, y);
		if (ret == -1 && cursor->prev != NULL)
		{
			cursor = cursor->prev;
			n = backtrack(cursor, map);
			x = n % ft_strlen(map[0]);
			y = n / ft_strlen(map[0]);
			ret = find_dot(cursor, map, x, y);
			
		}
		if (ret == 0)
		{
			cursor = cursor->next;
			y = 0;
			x = 0;
		}
		if (ret == -1 && (cursor == NULL || cursor->prev == NULL))
			return (-1);
	}
	return (0);
}
