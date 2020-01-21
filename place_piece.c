#include "fillit.h"

int     place_piece(t_piece *head, char **map, int placed, int n, int start)
{
    t_piece     *cursor;
    int         x;
    int         y;
    int         hash;
    int         j;

    y = (n / (ft_strlen(map[0])));
    x = (n % (ft_strlen(map[0])));
    ft_putnbr(x);
    ft_putchar('\n');
    ft_putnbr(y);
    hash = 0;
    j = 1;
    if (placed == 0) /*Checking for negative x.*/
    {
        ft_putendl("Checking for negatives...");
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
            while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
            ++x;
        }
        ft_putnbr(head->x[0] + x + 1);

        if ((head->x[0] + x + 1) > ft_strlen(map[0]) || (head->x[1] + x + 1) > ft_strlen(map[0]) || (head->x[2] + x + 1) > ft_strlen(map[0]) || (head->y[0] + y + 1) > ft_strlen(map[0]) || (head->y[1] + y + 1) > ft_strlen(map[0]) || (head->y[2] + y + 1) > ft_strlen(map[0]))
        {
            ft_putendl("We're going to need a bigger map...");
            return (-1);
        }
        ft_putendl("Placing our first hash.");
        map[y][x] = (65 + placed);
        while (hash < 3)
        {
            ft_putendl("Placing hash...");
            if (map[head->y[hash] + y][head->x[hash] + x] == '.')
            {
                map[head->y[hash] + y][head->x[hash] + x] = 65 + placed;
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