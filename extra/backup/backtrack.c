#include "fillit.h"

/* Deprecated backtrack function. */

void			backtrack(t_piece *cursor, char **map, int placed)
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
	ft_putendl("In backtrack function.");
	ft_putstr("Cursor set to ");
    ft_putchar(65 + placed);
	ft_putchar('\n');
	cursor = cursor->prev;
	placed--;
	ft_putstr("Removing piece ");
    ft_putchar(65 + placed);
	ft_putchar('\n');
	while (j < ft_strlen(map[0]))
	{
		ft_putendl("In first while.");
		while (map[j][i] != '\0')
		{
			ft_putendl("In second while.");
			if (map[j][i] == 65 + placed)
			{
				ft_putendl("Hit if; character of previous piece replaced.");
				map[j][i] = '.';
				if (replaced == 0)
				{
					ft_putendl("Hit if; replaced character was first character.");
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
	ft_putstr("Attempting to re-place piece ");
    ft_putchar(65 + placed);
	ft_putchar('\n');
	find_dot(cursor, map, (x + 1), y, placed);
}
