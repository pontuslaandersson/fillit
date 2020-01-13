#include "fillit.h"

char	**create_map(int n);

char	**initialize_map(int newlines)
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
	map = create_map(map_size);
	/*if (!(map[] = ft_strnew(5)))
			{
				display_error();
				exit (-1);
			}*/
			return (map);
}

int		main(void)
{
	char	**test_map;
	
	/*initialize_map(4);
	ft_putendl("");*/
	test_map = initialize_map(9);
	ft_putendl("");/*
	initialize_map(14);
	ft_putendl("");
	initialize_map(19);
	ft_putendl("");
	initialize_map(24);
	ft_putendl("");
	initialize_map(29);
	ft_putendl("");
	initialize_map(34);
	ft_putendl("");
	initialize_map(39);*/
}