#include "fillit.h"

int     place_piece(t_piece head, char **map, int placed)
{
    int     piece;
    t_piece *cursor;
    int     x;
    int     y;

    y = 0;
    x = 0;
    piece = 0;
    if (piece == 0) /*Checking for negative x.*/
    {
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
            while (((head->x[0] + x) < 0 || (head->x[1] + x) < 0 || (head->x[2] + x) < 0) && map[y][x] != '\0'/*there's enough map*/)
            ++x;
        }
        if (head->x[0] < 0 || head->x[1] < 0 || head->x[2] < 0)
        {
        /*We're going to need a bigger map*/
        }
        map[y][x] = '#'; 
        while (x < 3)
        {
            if (map[head->y[y]][head->x[x]] = '.')
                map[head->y[x]][head->x[x]] = '#';
            ++x;
            ++y;
        }
    }
}