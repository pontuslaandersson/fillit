#include "fillit.h"

int		get_map_size(int newlines)
{
	int		n;
    int    sqr_size;

	n = ((newlines + 1) / 5) * 4;

    sqr_size = 2;
	while (sqr_size * sqr_size < n)
		sqr_size++;
	return (sqr_size);
}

char	**initialize_map(int newlines)
{
	char	**map;
	int		map_size;
	int 	i;
	
	i = 0;
	map_size = get_map_size(newlines);
	map = create_map(map_size);
	return (map);
}


