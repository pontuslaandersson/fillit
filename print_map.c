#include "fillit.h"

void	print_map(char **map)
{
	int	line;

	line = 0;
	while (**map)
	{
		ft_putstr(*map[line]);
	}
}