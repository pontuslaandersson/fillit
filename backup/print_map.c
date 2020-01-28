#include "fillit.h"

void	print_map(char **map)
{
	int	line;

	line = 0;
	while (line < ft_strlen(map[0]))
	{
		ft_putendl(map[line]);
		++line;
	}
}
