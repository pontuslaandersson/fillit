#include "fillit.h"

int     place_piece(t_piece *head, char **map, int piece)
{
    t_piece     *cursor;
    int         x;
    int         y;
    int         hash;

    y = 0;
    x = 0;
    hash = 0;
    if (piece == 0) /*Checking for negative x.*/
    {
        ft_putendl("Checking for negatives...");
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
            while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
            ++x;
        }
        if (head->x[0] >= ft_strlen(map[0]) || head->x[1] >= ft_strlen(map[0]) || head->x[2] >= ft_strlen(map[0]) || head->y[0] >= ft_strlen(map[0]) || head->y[1] >= ft_strlen(map[0]) || head->y[2] >= ft_strlen(map[0]))
        {
            ft_putnbr(ft_strlen(map[0]));
            ft_putendl("We're going to need a bigger map...");
            return (-1);
        }
        ft_putendl("Attempting to place our first hash...");
        map[y][x] = (65 + piece);
        while (hash < 3)
        {
            ft_putendl("Placing hash...");
            if (map[head->y[hash]][head->x[hash]] == '.')
                map[head->y[hash]][head->x[hash]] = 65 + piece;
            ++hash;
        }
        ft_putendl("Hashes placed...");
    }
    /* Now we will want to traverse the list and try to place the next piece. */
    if (piece > 0) 
    {
        ft_putendl("Attempting to place non-first piece.");
        cursor = traverse_until(head, piece);
        print_list(cursor);
        while (map[y][x] != '.')
        {
            ft_putendl("Entered while...");
            if (map[y][x] >= 'A' && map[y][x] <= 'Y')
            {
                ft_putendl("Incrementing x...");
                ++x;
            }
            if (map[y][x] == '\0')
            {
                ft_putendl("Hit null terminator, going to next line.");
                x = 0;
                ++y;
                if (y > ft_strlen(map[0]))
                    {
                        ft_putendl("y over limit; map needs to get bigger.");
                        exit (-1);
                    }
            }
        }
        if (map[y][x] == '.')
        {
            ft_putendl("Found first position of new piece.");
            if (map[cursor->y[0]][cursor->x[0]] == '.')
                ft_putendl("Second one clear!");
            if (map[y + (cursor->y[1])][x + (cursor->x[1])] == '.')
                ft_putendl("Third one clear!");
            if (map[y + (cursor->y[2])][x + (cursor->x[2])] == '.')
                ft_putendl("Fourth one clear!");
            {
                ft_putendl("Candidate positions clear. Attempting to place letter...");
                map[y][x] = (65 + piece);
                ft_putendl("First one placed!");
                map[y + cursor->y[0]][x + cursor->x[0]] = (65 + piece);
                ft_putendl("Second one placed!");
                map[y + cursor->y[1]][x + cursor->x[1]] = (65 + piece);
                ft_putendl("Third placed!");
                map[y + cursor->y[2]][x + cursor->x[2]] = (65 + piece);
                ft_putendl("HOME RUN!");
            }
            /*else
            {
                ft_putendl("Cannot place piece.");
            }*/
            
            /*else if ((ft_strlen(map[0]) - 2) < (cursor->x[0] || cursor->x[1] || cursor->x[2]))
            {
                ft_putendl("We're going to need a bigger map...");
                exit (-1);
            }*/
        }    
    }
    return (0);
}