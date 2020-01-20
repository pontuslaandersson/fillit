#include "fillit.h"

int     check_candidate(t_piece *cursor, char **map, int x, int y, int placed)
{
    ft_putstr("Found first position of new piece at x ");
    ft_putnbr(x);
    ft_putstr(" and y ");
    ft_putnbr(y);
    ft_putendl("");
    ft_putstr("Strlen: ");
    ft_putnbr(ft_strlen(map[0]));
    ft_putendl("");
    if (y + 1 == ft_strlen(map[0]) && x + 1 == ft_strlen(map[0]))
    {
        ft_putendl("Map overflow detected. Backtracking.");
        backtrack(cursor, map, placed);
    }
    if ((y + (cursor->y[0])) < ft_strlen(map[0]) && (y + (cursor->y[1])) < ft_strlen(map[0]) && (y + (cursor->y[2])) < ft_strlen(map[0]))
    {
        if (map[y + cursor->y[0]][x + cursor->x[0]] == '.')
        {
            ft_putendl("Second one clear!");
            ft_putstr("Y value: ");
            ft_putnbr(y + (cursor->y[0]));
            ft_putendl("");
            ft_putnbr(ft_strlen(map[0]));
            ft_putendl("");
            if (map[y + (cursor->y[1])][x + (cursor->x[1])] == '.')
            {
                ft_putendl("Third one clear!");
                ft_putstr("Y value: ");
                ft_putnbr(y + (cursor->y[1]));
                ft_putendl("");
                ft_putnbr(ft_strlen(map[0]));
                ft_putendl("");
                if (map[y + (cursor->y[2])][x + (cursor->x[2])] == '.')
                {
                    ft_putendl("Fourth one clear!");
                    ft_putstr("Y value: ");
                    ft_putnbr(y + (cursor->y[2]));
                    ft_putendl("");
                    ft_putnbr(ft_strlen(map[0]));
                    ft_putendl("");
                    map[y][x] = (65 + placed);
                    ft_putendl("First one placed!");
                    map[y + cursor->y[0]][x + cursor->x[0]] = (65 + placed);
			    	ft_putendl("Second one placed!");
                    map[y + cursor->y[1]][x + cursor->x[1]] = (65 + placed);
                    ft_putendl("Third placed!");
                    map[y + cursor->y[2]][x + cursor->x[2]] = (65 + placed);
                    ft_putendl("HOME RUN!");
                    ft_putstr("Placed piece ");
                    ft_putchar(65 + placed);
                    ft_putchar('\n');
			    	return (0);
                }
            }
        }
    }
    return (-1);
}
