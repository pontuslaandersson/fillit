#include "fillit.h"

int     place_piece(t_piece *head, char **map, int piece)
{
    t_piece *cursor;
    int     x;
    int     y;
    int     hash;

    y = 0;
    x = 0;
    hash = 0;
    ft_putendl("Checking for negatives...");
    if (piece == 0) /*Checking for negative x.*/
    {
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
            while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
            ++x;
        }
        if (/*head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0 || */(ft_strlen(map[0]) - 2) < (head->x[0] || head->x[1] || head->x[2]) || (ft_strlen(map[0]) - 2) < (head->y[0] || head->y[1] || head->y[2]))
        {
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
    /*if (piece > 0) Now we will want to traverse the list and try to place the next piece.
    {
        cursor = traverse_until(head, piece);
        if ((ft_strlen(map[0]) - 1) < (cursor->x[0] || cursor->x[1] || cursor->x[2]))
        {
            ft_putendl("We're going to need a bigger map...");
            exit (-1);
        }
        ft_putendl("Attempting to place our first hash...");
        if (map[x][y] == '.')
            map[y][x] = '#';
        x = 0;
        while (x < 3)
        {
            ft_putendl("Placing hash...");
            if (map[cursor->y[x]][cursor->x[x]] == '.')
                map[cursor->y[x]][cursor->x[x]] = '#';
            ++x;
        }
        ft_putendl("Hashes placed...");
    }*/
    return (0);
}