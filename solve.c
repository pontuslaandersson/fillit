#include "fillit.h"

void		print_map(char **map)
{
	int				line;

	line = 0;
	while (line < ft_strlen(map[0]))
	{
		ft_putendl(map[line]);
		++line;
	}
	free_map(map);
}

void		free_map(char **map)
{
	int				i;
	int				limit;

	i = 0;
	limit = ft_strlen(map[0]);
	if (map != NULL)
	{
		while (i < limit)
		{
			ft_strdel(&map[i]);
			++i;
		}
	}
}

void		solve(t_piece *head, int newlines, int max)
{
	static char		**map;
	int				ret;
	static int		solved;
	t_piece			*cursor;
	int				n;

	solved = 0;
	map = initialize_map(newlines);
	ret = place_first(head, map);
	while (ret == -1)
	{
		free_map(map);
		newlines = newlines + 5;
		map = initialize_map(newlines);
		ret = place_first(head, map);
	}
	while (solve_map(head, map) == -1)
	{
		n = ft_strlen(map[0]);
		free_map(map);
		map = create_map(n + 1);
		ret = place_first(head, map);
	}
	if (ret != -1)
		solved = 1;
	if (ret == 0)
	{
		print_map(map);
		exit(0);
	}
}
