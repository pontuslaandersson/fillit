#include "fillit.h"

void       free_array(char **grid)
{
	int     i;

	i = 0;
	if (grid != NULL)
	{
		while (i < 4)
		{
			ft_strdel(&grid[i]);
			++i;
		}
	}
}
