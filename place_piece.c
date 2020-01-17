#include "fillit.h"

void			backtrack(t_piece *cursor, char **map, int piece)
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
	cursor = cursor->prev;
	--piece;
	ft_putendl("In backtrack function.");
	while (j < ft_strlen(map[0]))
	{
		ft_putendl("In first while.");
		while (map[j][i] != '\0')
		{
			ft_putendl("In second while.");
			if (map[j][i] == 65 + piece)
			{
				ft_putendl("Hit if; character of previous piece replaced.");
				map[j][i] = '.';
				if (replaced == 0)
				{
					ft_putendl("Hit if; replaced character was first character.");
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
	find_dot(cursor, map, (x + 1), y, piece);
}

int     place_piece(t_piece *head, char **map, int piece)
{
    t_piece     *cursor;
    int         x;
    int         y;
    int         hash;
    int         j;

    y = 0;
    x = 0;
    hash = 0;
    j = 1;
    if (piece == 0) /*Checking for negative x.*/
    {
        ft_putendl("Checking for negatives...");
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
            while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
            ++x;
        }
        if ((head->x[0] + x + 1) > ft_strlen(map[0]) || (head->x[1] + x + 1) > ft_strlen(map[0]) || (head->x[2] + x + 1) > ft_strlen(map[0]) || (head->y[0] + 1) > ft_strlen(map[0]) || (head->y[1] + 1) > ft_strlen(map[0]) || (head->y[2] + 1) > ft_strlen(map[0]))
        {
            /*ft_putnbr(ft_strlen(map[0]));
            ft_putendl("");
            ft_putnbr(head->x[0]);
            ft_putendl("");
            ft_putnbr(head->y[0]);
            ft_putendl("");
            ft_putnbr(head->x[1]);
            ft_putendl("");
            ft_putnbr(head->y[1]);
            ft_putendl("");
            ft_putnbr(head->x[2]);
            ft_putendl("");
            ft_putnbr(head->y[2]);
            ft_putendl("");*/
            ft_putendl("We're going to need a bigger map...");
            return (-1);
        }
        ft_putendl("Placing our first hash.");
        map[y][x] = (65 + piece);
        while (hash < 3)
        {
            ft_putendl("Placing hash...");
            if (map[head->y[hash] + y][head->x[hash] + x] == '.')
            {
                map[head->y[hash] + y][head->x[hash] + x] = 65 + piece;
                ft_putendl("Hash successfully placed.");
                print_map(map);
            }
            else
            {
                ft_putstr("Placement unsuccessful at x = ");
                ft_putnbr(head->x[hash] + x);
                ft_putstr(" and y = ");
                ft_putnbr(head->y[hash] + y);
                ft_putendl(".");
            }
            ++hash;
        }
        ft_putendl("Hashes placed...");
    }
    /* Now we will want to traverse the list and try to place the next piece. */
    if (piece > 0) 
    {
        ft_putstr("Attempting to place piece ");
        ft_putchar(65 + piece);
        ft_putchar('\n');
        cursor = traverse_until(head, piece);
        hash = find_dot(cursor, map, x, y, piece);
        if (hash == 1)
            backtrack(cursor, map, piece);
    }
    return (0);
}