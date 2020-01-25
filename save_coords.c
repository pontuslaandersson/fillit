#include "fillit.h"

t_piece		*save_coords(char **grid, int j, int i)
{
	int count;
	int start_x;
	int start_y;
	int x[3];
	int y[3];

	start_x = i;
	start_y = j;
	count = 0;
	++i;
	while (count < 3 && j < 4)
	{
		while (grid[j][i] != '\0' && count < 3)
		{
			if (grid[j][i] == '#')
			{
				x[count] = (i - start_x);
				y[count] = (j - start_y);
				++count;
			}
			++i;
		}
		i = 0;
		++j;
	}
	return (start_list(x, y));
}