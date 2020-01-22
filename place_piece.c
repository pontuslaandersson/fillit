#include "fillit.h"

/* Old place_piece, not part of current build. */

int     place_piece(t_piece *head, char **map, int placed, int n, int start)
{
    t_piece     *cursor;
    int         x;
    int         y;
    int         hash;

    y = (n / (ft_strlen(map[0])));
    x = (n % (ft_strlen(map[0])));
    ft_putnbr(x);
    ft_putchar('\n');
    ft_putnbr(y);
    hash = 0;
    /* Now we will want to traverse the list and try to place the next piece. */
    if (placed > 0) 
    {
        x = 0;
        y = 0;
        ft_putstr("Attempting to place piece ");
        ft_putchar(65 + placed);
        ft_putchar('\n');
        cursor = traverse_until(head, placed);
        ft_putendl("Starting find_dot with x ");
        ft_putnbr(x);
        hash = find_dot(cursor, map, x, y, placed);
        if (hash == 1)
        {
            ft_putendl("Ran out of map while placing pieces.");
            return (-1);
        }
        /*if (hash == -2)
        {
            ft_putendl("Unable to place piece and at end of map.");
            return (-2);
        }*/
        if (hash != 0)
        {
            ft_putstr("Return from find_dot: ");
            ft_putnbr(hash);
            ft_putendl("Unable to place piece.");
            return (-1);
        }
        /*if (hash == 1)
        {
            ft_putendl("Triggered backtracking in place_piece.");
            backtrack(cursor, map, placed);
        }*/
    }
    return (0);
}