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
	/*ft_putendl("In backtrack function.");
	ft_putstr("Removing piece ");
    ft_putchar(cursor->letter);
	ft_putchar('\n');*/
	while (j < ft_strlen(map[0]) && replaced < 4)
	{
		/*ft_putendl("In first while.");*/
		while (map[j][i] != '\0')
		{
			/*ft_putendl("In second while.");*/
			if (map[j][i] == cursor->letter)
			{
				/*ft_putendl("Hit if; character of previous piece replaced.");*/
				map[j][i] = '.';
				if (replaced == 0)
				{
					/*ft_putendl("Hit if; replaced character was first character.");*/
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
		/*if (cursor->letter == 'I')
		{
			print_map(map);
			while (1)
			{

			}
		}*/
		ret = find_dot(cursor, map, x, y);
		if (ret == -1 && cursor->prev != NULL)
		{
			cursor = cursor->prev; /* Move cursor back one step to previous piece. */
			/*if(cursor->letter == 'D')
			{
				ft_putchar(cursor->letter);
				ft_putchar('\n');
				print_map(map);
				}*/
			n = backtrack(cursor, map); /* Should return the offset between original position and the next try; should be +1. */
			x = n % ft_strlen(map[0]);
			y = n / ft_strlen(map[0]);
			/*++x;*/
			ret = find_dot(cursor, map, x, y); /* increment placement of said previous piece */
			
		}
		if (ret == 0)
		{
			cursor = cursor->next;  /*Only if piece is successfully placed. */
			y = 0;
			x = 0;
		}
		if (ret == -1 && (cursor == NULL || cursor->prev == NULL))
			return (-1);
	}
	return (0);
}
