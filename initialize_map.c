#include "fillit.h"

char	**create_map(int n);

void	initialize_map(int newlines) /* Should actually return char **. */
{
	char	**map;
	int		n;
	int		map_size;
	int 	i;
	
	i = 0;
	n = (newlines + 1) / 5;
	if (n == 1)
		map_size = 2;
	if (n == 2)
		map_size = 3;
	if (n == 3 || n == 4)
		map_size = 4;
	if (n == 5 || n == 6)
		map_size = 5;
	if (n >= 7 && n <= 9)
		map_size = 6;
	if (n >= 10 && n <= 12)
		map_size = 7;
	if (n >= 13 && n <= 16)
		map_size = 8;
	if (n >= 17 && n <= 20)
		map_size = 9;
	if (n >= 21 && n <= 25)
		map_size = 10;
	if (n == 26)
		map_size = 11;
	map = create_map(n);
	/*if (!(map[] = ft_strnew(5)))
			{
				display_error();
				exit (-1);
			}*/
}

int		main(void)
{
	initialize_map(4);
	/*initialize_map(9);
	initialize_map(14);
	initialize_map(19);
	initialize_map(24);
	initialize_map(29);
	initialize_map(34);
	initialize_map(39);*/
}