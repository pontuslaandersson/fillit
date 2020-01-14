#include "fillit.h"

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
	return (map);
}

/*int		main(void)
{
	char	**test_map;
	
	ft_putendl("Map size 1: 2");
	test_map = initialize_map(4);
	ft_putendl("");
	ft_putendl("Map size 2: 3");
	test_map = initialize_map(9);
	ft_putendl("");
	ft_putendl("Map size 3: 4");
	test_map = initialize_map(14);
	ft_putendl("");
	ft_putendl("Map size 4: 4");
	test_map = initialize_map(19);
	ft_putendl("");
	ft_putendl("Map size 5: 5");
	test_map = initialize_map(24);
	ft_putendl("");
	ft_putendl("Map size 6: 5");
	test_map = initialize_map(29);
	ft_putendl("");
	ft_putendl("Map size 7: 6");
	test_map = initialize_map(34);
	ft_putendl("");
	ft_putendl("Map size 8: 6");
	test_map = initialize_map(39);
	ft_putendl("Map size 9: 6");
	test_map = initialize_map(44);
	ft_putendl("");
	ft_putendl("Map size 10: 7");
	test_map = initialize_map(49);
	ft_putendl("");
	ft_putendl("Map size 11: 7");
	test_map = initialize_map(54);
	ft_putendl("");
	ft_putendl("Map size 12: 6");
	test_map = initialize_map(59);
	ft_putendl("");
	ft_putendl("Map size 13: 8");
	test_map = initialize_map(64);
	ft_putendl("");
	ft_putendl("Map size 14: 8");
	test_map = initialize_map(69);
	ft_putendl("");
	ft_putendl("Map size 15: 8");
	test_map = initialize_map(74);
	ft_putendl("");
	ft_putendl("Map size 16: 8");
	test_map = initialize_map(79);
	ft_putendl("");
	ft_putendl("Map size 17: 9");
	test_map = initialize_map(84);
	ft_putendl("");
	ft_putendl("Map size 18: 9");
	test_map = initialize_map(89);
	ft_putendl("");
	ft_putendl("Map size 19: 9");
	test_map = initialize_map(94);
	ft_putendl("");
	ft_putendl("Map size 20: 9");
	test_map = initialize_map(99);
	ft_putendl("");
	ft_putendl("Map size 21: 10");
	test_map = initialize_map(104);
	ft_putendl("");
	ft_putendl("Map size 22: 10");
	test_map = initialize_map(109);
	ft_putendl("");
	ft_putendl("Map size 23: 10");
	test_map = initialize_map(114);
	ft_putendl("");
	ft_putendl("Map size 24: 10");
	test_map = initialize_map(119);
	ft_putendl("");
	ft_putendl("Map size 25: 10");
	test_map = initialize_map(124);
	ft_putendl("");
	ft_putendl("Map size 26: 11");
	test_map = initialize_map(129);
	ft_putendl("");
	ft_putendl("");
	return (0);
}*/