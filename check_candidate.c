#include "fillit.h"

int     check_candidate(t_piece *cursor, char **map, int x, int y, int piece)
{
    ft_putstr("Found first position of new piece at x ");
    ft_putnbr(x);
    ft_putstr(" and y ");
    ft_putnbr(y);
    ft_putendl("");
    if (map[x + cursor->y[0]][x + cursor->x[0]] == '.')
    {
        ft_putendl("Second one clear!");
        if (map[y + (cursor->y[1])][x + (cursor->x[1])] == '.')
        {
            ft_putendl("Third one clear!");
            if (map[y + (cursor->y[2])][x + (cursor->x[2])] == '.')
            {
                ft_putendl("Fourth one clear!");
                map[y][x] = (65 + piece);
                ft_putendl("First one placed!");
                map[y + cursor->y[0]][x + cursor->x[0]] = (65 + piece);
				ft_putendl("Second one placed!");
                map[y + cursor->y[1]][x + cursor->x[1]] = (65 + piece);
                ft_putendl("Third placed!");
                map[y + cursor->y[2]][x + cursor->x[2]] = (65 + piece);
                ft_putendl("HOME RUN!");
				return (0);
            }
        }
    }
    return (-1);
}
